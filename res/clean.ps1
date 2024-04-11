function rmrf($path) { Remove-Item $path -Recurse -Force }
rmrf ./build/*
ni ./build/.gitkeep
mkdir ./build/res
rmrf ./bin/*.exe
