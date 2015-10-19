#include "include/tfatool.h"
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

       // select files with vtk prefix
       string filepath = string(dirp->d_name);
       size_t found = filepath.find_last_of(".");
       string prefix = filepath.substr(found+1);
       if (prefix == "vtk"){
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

bool tool::checkNewLine(string &s){
    string::iterator i = s.end()-1;
    if(*i == '\n'){
        s.erase(i,i+1);
        return true;
    }else
        return false;
}

bool tool::checkDirExist(string path){
    struct stat info;
    if(stat(path.c_str(),&info)!=0)
        return false;
    else if(info.st_mode & S_IFDIR)
        return true;
    else
        return false;
}

string tool::syscall(const char* cmd){
    FILE* pipe = popen(cmd,"r");
    if(!pipe) return NULL;
    char buffer[256];
    string result = "";
    while(!feof(pipe)){
        if(fgets(buffer,256,pipe)){
            result += buffer;
        }
    }
    pclose(pipe);
    return result;
}


void tool::tokenize(char* str, const char* delimiter, vector<string> &results){
    results.clear();
    char* tok = strtok(str,delimiter);
    while(tok!= NULL){
        results.push_back(string(tok));
        tok = strtok(NULL,delimiter);
    }
}

void tool::parseMapContent(string filename, map<string,TractData> &data, string header1, string header2){

    char* path;
    char* sid;
    if(header1==header2){
        io::CSVReader<1> in(filename);
        in.read_header(io::ignore_extra_column,header1);
        while(in.read_row(sid)){
            tool::TractData newTract = {
                QString::fromStdString(sid),
                QString::fromStdString(sid)
            };
            auto element = std::make_pair(sid,newTract);
            data.insert(element);
        }
    }else{
        io::CSVReader<2> in(filename);
        in.read_header(io::ignore_extra_column,header1,header2);
        while(in.read_row(path,sid)){
            if(header1 == header2)
                sid = path;
            tool::TractData newTract = {
                QString::fromStdString(path),
                QString::fromStdString(sid)
            };
            auto element = std::make_pair(sid,newTract);
            data.insert(element);
        }
    }

}

bool tool::checkExecutable(char *path){
    struct stat sb;
    if(stat(path,&sb)==0 && sb.st_mode & S_IXUSR)
        return true;
    else
        return false;
}

bool tool::checkExecutable(string path){
    const char* tmp = path.c_str();
    char* result = new char[path.length()-1];
    strcpy(result,tmp);
    bool y = checkExecutable(result);
    delete[] result;
    return y;
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
