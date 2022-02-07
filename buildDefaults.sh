if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/defaults using generated .cpp source."
    srcFiles=(./testSamples/defaults/gen-cpp/src/boma/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/defaults/main.cpp ${srcFiles[@]} -ItestSamples/defaults -o build/bin/defaults -lhumon
else
    echo "Making build/bin/defaults using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/defaults/main.cpp -ItestSamples/defaults -o build/bin/defaults -lhumon
fi
