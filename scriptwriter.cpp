#include "scriptwriter.h"

ScriptWriter* ScriptWriter::writer = NULL;

ScriptWriter* ScriptWriter::getInstance(QString tool, QString pipeline){
    if(!writer)
        writer = new ScriptWriter(tool, pipeline);
    return writer;
}

// to-do: enforce pathname to end with .py
ScriptWriter::ScriptWriter(QString tool,QString pipeline){
    tool_script = tool;
    pipeline_script = pipeline;
    hasTool = false;
}


void ScriptWriter::writePreliminary(){

    QFile file(tool_script);
    if(file.exists()){
        // shall we do something?
        //ErrorReporter::fire("Overwriting file " + tool_script.toStdString());
    }
    if(file.open(QIODevice::WriteOnly)){
        // obtaining lock of file
        file.write("#! /usr/bin/env python\n");
        file.write("# -*- coding: utf-8 -*-\n\n");
        file.write("import sys\n");
        file.write("if sys.version_info<(2,5):\n");
        file.write("\tprint(\"false\")\n");
        file.write("else:\n");
        file.write("\tprint(\"true\")\n");
        file.close();

    }else{
        // to-do: open failed. Should throw an error
        ErrorReporter::fire("Failed to open file " + tool_script.toStdString() + " for script generation.");
    }


}

