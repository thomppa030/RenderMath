#!/usr/bin/bash

mdkir build
cd build
cmake -S .. -B . -G "Unix Makefiles"
cd ..
