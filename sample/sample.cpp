#include <iostream>
#include "sample.hpp"
#include "gen-cpp/inc/og.hpp"
#include "observableVector.hpp"
#include "observableNumeric.hpp"

int main()
{
    auto desRes = hu::Trove::fromFile("sample/ogdata.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream: " << to_string(* error) << "\n";
        return 1;
    }

    auto & trove = std::get<hu::Trove>(desRes);
    auto node = trove.root();
    auto c = node % hu::val<og::config>{};

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

    og::ObservableVector<int> ov;
    ov.setNotifyFn([](){ std::cout << "change\n"; });

    ov.push_back(3);
    ov.push_back(3);
    ov.push_back(3);
    ov.assign({1, 2, 3});
    ov.insert(ov.begin(), 0);
    auto it = ov.insert(ov.end(), 5);
    ov.emplace(it, 4);
    it = ov.emplace(it, 98);
    ov.erase(it);
    ov.emplace_back(6);
    ov.emplace_back(33);
    ov.pop_back();
    ov.resize(8, 7);

    og::ObservableVector<int> ov2;
    ov2.emplace_back(10);
    ov2.emplace_back(20);
    ov2.emplace_back(30);

    ov.swap(ov2);
    ov2.emplace_back(8);
    ov.swap(ov2);

    ov2 = ov;
    ov = ov2;

    for (std::size_t i = 0; i < ov.size(); ++i)
    {
        std::cout << ov[i] << "\n";
    }

    og::ObservableNumeric<int> oi { 10 };
    oi.setNotifyFn([](){std::cout << "int changed\n"; });
    oi = 1;
    oi += 2;
    oi -= 4;

    oi = oi + 3;
    oi = 3 + oi;
    oi = oi + oi;

    oi += oi;

    std::cout << "oi: " << oi << "\n";

    og::ObservableVector<og::ObservableNumeric<float>> ov3;
    ov3.setNotifyFn([](){ std::cout << "ov3 change\n"; });

    ov3.push_back(3);
    ov3.push_back(3.0f);
    ov3.push_back(3.0);
    ov3.assign({1, 2, 3});
    ov3.insert(ov3.begin(), 0);
    auto it3 = ov3.insert(ov3.end(), 5);
    ov3.emplace(it3, 4);
    it3 = ov3.emplace(it3, 98);
    ov3.erase(it3);
    ov3.emplace_back(6);
    ov3.emplace_back(33);
    ov3.pop_back();
    ov3.resize(8, 7.5f);
    ov3.resize(9, 100);
    std::cout << "One more?\n";
    ov3[8] = 8;

    for (std::size_t i = 0; i < ov3.size(); ++i)
    {
        std::cout << ov3[i] << "\n";
    }

    for (auto & [changeType, startIndex, num] : ov3.getChanges())
    {
        std::cout << "Change type: " << (int) changeType << "; startIndex: " << startIndex << "; num: " << num << "\n";
    }

    return 0;
}
