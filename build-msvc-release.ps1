$build_path="build/msvc/release"
if(!(Test-Path -Path $build_path)){
    mkdir $build_path
}
cd $build_path
cmake -G "Visual Studio 17 2022" ../../..
cmake --build . --config Release
cd ../../..
cp "$build_path/Release/cxxpro_new.exe" cxxpro_new-msvc-release.exe
./cxxpro_new-msvc-release.exe
