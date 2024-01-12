$build_path="build/mingw/release"
if(!(Test-Path -Path $build_path)){
    mkdir $build_path
}
cd $build_path
cmake -G "MinGW Makefiles" ../../..
cmake --build . --config Release
cd ../../..
cp "$build_path/cxxpro_new.exe" cxxpro_new-mingw-release.exe
./cxxpro_new-mingw-release.exe
