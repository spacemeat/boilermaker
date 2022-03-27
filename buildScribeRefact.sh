mkdir -p build/bin

if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/scribeRefact using generated .cpp source."
    srcFiles=(./testSamples/scribeRefact/gen-cpp/txtToBin/src/*.cpp)
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/scribeRefact/main.cpp ${srcFiles[@]} -ItestSamples/scribeRefact -o build/bin/scribeRefact -lhumon
else
    echo "Making build/bin/scribeRefact using generated .hpp source."
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/scribeRefact/main.cpp -ItestSamples/scribeRefact -o build/bin/scribeRefact -lhumon
fi
