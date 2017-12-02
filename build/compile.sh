#!/bin/bash

BUILD_PATH="$(dirname "${BASH_SOURCE[0]}")"
pushd $BUILD_PATH
cmake -GNinja . && ninja
popd
