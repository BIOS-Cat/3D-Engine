#!/bin/bash

echo 'Installing SDL2'

set -x

curl -sL https://libsdl.org/release/SDL2-2.0.5.tar.gz | tar xz
pushd SDL2-2.0.5
./configure && make && make install
popd
