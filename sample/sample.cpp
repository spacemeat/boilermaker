#include <iostream>
#include "sample.hpp"
#include "gen-cpp/inc/og.hpp"

int test()
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

    return 0;
}

/*
int testObVector()
{
    og::ObservableVector<int> ov;
    ov.setNotifyFn([](auto & ovp){ std::cout << "ov change; new size = " << ovp.size() << "\n"; });

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

    return 0;
}

int testObNumeric()
{
    og::ObservableNumeric<int> oi { 10 };
    oi.setNotifyFn([](auto & oip){std::cout << "int changed to " << oip << "\n"; });
    oi = 1;
    oi += 2;
    oi -= 4;

    oi = oi + 3;
    oi = 3 + oi;
    oi = oi + oi;

    oi += oi;

    std::cout << "oi: " << oi << "\n";

    og::ObservableVector<og::ObservableNumeric<float>> ov3;
    ov3.setNotifyFn([](auto & t){ std::cout << "ov3 change: new size == " << t.size() << "\n"; });

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

    og::ObservableNumeric<int> ppe = ov3[7];
    std::cout << "PPE: " << ppe << "\n";

    for (auto & [changeType, startIndex, num] : ov3.getChanges())
    {
        std::cout << "Change type: " << (int) changeType << "; startIndex: " << startIndex << "; num: " << num << "\n";
    }

    return 0;
}

int testObString()
{
    og::ObservableVector<og::ObservableString<char>> ov4;
    ov4.setNotifyFn([](auto & t)
    {
        std::cout << "ov4 change: new size == " << t.size() << "\n";
        for (std::size_t i = 0; i < t.size(); ++i) { std::cout << " " << t[i]; }
        std::cout << "\n";
    });

    ov4.push_back("foo");
    ov4.push_back("bar");
    ov4.push_back("baz");
//    ov4[0].setNotifyFn([](auto & t) { std::cout << "Changed idx 0 to " << t << "\n"; });
//    ov4[1].setNotifyFn([](auto & t) { std::cout << "Changed idx 1 to " << t << "\n"; });
//    ov4[2].setNotifyFn([](auto & t) { std::cout << "Changed idx 2 to " << t << "\n"; });

    std::cout << "Changing [0]:\n";
    ov4[0] = "Floo";

    std::cout << "Assigning 3:\n";
    ov4.assign({"Foo", "Bar", "Baz"});
    std::cout << "Changing [2]:\n";
    ov4[2] = "Schmoo";

    for (std::size_t i = 0; i < ov4.size(); ++i)
    {
        std::cout << ov4[i] << "\n";
    }

    return 0;
}

int testObArray()
{
    og::ObservableArray<og::ObservableString<char>, 3> 
        ov5 { "foo", "bar", "baz"};
    ov5.setNotifyFn([](auto & t)
    {
        std::cout << "ov5 change; new values:\n";
        for (std::size_t i = 0; i < t.size(); ++i) { std::cout << " " << t[i]; }
        std::cout << "\n";
    });

    ov5.at(0) = "foO";
    ov5.at(1) = "baR";
    ov5.at(2) = "baZ";
//    ov5[0].setNotifyFn([](auto & t) { std::cout << "Changed idx 0 to " << t << "\n"; });
//    ov5[1].setNotifyFn([](auto & t) { std::cout << "Changed idx 1 to " << t << "\n"; });
//    ov5[2].setNotifyFn([](auto & t) { std::cout << "Changed idx 2 to " << t << "\n"; });

    std::cout << "Changing [0]:\n";
    ov5[0] = "Floo";

    std::cout << "Filling 3:\n";
    ov5.fill("Foo");

    std::cout << "Changing [2]:\n";
    ov5[2] = "Schmoo";

    for (std::size_t i = 0; i < ov5.size(); ++i)
    {
        std::cout << ov5[i] << "\n";
    }

    return 0;
}

int testObPair()
{
    og::ObservablePair<og::ObservableString<char>, og::ObservableNumeric<int>> ov6 { "foo", 10 };
    ov6.setNotifyFn([](auto & t)
    {
        std::cout << "ov6 change; new values:\n";
        if (t.getChanges()[0]) { std::cout << "first changed. "; }
        if (t.getChanges()[1]) { std::cout << "second changed. "; }
        std::cout << "first: " << t.first << "; second: " << t.second << "\n";
    });
    ov6.forgetChanges();

    ov6.first = "FOO";
    ov6.forgetChanges();
    ov6.second = 20;

    ov6 = { "baz", 30 };

    return 0;
}
*/

int testCompare()
{
    auto desRes = hu::Trove::fromFile("sample/ogdata.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream: " << to_string(* error) << "\n";
        return 1;
    }

    auto & trove0 = std::get<hu::Trove>(desRes);
    auto node = trove0.root();
    auto c0 = node % hu::val<og::config>{};

    desRes = hu::Trove::fromFile("sample/ogdata.hu");
    if (auto error = std::get_if<hu::ErrorCode>(& desRes))
    {
        std::cerr << "Error loading the token stream: " << to_string(* error) << "\n";
        return 1;
    }

    auto & trove1 = std::get<hu::Trove>(desRes);
    node = trove1.root();
    auto c1 = node % hu::val<og::config>{};

    auto diff = og::Diff(c0, c1);
    std::cout << "diffs: " << diff.diffs << "\n";

    return 0;
}

int main()
{
    int r;
    r = test();
    if (r) { return r; }

    r = testCompare();
    if (r) { return r; }
    /*
    r = testObVector();
    if (r) { return r; }
    r = testObNumeric();
    if (r) { return r; }
    r = testObArray();
    if (r) { return r; }
    r = testObString();
    if (r) { return r; }
    r = testObPair();
    if (r) { return r; }
    */

    return 0;
}
