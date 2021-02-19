shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/testCompare using generated .cpp source."
    srcFiles=(./testSamples/testCompare/gen-cpp/src/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/testCompare/main.cpp ${srcFiles[@]} -ItestSamples/testCompare -o build/bin/testCompare -lhumon
else
    echo "Making build/bin/testCompare using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/testCompare/main.cpp -ItestSamples/testCompare -o build/bin/testCompare -lhumon
fi
