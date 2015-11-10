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


bool ScriptWriter::writeData(QString outdir, std::vector<tool::MapData> data,
               std::vector<tool::TractData> tracts){
    // issue: window path may not take slash
    QFile file(outdir + "/" +pipeline_script);

    // override without warning if file exists
    if(file.open(QIODevice::WriteOnly)){
        file.write("#! /usr/bin/env python\n");
        file.write("# -*- coding: utf-8 -*-\n\n");
        file.write("import sys\n\n");

        // global declaration
        file.write("# global declaration \n");
        file.write("out_dir = \"\"\n\n");
        file.write("# procedure run for each case\n");
        file.write("def run_process(sid,dti_path,def_path,fiber_path):\n");
        file.write("\tpass\n\n");
        file.write("# this function contains all the run_process calls\n");
        file.write("def run():\n");
        for(std::vector<tool::MapData>::iterator it1 = data.begin(); it1 != data.end(); ++it1 ){
            for(std::vector<tool::TractData>::iterator it2 = tracts.begin(); it2 != tracts.end(); ++it2){
                char buffer[1024];
                std::sprintf(buffer,"\trun_process('%s','%s','%s','%s')\n",
                             it1->subjectID.toStdString().c_str(),it1->t12_path.toStdString().c_str(),
                             it1->def_path.toStdString().c_str(), it2->file_path.toStdString().c_str());
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
