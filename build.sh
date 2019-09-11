#rm *.so main *.o
#
#g++ -I. -o libadd2.so -fPIC -shared add2.cpp
#g++ -L. -ladd2 -o libadd1.so -fPIC -shared add1.cpp
#g++ -L. -ladd1 -o libadd.so -fPIC -shared add.cpp
#g++ -L. -Wl,-rpath,/home/cannon/rokid/document/performance/library-A-B-C -o main main.cpp -ladd -ladd1 -ladd2

rm -rf build
mkdir -p build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=.
make -j8
make install