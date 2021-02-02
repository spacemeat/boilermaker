#include "txtToBin/inc/boma/txtToBin-boma.hpp"
#include <iostream>

int main(int argc, char ** argv)
{
    (void) argc;
    (void) argv;

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
