shopt -s nullglob
srcFiles=(./sample/gen-cpp/src/*.cpp)
g++ -std=c++17 -Wall -O3 -Wextra sample/sample.cpp ${srcFiles[@]} -Isample -o build/bin/sample -lhumon
