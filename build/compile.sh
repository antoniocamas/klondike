#!/bin/bash

BUILD_PATH="$(dirname "${BASH_SOURCE[0]}")"
pushd $BUILD_PATH
cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -GNinja . && ninja
popd
