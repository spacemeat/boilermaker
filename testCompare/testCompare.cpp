#include <iostream>
#include "testCompare.hpp"
#include "gen-cpp/inc/testCompare.hpp"

int test()
{
    auto desRes = hu::Trove::fromFile("testCompare/testCompare0.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream testCompare0.hu: " << to_string(* error) << "\n";
        return 1;
    }

    auto & trove0 = std::get<hu::Trove>(desRes);
    std::cout << "testCompare0:\n" << std::get<std::string>(trove0.toPrettyString(4, false, hu::getAnsiColorTable()));
    auto node = trove0 / "testRoot";
    auto t0 = node % hu::val<testCompare::testRoot>{};    

    desRes = hu::Trove::fromFile("testCompare/testCompare1.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream testCompare1.hu: " << to_string(* error) << "\n";
        return 1;
    }

    auto & trove1 = std::get<hu::Trove>(desRes);
    std::cout << "testCompare1:\n" << std::get<std::string>(trove1.toPrettyString(4, false, hu::getAnsiColorTable()));
    node = trove1 / "testRoot";
    auto t1 = node % hu::val<testCompare::testRoot>{};

    // compare t0 and t1, and get the diff object back
    auto diff = testCompare::Diff(t0, t1);

    // now check diff's contents
    std::cout << "diffs: " << diff.memberDiffs << "\n";
    for (std::size_t i = 0; i < diff.v_of_ints_diffs.elementDiffs.size(); ++i)
    {
        auto const & [idx, kind, obj] = diff.v_of_ints_diffs.elementDiffs[i];
        std::cout << "diffs.v_of_ints_diffs.elementDiffs[" << i << "]: "
            << "idx: " << idx << "; kind: " << (int) kind << "\n";
    }

    for (std::size_t i = 0; i < diff.a_of_v_of_ints_diffs.elementDiffs.size(); ++i)
    {
        auto const & [idx, obj] = diff.a_of_v_of_ints_diffs.elementDiffs[i];
        std::cout << "diffs.a_of_v_of_ints_diffs.elementDiffs[" << i << "]: "
            << "idx: " << idx << "\n";
        for (std::size_t j = 0; j < obj.elementDiffs.size(); ++j)
        {
            auto const & [idx2, kind2, obj2] = obj.elementDiffs[j];
            std::cout << "diffs.v_of_ints_diffs.elementDiffs[" << i << "][" << j << "]: "
                << "idx: " << idx2 << "; kind: " << (int) kind2 << "\n";
        }
    }

    for (std::size_t i = 0; i < diff.users_diffs.elementDiffs.size(); ++i)
    {
        auto const & [idx, kind, obj] = diff.users_diffs.elementDiffs[i];
        std::cout << "diffs.users_diffs.elementDiffs[" << i << "]: "
            << "idx: " << idx << "; kind: " << (int) kind << "; user_diffs: " << obj.memberDiffs << "\n";
    }

    for (std::size_t i = 0; i < diff.things_diffs.elementDiffs.size(); ++i)
    {
        auto const & [elem, kind, obj] = diff.things_diffs.elementDiffs[i];
        std::cout << "diffs.things_diffs.elementDiffs[" << i << "]: "
            << "elem: " << elem << "; kind: " << (int) kind << "\n";
    }

    std::cout << "stuff.diffs: " << diff.stuff_diffs.memberDiffs << "\n";
    auto & tup = diff.stuff_diffs.diffObjects;
    if (std::get<0>(tup).memberDiffs)
        { std::cout << "Stuff<0> diff: true\n"; }
    if (std::get<1>(tup).memberDiffs)
        { std::cout << "Stuff<1> diff: true\n"; }
    if (std::get<2>(tup).memberDiffs.any())
        { std::cout << "Stuff<2> diff: true\n"; }
    
    std::cout << "two.diffs: " << diff.two_diffs.memberDiffs << "\n";

    return 0;
}

int main()
{
    int r;
    r = test();
    if (r) { return r; }

    return 0;
}
