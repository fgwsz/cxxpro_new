#include<iostream>
#include<filesystem>
#include<fstream>
#include<string>
static bool __checkProjectName(::std::string const& project_name){
    if(project_name.empty()||::std::isdigit(project_name.at(0))){
        return false;
    }
    ::std::size_t len=project_name.size();
    for(auto const& element:project_name){
        if(!(::std::isalnum(element)||element=='_')){
            return false;
        }
    }
    return true;
}
static bool __fileExist(::std::filesystem::path const& file_path){
    return ::std::ifstream(file_path).is_open();
}
static bool __dirExist(::std::filesystem::path const& dir_path){
    return ::std::filesystem::exists(dir_path)&&::std::filesystem::is_directory(dir_path);
}
static void __makeDir(::std::filesystem::path const& dir_path){
    if(!__dirExist(dir_path)){
        ::std::filesystem::create_directories(dir_path);
    }
}
int main(int argc,char* argv[]){
    ::std::cout<<"this program will create the following file structure:\n"
        <<"./${project_name}/\n"
        <<"    |--include/\n"
        <<"        |--main.h\n"
        <<"    |--src/\n"
        <<"        |--main.cpp\n"
        <<"    |--CMakeLists.txt\n"
        <<"    |--mingw_build.ps1\n"
        <<"    |--msvc_build.ps1\n"
        <<"    |--README.md\n"
        <<"    |--git_push.ps1\n";
    if(argc==1){
        ::std::cout<<"please input project name!\n";
        return -1;
    }
    if(argc>2){
        ::std::cout<<"too many input parameters!\n";
        return -2;
    }
    ::std::string project_name=argv[1];
    if(!__checkProjectName(project_name)){
        ::std::cout<<"project name error!\n";
        ::std::cout<<"project name can only use letters and numbers and underscores.\n";
        return -3;
    }
    ::std::filesystem::path project_path(project_name);
    __makeDir(project_path);
    __makeDir(project_path/"include");
    auto main_h=project_path/"include"/"main.h";
    if(!__fileExist(main_h)){
        ::std::ofstream ofs(main_h);
        if(!ofs.is_open()){
            ::std::cout<<"open main.h error!\n";
            return -4;
        }
        ofs<<"#pragma once\n"
           <<"#include<iostream>\n";
    }
    __makeDir(project_path/"src");
    auto main_cpp=project_path/"src"/"main.cpp";
    if(!__fileExist(main_cpp)){
        ::std::ofstream ofs(main_cpp);
        if(!ofs.is_open()){
            ::std::cout<<"open main.cpp error!\n";
            return -5;
        }
        ofs<<"#include\"main.h\"\n"
           <<"int main(int argc,char* argv[]){\n"
           <<"    ::std::cout<<\"hello "<<project_name<<"!\\n\";\n"
           <<"    return 0;\n"
           <<"}\n";
    }
    auto cmakelists_txt=project_path/"CMakeLists.txt";
    if(!__fileExist(cmakelists_txt)){
        ::std::ofstream ofs(cmakelists_txt);
        if(!ofs.is_open()){
            ::std::cout<<"open CMakeLists.txt error!\n";
            return -6;
        }
        ofs<<"cmake_minimum_required(VERSION 3.15)\n"
           <<"project("<<project_name<<" VERSION 0.0.1 LANGUAGES CXX)\n"
           <<"set(CMAKE_CXX_STANDARD 20)\n"
           <<"aux_source_directory(src SRC_DIR)\n"
           <<"include_directories(include)\n"
           <<"add_executable(${PROJECT_NAME} ${SRC_DIR})\n";
    }
    auto mingw_build_ps1=project_path/"mingw_build.ps1";
    if(!__fileExist(mingw_build_ps1)){
        ::std::ofstream ofs(mingw_build_ps1);
        if(!ofs.is_open()){
            ::std::cout<<"open mingw_build.ps1 error!\n";
            return -7;
        }
        ofs<<"if(Test-Path -Path mingw_build){}else{\n"
           <<"    mkdir mingw_build\n"
           <<"}\n"
           <<"cd mingw_build\n"
           <<"cmake -G\"MinGW Makefiles\" ..\n"
           <<"cmake --build .\n"
           <<"cd ..\n"
           <<"cp mingw_build/"<<project_name<<".exe "<<project_name<<".exe\n"
           <<"./"<<project_name<<".exe\n";
    }
    auto msvc_build_ps1=project_path/"msvc_build.ps1";
    if(!__fileExist(msvc_build_ps1)){
        ::std::ofstream ofs(msvc_build_ps1);
        if(!ofs.is_open()){
            ::std::cout<<"open msvc_build.ps1 error!\n";
            return -8;
        }
        ofs<<"if(Test-Path -Path msvc_build){}else{\n"
           <<"    mkdir msvc_build\n"
           <<"}\n"
           <<"cd msvc_build\n"
           <<"cmake -G\"Visual Studio 17 2022\" ..\n"
           <<"cmake --build .\n"
           <<"cd ..\n"
           <<"cp msvc_build/Debug/"<<project_name<<".exe "<<project_name<<".exe\n"
           <<"./"<<project_name<<".exe\n";
    }
    auto readme_md=project_path/"README.md";
    if(!__fileExist(readme_md)){
        ::std::ofstream ofs(readme_md);
        if(!ofs.is_open()){
            ::std::cout<<"open README.md error!\n";
            return -9;
        }
        ofs<<"# "<<project_name<<"\n";
    }
    auto git_push_ps1=project_path/"git_push.ps1";
    if(!__fileExist(git_push_ps1)){
        ::std::ofstream ofs(git_push_ps1);
        if(!ofs.is_open()){
            ::std::cout<<"open git_push.ps1 error!\n";
            return -10;
        }
        ofs<<"echo \"you can input exit to abort git push.\"\n"
           <<"$commit_info=Read-Host -Prompt \"input commit info\"\n"
           <<"if($commit_info -eq \"exit\"){\n"
           <<"    echo \"git push exit!\"\n"
           <<"}else{\n"
           <<"    git add include/*\n"
           <<"    git add src/*\n"
           <<"    git add CMakeLists.txt\n"
           <<"    git add mingw_build.ps1\n"
           <<"    git add msvc_build.ps1\n"
           <<"    git add README.md\n"
           <<"    git add git_push.ps1\n"
           <<"    git commit -m $commit_info\n"
           <<"    git push\n"
           <<"}\n";
    }
    ::std::cout<<"created successfully!\n";
    return 0;
}
