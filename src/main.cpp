#include"main.hpp"
int main(int argc,char* argv[]){
    if(argc==1){
        ::std::cerr<<"Please input project name!\n";
        return -1;
    }
    if(argc>2){
        ::std::cerr<<"Input too many arguments!\n";
        return -2;
    }
    ::std::string const project_name={argv[1]};
    if(!::check_project_name(project_name)){
        ::std::cerr<<"Project name input error!\n";
        return -3;
    }
    ::std::filesystem::path res_dir=::std::filesystem::path(argv[0]).parent_path()/"res";
    ::std::filesystem::path pro_dir=::std::filesystem::current_path()/project_name;
    ::std::filesystem::create_directories(pro_dir);
    ::copy_files_recursively(res_dir,pro_dir,project_name);
    ::std::cout<<"Create new project successfully."<<::std::endl;
    return 0;
}