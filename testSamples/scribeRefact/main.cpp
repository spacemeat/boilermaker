#include "gen-cpp/txtToBin/inc/boma/txtToBin.hpp"
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;
using namespace txtToBin;

int testEnums()
{
    auto hu = R"(
{
    foo: [nonstandard_block_size_bit single_miptail_bit]
    bar: object
    baz: single_miptail_bit
}
)";
    auto res = hu::Trove::fromString(hu);
    if (auto t = get_if<hu::Trove>(&res))
    {
        auto ev = t->root() / "foo" % hu::val<VkSparseImageFormatFlagBits>();
        cout << "Got value: '" << HumonFormat(ev) << "'.\n";
        ev = (VkSparseImageFormatFlagBits) ((int) ev + VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT - VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT);
        cout << "Mod value: '" << HumonFormat(ev) << "'.\n";
        auto ev2 = t->root() / "bar" % hu::val<VkSystemAllocationScope>();
        cout << "Got value: '" << HumonFormat(ev2) << "'.\n";
        auto ev3 = t->root() / "baz" % hu::val<VkSparseImageFormatFlagBits>();
        cout << "Got value: '" << HumonFormat(ev3) << "'.\n";
        cout << '\n';
    }

    return 0;
}


int testWut(string_view dir)
{
    string path = string(dir) + string("/testSamples/newsamp/wut.hu");
    cout << "path = " << path << '\n';
    auto res = hu::Trove::fromFile(path);
    cout << "Trove loaded." << '\n';
    if (auto t = get_if<hu::Trove>(&res))
    {
        auto && whaa = t->root() / "whaa" % hu::val<txtToBin::wut> {};
        cout << "Extracted." << '\n';

        auto & huh = whaa.get_huh();
        auto & opt0 = huh[0][0];
        auto & p = get<0>(*opt0);
        cout << "pair: " << p.first << "; " << p.second << '\n';
        auto & opt1 = huh[0][1];
        auto & tu = get<1>(*opt1);
        cout << "tuple: " << get<0>(tu) << "; " << get<1>(tu) << "; " << get<2>(tu) << '\n';
        auto & opt2 = huh[0][2];
        auto & ma0 = get<2>(*opt2);
        for (auto const & [k, v] : ma0)
        {
            cout << "map entry: " << k << ": " << v << '\n';
        }
        auto & opt3 = huh[0][3];
        auto & ma1 = get<3>(*opt3);
        for (auto const & [k, v] : ma1)
        {
            cout << "unordered_map entry: " << k << ": " << v << '\n';
        }

        auto & opt4 = huh[1][0];
        auto & se = get<4>(*opt4);
        for (auto const & e : se)
        {
            for (auto const & [k, v]: e)
            {
                cout << "set->umap entry: " << k << ": " << HumonFormat(v) << '\n';
            }
        }

        auto & opt5 = huh[1][1];
        auto & use = get<5>(*opt5);
        for (auto const & e : use)
        {
            cout << "unordered_set entry: " << e << '\n';
        }


        auto & opt6 = huh[1][2];
        auto & som = get<6>(*opt6);
        for (auto const & e : som)
        {
            for (auto const & [k, v]: e)
            {
                cout << "set->map entry: " << k << ": " << v << '\n';
            }
        }

        cout << '\n';

        return 0;
    }

    return 1;
}

int testPrintingWut(string_view dir)
{
    string path = string(dir) + string("/testSamples/newsamp/wut.hu");
    cout << "path = " << path << '\n';
    auto res = hu::Trove::fromFile(path);
    if (auto t = get_if<hu::Trove>(&res))
    {
        auto whaa = t->root() / "whaa" % hu::val<txtToBin::wut> {};

        cout << HumonFormat(whaa) << "\n\n";

        return 0;
    }

    return 1;
}


int testBinaryWut(string_view dir)
{
    string path = string(dir) + string("/testSamples/newsamp/wut.hu");
    cout << "path = " << path << '\n';
    auto res = hu::Trove::fromFile(path);
    if (auto t = get_if<hu::Trove>(&res))
    {
        auto whaa = t->root() / "whaa" % hu::val<txtToBin::wut> {};

        string binPath = string(dir) + string("/testSamples/newsamp/wutBinary.bin");
        auto out = ofstream(binPath, std::ios::binary);
        out << BinaryFormat(whaa);
        out.close();

        BinaryDeserializer bd(binPath);
        auto nuwut = bd.deserialize<txtToBin::wut>();
        
        cout << HumonFormat(nuwut) << "\n\n";

        return 0;
    }

    return 1;
}

string get_current_dir()
{
   char buff[FILENAME_MAX];
   getcwd(buff, FILENAME_MAX);
   return string(buff);
}

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    string path = get_current_dir();

    int ret = 0;
    ret = testEnums();
    if (ret)
        { return ret; }

    ret = testWut(path);
    if (ret)
        { return ret; }
    
    ret = testPrintingWut(path);
    if (ret)
        { return ret; }
    
    ret = testBinaryWut(path);
    if (ret)
        { return ret; }

    return 0;
}
