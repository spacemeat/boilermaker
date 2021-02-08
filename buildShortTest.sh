shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/shortTest using generated .cpp source."
    srcFiles=(./shortTest/src/gen-cpp/src/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra shortTest/main.cpp ${srcFiles[@]} -IshortTest -o build/bin/shortTest -lhumon
else
    echo "Making build/bin/shortTest using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra shortTest/main.cpp -IshortTest -o build/bin/shortTest -lhumon
fi
