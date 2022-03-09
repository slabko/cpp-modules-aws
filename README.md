Building AWS with S3

```
git submodule update --init --recursive
mkdir thirdparty/bin
cd thirdparty/src/aws-sdk-cpp
mkdir build && cd build

cmake .. \
	-DBUILD_ONLY="s3" \
    -DCMAKE_BUILD_TYPE=Release \
	-DCMAKE_INSTALL_PREFIX=$(pwd)/../../../bin \

make
make install
```

Building and running the application
```
mkdir build
cd build
cmake ..
make
./main
```
