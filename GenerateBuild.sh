#!/usr/bin/bash

mkdir build
cd build
cmake -S .. -B . -G "Unix Makefiles"
cd ..