// issue: special characters are not escaped
bool ScriptWriter::writeData(QString outdir, QString fiber_dir, QString fiber_process, QString dtistat, bool isHField, QString scalar_name, std::vector<tool::MapData> data,
               std::vector<tool::TractData> tracts)
{
    // issue: path may not take slash in Window system
    QFile file(outdir + "/" +pipeline_script);

    // override without warning if file exists
    if(file.open(QIODevice::WriteOnly))
    {
        file.write("#! /usr/bin/env python\n");
        file.write("# -*- coding: utf-8 -*-\n\n");
        file.write("import sys\n");
        file.write("import subprocess\n");
        file.write("import string\n");
	file.write("import os\n");
	file.write("import csv\n");
	file.write("import time\n\n");

        // global declaration
        file.write("# global declaration \n");
        char out[18+outdir.size()];
        snprintf(out,sizeof out, "out_dir = \"%s\"\n",outdir.toStdString().c_str());
        file.write(out);
        char fout[24+ outdir.size()];
        snprintf(fout,sizeof fout, "fiber_dir = \"%s\"\n",fiber_dir.toStdString().c_str());
        char fiberprocess[36+ fiber_process.size()];
        snprintf(fiberprocess,sizeof fiberprocess, "fiberprocess_path = \"%s\"\n",fiber_process.toStdString().c_str());
        char dtistatout[36 + dtistat.size()];
        snprintf(dtistatout,sizeof dtistatout, "dti_stat_path= \"%s\"\n", dtistat.toStdString().c_str());

        file.write(fout);
        file.write(fiberprocess);
        file.write(dtistatout);
	file.write("fvp_results=[]\n\n");

        file.write("# procedure run for each case\n");
		
        file.write("def run_process(sid,scalar_path,def_path,fiber_path,isHField,scalarName='scalar'):\n");
	file.write("\tfibername=string.rsplit(fiber_path,'.vtk',1)[0]\n");
	file.write("\tif not os.path.exists(out_dir+'/'+sid):\n");
	file.write("\t\tos.makedirs(out_dir+'/'+sid)\n");
	file.write("\tif not os.path.exists(out_dir+'/'+sid+'/'+fibername):\n");
	file.write("\t\tos.makedirs(out_dir+'/'+sid+'/'+fibername)\n");	
	file.write("\toutput_dir = out_dir+'/'+sid+'/'+fibername\n");	
        file.write("\toutput_fiber = output_dir + '/' + sid + '_' + fiber_path\n");
        file.write("\toutput_fvp = string.rsplit(output_fiber,'.vtk',1)[0]+'.fvp'\n");
	file.write("\tif isHField:\n");
        file.write("\t\tcommand = fiberprocess_path + ' -n' + ' --inputFiberBundle '"
           " + fiber_dir+'/'+fiber_path + ' -o '+ output_fiber + ' -S ' + scalar_path "
           " + ' -H ' + def_path + ' --scalarName '+scalarName\n");
	file.write("\telse:\n");
        file.write("\t\tcommand = fiberprocess_path + ' -n' + ' --inputFiberBundle '"
           " + fiber_dir+'/'+fiber_path + ' -o '+ output_fiber + ' -S ' + scalar_path "
           " + ' -D ' + def_path + ' --scalarName '+scalarName\n");
	
        file.write("\ti1 = subprocess.check_call(command,shell=True)\n");
        file.write("\tcommand_stat = dti_stat_path + ' --scalarName ' + scalarName + "
                   "' --parameter_list ' + scalarName + ' -o ' + output_fvp + ' -i ' + output_fiber\n");
        file.write("\ti2 = subprocess.check_call(command_stat,shell=True)\n");
	file.write("\t#store fvp information\n");
	file.write("\tif i2==0 :\n");
	file.write("\t\tfvp_results.append((output_fvp,fibername,sid))\n");

        file.write("\treturn i1 + i2 \n\n");
	
	file.write("#this function contains the procedure to write the final csv\n");
	file.write("def writeCSV():\n");
	file.write("\tt = time.strftime('%c').replace(' ','-')\n");
	file.write("\tresult = out_dir + '/' + 'Result_' + t + '.csv'\n");
	file.write("\twith open(result,'w') as csvf:\n");
	file.write("\t\tcsvw = csv.writer(csvf)\n");
	file.write("\t\t# write csv headers\n");
	file.write("\t\tcsvw.writerow(['Case','Fiber','Arc Length','Parameter Value'])\n");
	file.write("\t\tfor fvp in fvp_results:\n");
	file.write("\t\t\tf = open(fvp[0],'r')\n");
	file.write("\t\t\t#omitting the first five lines, including headers\n");
	file.write("\t\t\tfor i in range(0,5):\n");
	file.write("\t\t\t\tf.readline()\n");
	file.write("\t\t\tfor line in f:\n");
	file.write("\t\t\t\tparameters = line.rstrip().split(',')\n");
	file.write("\t\t\t\t# taking arc length and parameter value\n");
	file.write("\t\t\t\tout_param = [fvp[2],fvp[1],parameters[0],parameters[2]]\n");
	file.write("\t\t\t\tcsvw.writerow(out_param)\n");
	file.write("\t\t\tf.close()\n\n");

        file.write("# this function contains all the run_process calls\n");
        file.write("def run():\n");
        file.write("\tcode = 0\n");
        for(std::vector<tool::MapData>::iterator it1 = data.begin(); it1 != data.end(); ++it1 )
        {
            for(std::vector<tool::TractData>::iterator it2 = tracts.begin(); it2 != tracts.end(); ++it2)
            {
                char* HF;

                if (isHField)
                    HF = "True";
                else
                    HF = "False";

                char buffer[1024];
                if(scalar_name != "")
                {
                    std::snprintf(buffer,1024,"\tcode += run_process('%s','%s','%s','%s',%s,'%s')\n",
                                  it1->subjectID.toStdString().c_str(),it1->t12_path.toStdString().c_str(),
                                  it1->def_path.toStdString().c_str(), it2->file_path.toStdString().c_str(), HF,
                                  scalar_name.toStdString().c_str());
                }else
                {
                    std::snprintf(buffer,1024,"\tcode += run_process('%s','%s','%s','%s', %s)\n",
                                  it1->subjectID.toStdString().c_str(),it1->t12_path.toStdString().c_str(),
                                  it1->def_path.toStdString().c_str(), it2->file_path.toStdString().c_str(),HF);

                }
                file.write(buffer);
            }
        }
	file.write("\twriteCSV()\n");
        file.write("\treturn code\n");

        file.write("\nif __name__ == '__main__':\n");
        file.write("\tcode = run()\n");
        file.write("\tif code == 0:\n");
        file.write("\t\tprint(\"Fiber output is successfully generated! Return code = \" + str(code))\n");
        file.write("\telse:\n");
        file.write("\t\tprint('Failed to run command. Return code =' + str(code))\n");
        file.close();
        ErrorReporter::friendly_fire("Successfully generated script to " + outdir.toStdString() + "/" +pipeline_script.toStdString());
        return true;
    }else
        return false;

}


QString ScriptWriter::getToolScriptName(){
    return tool_script;
}

QString ScriptWriter::getPipelineScriptName(){
    return pipeline_script;
}

void ScriptWriter::close(){

}
