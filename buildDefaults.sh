mkdir -p build/bin

echo "Making build/bin/defaults using generated .hpp source."
srcFiles=(./testSamples/defaults/gen/boma/src/*.cpp)
g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/defaults/main.cpp ${srcFiles[@]} -ItestSamples/defaults -o build/bin/defaults -lhumon
