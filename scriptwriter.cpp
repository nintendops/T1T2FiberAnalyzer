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
bool ScriptWriter::writeData(QString outdir, QString fiber_dir, QString fiber_process, QString scalar_name, std::vector<tool::MapData> data,
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
        file.write("import subprocess\n\n");

        // global declaration
        file.write("# global declaration \n");
        char out[18+outdir.size()];
        snprintf(out,sizeof out, "out_dir = \"%s\"\n",outdir.toStdString().c_str());
        file.write(out);
        char fout[24+ outdir.size()];
        snprintf(fout,sizeof fout, "fiber_dir = \"%s\"\n",fiber_dir.toStdString().c_str());
        char fiberprocess[36+ fiber_process.size()];
        snprintf(fiberprocess,sizeof fiberprocess, "fiberprocess_path = \"%s\"\n",fiber_process.toStdString().c_str());
        file.write(fout);
        file.write(fiberprocess);
        file.write("# procedure run for each case\n");
        file.write("def run_process(sid,scalar_path,def_path,fiber_path,scalarName='scalar'):\n");
        file.write("\tsubprocess.check_call([fiberprocess_path,'-n',"
                   "'--inputFiberBundle '+fiber_dir+'/'+fiber_path,"
                   "'-o '+out_dir+'/'+fiber_path,"
                   "'-S '+scalar_path, '-D '+ def_path, '--scalarName '+scalarName])\n\n");
        file.write("# this function contains all the run_process calls\n");
        file.write("def run():\n");
        for(std::vector<tool::MapData>::iterator it1 = data.begin(); it1 != data.end(); ++it1 )
        {
            for(std::vector<tool::TractData>::iterator it2 = tracts.begin(); it2 != tracts.end(); ++it2)
            {
                char buffer[1024];
                if(scalar_name != "")
                {
                    std::snprintf(buffer,1024,"\trun_process('%s','%s','%s','%s','%s')\n",
                                  it1->subjectID.toStdString().c_str(),it1->t12_path.toStdString().c_str(),
                                  it1->def_path.toStdString().c_str(), it2->file_path.toStdString().c_str(),
                                  scalar_name.toStdString().c_str());
                }else
                {
                    std::snprintf(buffer,1024,"\trun_process('%s','%s','%s','%s')\n",
                                  it1->subjectID.toStdString().c_str(),it1->t12_path.toStdString().c_str(),
                                  it1->def_path.toStdString().c_str(), it2->file_path.toStdString().c_str());

                }
                file.write(buffer);
            }
        }

        file.write("\n\nif __name__ == '__main__':\n");
        file.write("\trun()");
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
