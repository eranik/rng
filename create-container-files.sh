#!/bin/bash

rm -rf ./rng-container
mkdir -p ./rng-container
cd ./rng-container
mkdir -p ./bin
cp ../rng ./bin/
for i in `ldd ./bin/rng | grep -v linux-vdso.so.1 | awk {' if ( $3 == "") print $1; else print $3 '}`; do cp --parents $i ./ ; done
cp ../config.json .
cd ..
tar -czvf ./rng-container.tar.gz ./rng-container -C rng-container

# docker import ./rng-container.tar.gz rng-container


