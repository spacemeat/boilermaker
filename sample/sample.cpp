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
    auto node = trove.root();
    og::config c = node % hu::val<og::config>{};

    std::cout << "\n";

    std::cout << c.get_graphics().get_height() << "\n";
    std::cout << c.get_graphics().get_swapchain().get_presentModePriorities() << "\n";
    std::cout << c.get_weird().get_mappy().find("general1")->second.get_numWorkers() << "\n";
    std::cout << c.get_weird().get_unmappy().find("foo")->second.size() << "\n";
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
    if (std::holds_alternative<std::string>(c.get_weird().get_var()))
        { std::cout << std::get<std::string>(c.get_weird().get_var()) << "\n"; }
    for (std::size_t i = 0; i < c.get_weird().get_varVect().size(); ++i)
    {
        if (auto v = std::get_if<std::string>(& c.get_weird().get_varVect()[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<int>(& c.get_weird().get_varVect()[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<float>(& c.get_weird().get_varVect()[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<og::general>(& c.get_weird().get_varVect()[i]); v)
            { std::cout << v->get_programName() << "\n"; }
        else if (auto v = std::get_if<std::vector<std::string>>(& c.get_weird().get_varVect()[i]); v)
            { std::cout << v->at(2) << "\n"; }
    }

   /*
    std::cout << c.graphics.height << "\n";
    std::cout << c.weird.mappy.find("general1")->second.numWorkers << "\n";
    std::cout << c.weird.unmappy.find("foo")->second.size() << "\n";
    if (c.weird.maybe.has_value())
        { std::cout << c.weird.maybe.value() << "\n"; }
    if (c.weird.maybeKinda.has_value())
    {
        for (auto & val : c.weird.maybeKinda.value())
            { std::cout << val << "\n"; }
    }
    for (int i = 0; i < 4; ++i)
    {
        std::cout << c.weird.a_of_o[i].has_value() << "\n";
    }
    if (std::holds_alternative<std::string>(c.weird.var))
        { std::cout << std::get<std::string>(c.weird.var) << "\n"; }
    for (std::size_t i = 0; i < c.weird.varVect.size(); ++i)
    {
        if (auto v = std::get_if<std::string>(& c.weird.varVect[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<int>(& c.weird.varVect[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<float>(& c.weird.varVect[i]); v)
            { std::cout << *v << "\n"; }
        else if (auto v = std::get_if<og::general>(& c.weird.varVect[i]); v)
            { std::cout << v->programName << "\n"; }
        else if (auto v = std::get_if<std::vector<std::string>>(& c.weird.varVect[i]); v)
            { std::cout << v->at(2) << "\n"; }
    }
    */

    std::cout << "\n";

    std::cout << c << "\n";

    std::ostringstream oss;
    oss << og::bomaStream {} << c;
    auto nt = hu::Trove::fromString(oss.str());
    if (auto t = std::get_if<hu::Trove>(& nt); t)
    {
        std::cout << "\n" << std::get<std::string>(t->toPrettyString(4, false, hu::getAnsiColorTable()));
    }

    return 0;
}
