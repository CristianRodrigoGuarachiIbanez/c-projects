#include <string>
#include <string.h>
#include <iostream>
#include <filesystem>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>


//#include "boost/filesystem.hpp"
//using namespace std;
//namespace fs = std::filesystem;
using namespace std;
// int main(){
    
//     char command[10] = "ls -la";
//     for(int i = 0; i<10; i++){
//         cout << "index :" << i << "value :" << command[i] << endl;
//     }
//     system(command);
// };

class DirectoryManager{
    public: 
    DIR *dir;
    string listDir;
    struct dirent *Entry;
    DirectoryManager(string path){
        dir = opendir(path.c_str()); // convert to string 
        listDir = list_dir(path);
        cout<<listDir<<endl;
    }
    string list_dir(string path){
        
        if(dir == NULL){
            cout << "directory : "<<strerror(errno) << endl;
            return "the directory list is empty";
        }
        recover_content(path);
        close();
        return "it was successfully recovered";
    }

    private:
    string checkPathString(string strPath){
        if(strPath[strPath.length()-1] == '/'){
            strPath = strPath.substr(0, strPath.length()-1);
        }
        return strPath;
    }
    
    void recover_content(string path){
        int i = 0;
        while ((Entry = readdir(dir)) != NULL)
        {
            /* code */
            string strPath = "";
            if(strcmp(Entry->d_name, ".") ==0 || strcmp(Entry->d_name, "..")==0) continue;
            if(Entry->d_type == DT_DIR){
                path = checkPathString(path);
                strPath = path + "/" + Entry->d_name;
                recover_content(path);
            }
            else{
                path = checkPathString(path);
                strPath = path + "/" + Entry->d_name;
                cout<<"index:" << " "<<i<<" " << "path: "<< strPath <<endl;
            }

            cout << "index: " << i <<" "<< "file:" << Entry->d_name << endl;
            i++;
        }
    }
    void close(){
        closedir(dir);
    }    

};

int main(){

    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL){
        cout<<cwd<<endl;
    }
    string path = cwd; //"/home/cristian/c++Project/useArrays";
    DirectoryManager directory(path);
    //string files = directory.list_dir();
};
