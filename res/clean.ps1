function rmrf($path) { Remove-Item $path -Recurse -Force }
rmrf ./build/mingw/
rmrf ./build/msvc/
rmrf ./bin/*.exe
