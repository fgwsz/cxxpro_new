# make\_c\_project
input a string from console `${project_name}`,
and `${project_name}` can only use letters and numbers and underscores.

use:  
`make_c_project.exe ${project_name}`

this program will create the following file structure:  
```
./${project_name}/  
    |--include/  
        |--main.hpp  
    |--src/  
        |--main.cpp  
    |--CMakeLists.txt  
    |--mingw_build.ps1  
    |--msvc_build.ps1  
    |--README.md  
    |--git_push.ps1
    |--.gitignore
```
