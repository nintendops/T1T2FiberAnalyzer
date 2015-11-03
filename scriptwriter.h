#ifndef SCRIPTWRITER_H
#define SCRIPTWRITER_H

#include <QFile>
#include <QFileInfo>
#include <QString>
#include <include/tfatool.h>
#include <include/errorreporter.h>


// class used for writing python script
// used singleton pattern
class ScriptWriter
{
public:
    static ScriptWriter *getInstance(QString tool, QString pipeline);
    void writePreliminary();
    bool writeData(QString outdir, std::vector<tool::MapData> data,
                   std::vector<tool::TractData> tracts);
    QString getToolScriptName();
    QString getPipelineScriptName();
    void close();

private:
    ScriptWriter(QString tool, QString pipeline);
    QString tool_script;
    QString pipeline_script;
    bool hasTool;
    static ScriptWriter *writer;
};

#endif // SCRIPTWRITER_H
