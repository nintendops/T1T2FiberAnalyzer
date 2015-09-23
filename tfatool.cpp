#include "tfatool.h"
#include "Resources/csv.h"
#include <cstddef>
using namespace tool;

int tool::getnrrdfiles (string dir, vector<tool::TractData> &files){
   DIR *dp;
   struct dirent *dirp;
   if((dp  = opendir(dir.c_str())) == NULL) {
         //cout << "Error(" << errno << ") opening " << dir << endl;
         return errno;
   }

   while((dirp = readdir(dp)) != NULL){

       // select files with nrrd prefix
       string filepath = string(dirp->d_name);
       size_t found = filepath.find_last_of(".");
       string prefix = filepath.substr(found+1);
       if (prefix == "nrrd"){
           size_t found_name = filepath.find_last_of("/");
           string filename = filepath.substr(found_name+1);
           tool::TractData newTract = {
               QString::fromStdString(filename),  // file name
               QString("UniTract")  //subject ID
           };
           files.push_back(newTract);
       }

   }
   closedir(dp);
   return 0;

}


void tool::tokenize(char* str, char* delimiter, vector<string> &results){
    results.clear();
    char* tok = strtok(str,delimiter);
    while(tok!= NULL){
        results.push_back(string(tok));
        tok = strtok(NULL,delimiter);
    }
}


// generic parsing of csv files
vector<vector<string>> tool::parseCSV(string dir, vector<string> &attrs){
    io::LineReader scanner(dir);
    attrs.clear();
    // header line
    char* header = scanner.next_line();
    tokenize(header,",",attrs);
    int colnum = attrs.size();

    vector<vector<string>> results;
    while (char* line = scanner.next_line()){
        vector<string> new_arr;
        tokenize(line,",",new_arr);
        results.push_back(new_arr);
    }
    return results;
}

