#include "txtToBin/inc/boma/txtToBin-boma.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    auto hu = R"({foo: timeout})";
    auto res = hu::Trove::fromString(hu);
    if (auto t = std::get_if<hu::Trove>(&res))
    {
        auto ev = t->root() / "foo" % hu::val<::VkResult>();
        std::cout << "Got value " << ev << ".\n";
    }

    return 0;
}
