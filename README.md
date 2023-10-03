# make\_c\_project
input a string from console `${project_name}`,
and `${project_name}` can only use letters and numbers and underscores.

use:  
`make_c_project.exe ${project_name}`

this program will create the following file structure:  
```
./${project\_name}/  
    |--include/  
        |--main.h  
    |--src/  
        |--main.cpp  
    |--CMakeLists.txt  
    |--mingw\_build.ps1  
    |--msvc\_build.ps1  
    |--README.md  
    |--git\_push.ps1
```
