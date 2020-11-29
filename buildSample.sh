shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/sample using generated .cpp source."
    srcFiles=(./sample/gen-cpp/src/*.cpp)
    g++ -std=c++17 -Wall -O0 -g -Wextra sample/sample.cpp ${srcFiles[@]} -Isample -o build/bin/sample -lhumon
else
    echo "Making build/bin/sample using generated .hpp source."
    g++ -std=c++17 -Wall -O0 -g -Wextra sample/sample.cpp -Isample -o build/bin/sample -lhumon
fi
