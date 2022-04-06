mkdir -p build/bin

echo "Making build/bin/shortTest using generated .cpp source."
srcFiles=(./testSamples/shortTest/gen-cpp/shortTest/src/*.cpp)
g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp ${srcFiles[@]} -ItestSamples/shortTest -o build/bin/shortTest -lhumon
