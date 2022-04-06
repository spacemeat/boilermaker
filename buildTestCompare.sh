mkdir -p build/bin

echo "Making build/bin/testCompare using generated .cpp source."
srcFiles=(./testSamples/testCompare/gen-cpp/src/*.cpp)
g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/testCompare/main.cpp ${srcFiles[@]} -ItestSamples/testCompare -o build/bin/testCompare -lhumon
