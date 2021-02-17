#include "txtToBin/inc/boma/txtToBin.hpp"
#include <iostream>
#include <unistd.h>

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
    if (auto t = std::get_if<hu::Trove>(&res))
    {
        auto ev = t->root() / "foo" % hu::val<::VkSparseImageFormatFlagBits>();
        std::cout << "Got value: '" << ev << "'.\n";
        ev = (VkSparseImageFormatFlagBits) ((int) ev + VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT - VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT);
        std::cout << "Mod value: '" << ev << "'.\n";
        auto ev2 = t->root() / "bar" % hu::val<::VkSystemAllocationScope>();
        std::cout << "Got value: '" << ev2 << "'.\n";
        auto ev3 = t->root() / "baz" % hu::val<::VkSparseImageFormatFlagBits>();
        std::cout << "Got value: '" << ev3 << "'.\n";
    }

    return 0;
}


int testWut(std::string_view dir)
{
    std::string path = std::string(dir) + std::string("/newsamp/wut.hu");
    std::cout << "path = " << path << std::endl;
    auto res = hu::Trove::fromFile(path);
    if (auto t = std::get_if<hu::Trove>(&res))
    {
        auto whaa = t->root() / "whaa" % hu::val<txtToBin::wut> {};
        auto & huh = whaa.get_huh();
        auto & opt = huh[0][0];
        auto & p = std::get<0>(*opt);
        std::cout << "pair: " << p.first << "; " << p.second << std::endl;
        opt = huh[0][1];
        auto & tu = std::get<1>(*opt);
        std::cout << "tuple: " << std::get<0>(tu) << "; " << std::get<1>(tu) << "; " << std::get<2>(tu) << std::endl;
        opt = huh[0][2];
        auto & ma0 = std::get<2>(*opt);
        for (auto const & [k, v] : ma0)
        {
            std::cout << "map entry: " << k << ": " << v << std::endl;
        }
        opt = huh[0][3];
        auto & ma1 = std::get<3>(*opt);
        for (auto const & [k, v] : ma1)
        {
            std::cout << "unordered_map entry: " << k << ": " << v << std::endl;
        }

        opt = huh[1][0];
        auto & se = std::get<4>(*opt);
        for (auto const & e : se)
        {
            for (auto const & [k, v]: e)
            {
                std::cout << "set->map entry: " << k << ": " << v << std::endl;
            }
        }

        opt = huh[1][1];
        auto & use = std::get<5>(*opt);
        for (auto const & e : use)
        {
            std::cout << "unordered_set entry: " << e << std::endl;
        }
    }

    return 0;
}

std::string get_current_dir()
{
   char buff[FILENAME_MAX];
   getcwd(buff, FILENAME_MAX);
   return std::string(buff);
}

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

    std::string path = get_current_dir();

    int ret;
    ret = testEnums();
    if (ret)
        { return ret; }

    ret = testWut(path);
    if (ret)
        { return ret; }
    return 0;
}
