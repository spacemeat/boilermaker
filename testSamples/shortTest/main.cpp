#include "gen-cpp/inc/boma/shortTest.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    auto hu = R"(
{
    coup: {a: foo, bee: 3}
    vacoup: {
        coupleses: [
            [
                { a: bar, bee: 4 }
                { a: baa, bee: 5 }
            ]
            []
            [
                { a: sna, bee: 6 }
                { a: flu, bee: 7 }
            ]
            []
        ]
    }
}
)";
    auto res = hu::Trove::fromString(hu);
    if (auto t = std::get_if<hu::Trove>(&res))
    {
        auto ev = t->root() / "coup" % hu::val<shortTest::couple>();
        std::cout << "Got value: '" << shortTest::HumonFormat(ev, 2) << "'.\n";
        auto ev2 = t->root() / "vacoup" % hu::val<shortTest::a_of_v_of_couples>();
        std::cout << "Got value: '" << shortTest::HumonFormat(ev2) << "'.\n";
    }

    return 0;
}
