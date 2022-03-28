mkdir -p build/bin

if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/defaults using generated .cpp source."
    srcFiles=(./testSamples/defaults/gen-cpp/boma/src/*.cpp)
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/defaults/main.cpp ${srcFiles[@]} -ItestSamples/defaults -o build/bin/defaults -lhumon
else
    echo "Making build/bin/defaults using generated .hpp source."
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/defaults/main.cpp -ItestSamples/defaults -o build/bin/defaults -lhumon
fi
