#include "gen/shortTest/inc/shortTest.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    auto hu = R"(
{
    coup: {a: foo, bee: [cat, dog]}
    vacoup: {
        coupleses: [
            [
                { a: bar, bee: cat }
                { a: baa, bee: dog }
            ]
            []
            [
                { a: sna, bee: pig }
                { a: flu, bee: [cat, pig] }
            ]
            []
        ]
    }
}
)";
    auto res = hu::Trove::fromString(hu);
    if (auto t = std::get_if<hu::Trove>(& res))
    {
        auto ev = t->root() / "coup" % hu::val<shortTest::couple>();
        std::cout << "Got value: '" << shortTest::HumonFormat(ev) << "'.\n";
        auto ev2 = t->root() / "vacoup" % hu::val<shortTest::a_of_v_of_couples>();
        std::cout << "Got value: '" << shortTest::HumonFormat(ev2) << "'.\n";
    }

    return 0;
}
