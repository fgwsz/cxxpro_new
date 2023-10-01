# make\_c\_project
input a string from console `${project name}`,
and ${project\_name} can only use letters and numbers and underscores.
use like:`make_c_project.exe ${project_name}`

this program will create the following file structure:
./${project\_name}/  
    |--include/  
        |--main.h  
    |--src/  
        |--main.cpp  
    |--CMakeLists.txt  
    |--mingw_build.ps1  
    |--msvc_build.ps1  
    |--README.md  
    |--git_push.ps1
