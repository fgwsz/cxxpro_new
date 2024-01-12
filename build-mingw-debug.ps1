$build_path="build/mingw/debug"
if(!(Test-Path -Path $build_path)){
    mkdir $build_path
}
cd $build_path
cmake -G "MinGW Makefiles" ../../..
cmake --build .
cd ../../..
cp "$build_path/cxxpro_new.exe" cxxpro_new-mingw-debug.exe
./cxxpro_new-mingw-debug.exe
