#include "gen-cpp/inc/boma/boma.hpp"
#include <variant>
#include <iostream>
#include <humon/humon.hpp>

int main()
{
    auto tr = hu::Trove::fromString("{a: foo, b: 3}");
    auto & t = std::get<hu::Trove>(tr);
    auto c = t.root() % hu::val<boma::couple> {};
    std::cout << "a: " << c.get_a() << "; b: " << c.get_b() << "\n";
}
