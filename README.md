# make\_c\_project
input a string from console `${project name}`,
and `${project\_name}` can only use letters and numbers and underscores.

use:  
`make_c_project.exe ${project_name}`

this program will create the following file structure:  
./${project\_name}/  
&ensp;&ensp;|--include/  
&ensp;&ensp;&ensp;&ensp;|--main.h  
&ensp;&ensp;|--src/  
&ensp;&ensp;&ensp;&ensp;|--main.cpp  
&ensp;&ensp;|--CMakeLists.txt  
&ensp;&ensp;|--mingw_build.ps1  
&ensp;&ensp;|--msvc_build.ps1  
&ensp;&ensp;|--README.md  
&ensp;&ensp;|--git_push.ps1