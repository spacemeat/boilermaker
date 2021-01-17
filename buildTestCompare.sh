shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/testCompare using generated .cpp source."
    srcFiles=(./testCompare/gen-cpp/src/*.cpp)
    g++ -std=c++17 -Wall -O0 -g -Wextra testCompare/testCompare.cpp ${srcFiles[@]} -ItestCompare -o build/bin/testCompare -lhumon
else
    echo "Making build/bin/testCompare using generated .hpp source."
    g++ -std=c++17 -Wall -O0 -g -Wextra testCompare/testCompare.cpp -ItestCompare -o build/bin/testCompare -lhumon
fi
