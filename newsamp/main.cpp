#include "txtToBin/inc/boma/txtToBin.hpp"
#include <iostream>
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
        cout << "Got value: '" << ev << "'.\n";
        ev = (VkSparseImageFormatFlagBits) ((int) ev + VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT - VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT);
        cout << "Mod value: '" << ev << "'.\n";
        auto ev2 = t->root() / "bar" % hu::val<VkSystemAllocationScope>();
        cout << "Got value: '" << ev2 << "'.\n";
        auto ev3 = t->root() / "baz" % hu::val<VkSparseImageFormatFlagBits>();
        cout << "Got value: '" << ev3 << "'.\n";
    }

    return 0;
}


int testWut(string_view dir)
{
    string path = string(dir) + string("/newsamp/wut.hu");
    cout << "path = " << path << endl;
    auto res = hu::Trove::fromFile(path);
    if (auto t = get_if<hu::Trove>(&res))
    {
        auto whaa = t->root() / "whaa" % hu::val<txtToBin::wut> {};
        auto & huh = whaa.get_huh();
        auto & opt = huh[0][0];
        auto & p = get<0>(*opt);
        cout << "pair: " << p.first << "; " << p.second << endl;
        opt = huh[0][1];
        auto & tu = get<1>(*opt);
        cout << "tuple: " << get<0>(tu) << "; " << get<1>(tu) << "; " << get<2>(tu) << endl;
        opt = huh[0][2];
        auto & ma0 = get<2>(*opt);
        for (auto const & [k, v] : ma0)
        {
            cout << "map entry: " << k << ": " << v << endl;
        }
        opt = huh[0][3];
        auto & ma1 = get<3>(*opt);
        for (auto const & [k, v] : ma1)
        {
            cout << "unordered_map entry: " << k << ": " << v << endl;
        }

        opt = huh[1][0];
        auto & se = get<4>(*opt);
        for (auto const & e : se)
        {
            for (auto const & [k, v]: e)
            {
                cout << "set->umap entry: " << k << ": " << v << endl;
            }
        }

        opt = huh[1][1];
        auto & use = get<5>(*opt);
        for (auto const & e : use)
        {
            cout << "unordered_set entry: " << e << endl;
        }


        opt = huh[1][2];
        auto & som = get<6>(*opt);
        for (auto const & e : som)
        {
            for (auto const & [k, v]: e)
            {
                cout << "set->map entry: " << k << ": " << v << endl;
            }
        }
    }

    return 0;
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

    int ret;
    ret = testEnums();
    if (ret)
        { return ret; }

    ret = testWut(path);
    if (ret)
        { return ret; }
    return 0;
}
