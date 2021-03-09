if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/newsamp using generated .cpp source."
    srcFiles=(./testSamples/newsamp/gen-cpp/txtToBin/src/boma/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/newsamp/main.cpp ${srcFiles[@]} -ItestSamples/newsamp -o build/bin/newsamp -lhumon
else
    echo "Making build/bin/newsamp using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/newsamp/main.cpp -ItestSamples/newsamp -o build/bin/newsamp -lhumon
fi
