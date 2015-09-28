#ifndef TFATOOL_H
#define TFATOOL_H
#include <QString>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cctype>
#include <locale>
#include <utility>


using namespace std;

namespace tool{

     struct TractData{
        QString csv_path;
        QString subjectID;
    };
     struct MapData{
         QString t12_path;
         QString def_path;
         QString subjectID;
         QString mapID;
     };

     int getnrrdfiles (string dir, vector<tool::TractData> &files);
     void tokenize(char* str, char* delimiter, vector<string> &results);
     void parseMapContent(string filename, map<string,TractData> &data, string header1, string header2);
     vector<vector<string>>  parseCSV(string dir, vector<string> &attrs);
     string syscall(const char* cmd);

     // trim from start
     inline std::string &ltrim(std::string &s) {
             s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
             return s;
     }

     // trim from end
     inline std::string &rtrim(std::string &s) {
             s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
             return s;
     }

     // trim from both ends
     inline std::string &trim(std::string &s) {
             return ltrim(rtrim(s));
     }

}



#endif // TFATOOL_H
