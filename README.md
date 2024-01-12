# cxxpro\_new
input a string from console `${project_name}`,
and `${project_name}` can only use letters and numbers and underscores.

use:  
`cxxpro_new.exe ${project_name}`

this program will create the following file structure:  
```
./${project_name}/  
    |--include/  
        |--main.hpp  
    |--src/  
        |--main.cpp  
    |--CMakeLists.txt  
    |--build*.ps1  
    |--README.md  
    |--git-push.ps1
    |--.gitignore
```
