# cxxpro\_new
input a string from console `${project_name}`,
and `${project_name}` can only use letters and numbers and underscores.

use:  
`cxxpro_new*.exe ${project_name}`

this program will create the following file structure:  
```
./${project_name}/  
    |--bin/  
    |--build/  
    |--vendor/  
    |--include/  
    |--src/  
        |--main.cpp  
    |--tests/  
    |--res/  
    |--releases/  
    |--docs/  
    |--CMakeLists.txt  
    |--LICENSE  
    |--README.md  
    |--.gitignore
    |--git-push.ps1
    |--git-keep.ps1
    |--build*.ps1  
    |--clean.ps1  
```
