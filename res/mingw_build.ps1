if(Test-Path -Path mingw_build){}else{
    mkdir mingw_build
}
cd mingw_build
cmake -G"MinGW Makefiles" ..
cmake --build .   
cd ..
cp mingw_build/`project_name`.exe `project_name`-mingw_build.exe
./`project_name`-mingw_build.exe
