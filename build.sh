mkdir -p _build_dir
pushd _build_dir
cmake ..
make -j
cp ./rng ..
popd
