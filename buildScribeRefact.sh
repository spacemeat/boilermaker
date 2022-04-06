mkdir -p build/bin

echo "Making build/bin/scribeRefact using generated .cpp source."
srcFiles=(./testSamples/scribeRefact/gen-cpp/txtToBin/src/*.cpp)
g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/scribeRefact/main.cpp ${srcFiles[@]} -ItestSamples/scribeRefact -o build/bin/scribeRefact -lhumon
