#ifndef __MAIN_HPP__
#define __MAIN_HPP__
#include<string>
#include<fstream>
#include<iostream>
#include<filesystem>
static inline void replace_all(
    ::std::string& string,
    ::std::string const& old_string,
    ::std::string const& new_string
)noexcept{
    size_t pos=0;
    while((pos=string.find(old_string,pos))!=std::string::npos){
        string.replace(pos,old_string.length(),new_string);
        pos+=new_string.length();
    }
}
static inline void replace_project_name(
    ::std::filesystem::path const& file_path,
    ::std::string const& project_name
){
    ::std::ifstream input_file(file_path);
    if(!input_file.is_open()){
        ::std::cerr<<"Failed to open file: "<<file_path<<::std::endl;
        return;
    }
    ::std::string content((::std::istreambuf_iterator<char>(input_file)),::std::istreambuf_iterator<char>());
    input_file.close();
    ::replace_all(content,"`project_name`",project_name);
    ::std::ofstream output_file(file_path);
    if(!output_file.is_open()){
        ::std::cerr<<"Failed to create output file: "<<file_path<<::std::endl;
        return;
    }
    output_file<<content;
    output_file.close();
}
static inline void copy_files_recursively(
    ::std::filesystem::path const& source_dir,
    ::std::filesystem::path const& destination_dir,
    ::std::string const& project_name
){
    for(auto const& entry: ::std::filesystem::recursive_directory_iterator(source_dir)){
        ::std::filesystem::path const relative_path=::std::filesystem::relative(entry.path(),source_dir);
        ::std::filesystem::path const new_file_path=destination_dir/relative_path;
        if(::std::filesystem::is_directory(entry.path())&&!::std::filesystem::exists(new_file_path)){
            ::std::filesystem::create_directories(new_file_path);
        }else if(::std::filesystem::is_regular_file(entry.path())){
            ::std::filesystem::copy_file(entry,new_file_path,::std::filesystem::copy_options::update_existing);
            if(::std::filesystem::is_regular_file(entry)&&!std::ifstream(new_file_path).is_open()){
                ::std::cerr<<"Failed to open file: "<<new_file_path<<::std::endl;
                continue;
            }
            ::replace_project_name(new_file_path,project_name);
        }
    }
}
static inline bool check_project_name(::std::string const& project_name)noexcept{
    //首字符不能为数字
    if(::std::isdigit(project_name[0])){
        return false;
    }
    //检查字符串中的每个字符
    for(auto const& ch:project_name){
        //字符必须是字母、数字或下划线
        if(!(::std::isalnum(ch)||ch=='_')){
            return false;
        }
    }
    return true;
}
#endif//!__MAIN_HPP__