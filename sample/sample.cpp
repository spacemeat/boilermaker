#include "sample.hpp"
#include "gen-cpp/inc/og.hpp"
#include <iostream>


int main()
{
    auto desRes = hu::Trove::fromFile("sample/ogdata.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream: " << to_string(* error) << "\n";
        return 1;
    }

    hu::Trove trove = std::move(std::get<hu::Trove>(desRes));
    auto node = trove / "config";
    og::config c = node % hu::val<og::config>{};

    std::cout << "\n";

    std::cout << c.get_graphics().get_height() << "\n";
    std::cout << c.get_weird().get_mappy()["general1"].get_numWorkers() << "\n";
    std::cout << c.get_weird().get_unmappy()["foo"].size() << "\n";
    if (c.get_weird().get_maybe().has_value())
        { std::cout << c.get_weird().get_maybe().value() << "\n"; }
    if (c.get_weird().get_maybeKinda().has_value())
    {
        for (auto & val : c.get_weird().get_maybeKinda().value())
            { std::cout << val << "\n"; }
    }
    for (int i = 0; i < 4; ++i)
    {
        std::cout << c.get_weird().get_a_of_o()[i].has_value() << "\n";
    }

    std::cout << "\n";

    return 0;
}
