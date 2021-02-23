docker run --entrypoint bash -it --rm --name ubi -e DISPLAY=host.docker.internal:0 -v $(pwd):/root/aegi aegisub:bionic -c "
cd /root/aegi/deps/cxxopts
cmake -DCXXOPTS_BUILD_EXAMPLES=OFF -DCXXOPTS_BUILD_TESTS=OFF -DCXXOPTS_ENABLE_INSTALL=ON .
make install
git clean -dfx

cd /root/aegi
bash -l
"
