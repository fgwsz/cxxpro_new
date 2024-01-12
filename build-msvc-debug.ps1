$build_path="build/msvc/debug"
if(!(Test-Path -Path $build_path)){
    mkdir $build_path
}
cd $build_path
cmake -G "Visual Studio 17 2022" ../../..
cmake --build .
cd ../../..
cp "$build_path/Debug/cxxpro_new.exe" cxxpro_new-msvc-debug.exe
./cxxpro_new-msvc-debug.exe
