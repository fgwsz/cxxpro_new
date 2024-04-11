function rmrf($path) { Remove-Item $path -Recurse -Force }
rmrf ./build/*
ni ./build/.gitkeep
rmrf ./bin/*.exe
