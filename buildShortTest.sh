shopt -s nullglob
if [ "${1}." == '-geg.' ]; then
    echo "Making build/bin/newsamp using generated .cpp source, json output for geg."
    srcFiles=(./testSamples/shortTest/gen-cpp/src/boma/*.cpp)
    python3 -m geg g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp ${srcFiles[@]} -ItestSamples/shortTest -o build/bin/shortTest -lhumon
elif [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/shortTest using generated .cpp source."
    srcFiles=(./testSamples/shortTest/gen-cpp/src/boma/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp ${srcFiles[@]} -ItestSamples/shortTest -o build/bin/shortTest -lhumon
else
    echo "Making build/bin/shortTest using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra testSamples/shortTest/main.cpp -ItestSamples/shortTest -o build/bin/shortTest -lhumon
fi
