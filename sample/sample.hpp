#pragma once

#define ENUM enum

namespace og
{
    ENUM VkComponentSwizzle
    {
        IDENTITY = 0,
        ZERO = 1,
        ONE = 2, 
        R = 3,
        G = 4,
        B = 5,
        A = 6
    };

    ENUM class VkImageAspectFlagBits
    {
        COLOR = 0,
        DEPTH,
        STENCIL
    };

    ENUM class VkSurfaceTransform : int
    {
        IDENTITY,
        ROTATE90,
        ROTATE180,
        ROTATE270
    };

    typedef ENUM VkCompositeAlpha_tag
    {
        OPAQUE,
        PREMULTIPLIED,
        POSTMULTIPLIED,
        INHERIT
    } VkCompositeAlpha;


    typedef ENUM class VkPresentModeKHR_tag
    {
        IMMEDIATE,
        MAILBOX,
        FIFO
    } VkPresentModeKHR;


    typedef ENUM class VkFormat_tag
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkFormat;


    typedef ENUM class VkColorSpaceKHR_tag
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkColorSpaceKHR;

    typedef ENUM class VkSurfaceTransformFlagBitsKHR_tag
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkSurfaceTransformFlagBitsKHR;
    
    typedef ENUM class VkCompositeAlphaFlagBitsKHR_tag
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkCompositeAlphaFlagBitsKHR;
    

    typedef ENUM class VkImageViewType_tag
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkImageViewType;
    
}
