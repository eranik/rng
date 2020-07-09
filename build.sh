mkdir -p _build_dir
pushd _build_dir
cmake .. 2>&1 | tee ../log_build.log
make -j 2>&1 | tee -a ../log_build.log
cp ./rng .. 2>&1 | tee -a ../log_build.log
popd
