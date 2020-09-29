#include "sample.hpp"
#include "gen-cpp/inc/og.hpp"


int main()
{
    og::general g0 {};
    og::general g1 {
        "Boma Test", {1, 0, 0}, 1
    };

    return g1.get_numWorkers();
}
