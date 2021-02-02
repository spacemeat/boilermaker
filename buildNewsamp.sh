shopt -s nullglob
if [ "${1}." != '-ho.' ]; then
    echo "Making build/bin/newsamp using generated .cpp source."
    srcFiles=(./newsamp/gen-cpp/src/*.cpp)
    g++ -std=c++17 -O0 -g -Wall -Wextra newsamp/main.cpp ${srcFiles[@]} -Inewsamp -o build/bin/newsamp -lhumon
else
    echo "Making build/bin/newsamp using generated .hpp source."
    g++ -std=c++17 -O0 -g -Wall -Wextra newsamp/main.cpp -Inewsamp -o build/bin/newsamp -lhumon
fi
