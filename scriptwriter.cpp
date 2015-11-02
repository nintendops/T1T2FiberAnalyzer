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


void ScriptWriter::writeData(){

}

QString ScriptWriter::getToolScriptName(){
    return tool_script;
}

QString ScriptWriter::getPipelineScriptName(){
    return pipeline_script;
}

void ScriptWriter::close(){

}
