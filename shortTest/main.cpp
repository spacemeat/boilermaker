#include "inc/boma/shortTest.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    auto hu = R"(
{
    coup: {a: foo, b: 3}
    vacoup: {
        coupleses: [
            [
                { a: bar, b: 4 }
                { a: baa, b: 5 }
            ]
            []
            [
                { a: sna, b: 6 }
                { a: flu, b: 7 }
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
        std::cout << "Got value: '" << ev << "'.\n";
        auto ev2 = t->root() / "vacoup" % hu::val<shortTest::a_of_v_of_couples>();
        std::cout << "Got value: '" << ev2 << "'.\n";
    }

    return 0;
}
