shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/shortTest using generated .cpp source."
    srcFiles=(./testSamples/shortTest/gen-cpp/shortTest/src/*.cpp)
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp ${srcFiles[@]} -ItestSamples/shortTest -o build/bin/shortTest -lhumon
else
    echo "Making build/bin/shortTest using generated .hpp source."
    geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp -ItestSamples/shortTest -o build/bin/shortTest -lhumon
fi
