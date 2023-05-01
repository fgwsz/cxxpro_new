#include<stdbool.h> // bool
#include<stddef.h> // size_t
#include<ctype.h> // isalnum isdigit
#include<stdio.h> // printf fopen FILE fclose fprintf
#include<string.h> // strlen memset
#include<stdlib.h> // malloc free
extern bool checkProjectName(char const* project_name);
extern bool fileExist(char const* file_path);
extern void makeDir(char const* dir_path);
extern char* stringConcat(char const* str1,char const* str2);
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
    makeDir(project_name);

    char* project_build_path=stringConcat(project_name,"/build");
    makeDir(project_build_path);
    free(project_build_path);
    project_build_path=NULL;

    char* project_src_path=stringConcat(project_name,"/src");
    makeDir(project_src_path);
    free(project_src_path);
    project_src_path=NULL;

    char* project_include_path=stringConcat(project_name,"/include");
    makeDir(project_include_path);
    free(project_include_path);
    project_include_path=NULL;

    char* project_cmakelists_path=stringConcat(project_name,"/CMakeLists.txt");
    if(!fileExist(project_cmakelists_path)){
        FILE* stream=fopen(project_cmakelists_path,"w");
        if(stream==NULL){
            printf("create CMakeLists.txt error!\n");
            free(project_cmakelists_path);
            project_cmakelists_path=NULL;
            return -3;
        }
        fprintf(stream,"cmake_minimum_required(VERSION 3.15)\n");
        fprintf(stream,"project(%s VERSION 0.0.1 LANGUAGES C CXX)\n",project_name);
        fprintf(stream,"set(CMAKE_C_STANDARD 11)\n");
        fprintf(stream,"aux_source_directory(src SRC_DIR)\n");
        fprintf(stream,"include_directories(include)\n");
        fprintf(stream,"add_executable(${PROJECT_NAME} ${SRC_DIR})\n");
        fclose(stream);
    }
    free(project_cmakelists_path);
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
#if defined(WIN32) || defined(_WIN32) || defined(_WIN32_) || defined(WIN64) || defined(_WIN64) || defined(_WIN64_)
#include<direct.h> // mkdir
#include<io.h> // _access
static bool __pathExist(char const* path){
    return (bool)(_access(path,0)!=-1);
}
void makeDir(char const* dir_path){
    if(!__pathExist(dir_path)){
        mkdir(dir_path);
    }
}
#elif defined(__linux__)
#include<unistd.h> // access F_OK
// mkdir
#include <sys/stat.h>
#include <sys/types.h>
static bool __pathExist(char const* path){
    return (bool)(access(path,F_OK)==0);
}
void makeDir(char const* dir_path){
    if(!__pathExist(dir_path)){
        mkdir(dir_path,S_IRWXU);
    }
}
#endif
static size_t __stringLength(char const* str){
    if(str==NULL){
        return 0;
    }
    return strlen(str);
}
static void __stringConcat(char* str_this,char const* str_append){
    if(__stringLength(str_append)==0){
        return;
    }
    strcat(str_this,str_append);
}
static void* memoryAlloc(size_t byte_size){
    void* ret=NULL;
    while(1){
        ret=malloc(byte_size);
        if(ret!=NULL){
            memset(ret,0,byte_size);
            return ret;
        }
        free(ret);
        ret=NULL;
    }
}
char* stringConcat(char const* str1,char const* str2){
    size_t ret_byte_size=sizeof(char)*(__stringLength(str1)+__stringLength(str2)+1);
    char* ret=(char*)memoryAlloc(ret_byte_size);
    __stringConcat(ret,str1);
    __stringConcat(ret,str2);
    return ret;
}
