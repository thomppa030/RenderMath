@echo off

mkdir build
pushd build
cmake -S .. -B .
popd
