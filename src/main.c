#include<stdbool.h> // bool
#include<stddef.h> // size_t
#include<ctype.h> // isalnum isdigit
#include<stdio.h> // printf fopen FILE fclose fprintf
#include<string.h> // strlen
#include"filesystem.h" // filesystem_createDir
#include"memory.h" // memory_free
#include"string_concat.h" // string_concat
extern bool checkProjectName(char const* project_name);
extern bool fileExist(char const* file_path);
// argv[1]:project name
int main(int argc,char* argv[]){
    if(argc!=2){
        printf("please input project name!\n");
        return -1;
    }
    char* project_name=argv[1];
    if(!checkProjectName(project_name)){
        printf("project name error!\n");
        return -2;
    }
    filesystem_createDir(project_name);

    char* project_build_path=string_concat(project_name,"/build");
    filesystem_createDir(project_build_path);
    memory_free(project_build_path);
    project_build_path=NULL;

    char* project_src_path=string_concat(project_name,"/src");
    filesystem_createDir(project_src_path);
    memory_free(project_src_path);
    project_src_path=NULL;

    char* project_include_path=string_concat(project_name,"/include");
    filesystem_createDir(project_include_path);
    memory_free(project_include_path);
    project_include_path=NULL;

    char* project_cmakelists_path=string_concat(project_name,"/CMakeLists.txt");
    if(!fileExist(project_cmakelists_path)){
        FILE* stream=fopen(project_cmakelists_path,"w");
        if(stream==NULL){
            printf("create CMakeLists.txt error!\n");
            memory_free(project_cmakelists_path);
            project_cmakelists_path=NULL;
            return -3;
        }
        fprintf(stream,"cmake_minimum_required(VERSION 3.15)\n");
        fprintf(stream,"project(%s VERSION 0.0.1 LANGUAGES C)\n",project_name);
        fprintf(stream,"set(CMAKE_C_STANDARD 11)\n");
        fprintf(stream,"aux_source_directory(src SRC_DIR)\n");
        fprintf(stream,"include_directories(include)\n");
        fprintf(stream,"add_executable(${PROJECT_NAME} ${SRC_DIR})\n");
        fclose(stream);
    }
    memory_free(project_cmakelists_path);
    project_cmakelists_path=NULL;
    return 0;
}
bool checkProjectName(char const* project_name){
    if(project_name==NULL||project_name[0]=='\0'||isdigit(project_name[0])){
        return false;
    }
    size_t len=strlen(project_name);
    for(size_t index=0;index<len;++index){
        if(!(isalnum(project_name[index])||project_name[index]=='_')){
            return false;
        }
    }
    return true;
}
bool fileExist(char const* file_path){
    FILE* stream=fopen(file_path,"r");
    if(stream==NULL){
        return false;
    }
    fclose(stream);
    return true;
}
