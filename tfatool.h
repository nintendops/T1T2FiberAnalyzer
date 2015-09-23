#ifndef TFATOOL_H
#define TFATOOL_H

#include <QString>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include "stdio.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace tool{

     struct TractData{
        QString csv_path;
        QString subjectID;
    };

     int getnrrdfiles (string dir, vector<tool::TractData> &files);
     void tokenize(char* str, char* delimiter, vector<string> &results);
     vector<vector<string>>  parseCSV(string dir, vector<string> &attrs);

}



#endif // TFATOOL_H
