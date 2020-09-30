#pragma once

#define ENUM enum

namespace og
{
    ENUM VkComponentSwizzle
    {
        VK_COMPONENT_SWIZZLE_IDENTITY = 0,
        VK_COMPONENT_SWIZZLE_ZERO = 1,
        VK_COMPONENT_SWIZZLE_ONE = 2, 
        VK_COMPONENT_SWIZZLE_R = 3,
        VK_COMPONENT_SWIZZLE_G = 4,
        VK_COMPONENT_SWIZZLE_B = 5,
        VK_COMPONENT_SWIZZLE_A = 6
    };

    ENUM class VkImageAspectFlagBits
    {
        VK_IMAGE_ASPECT_COLOR_BIT = 1,
        VK_IMAGE_ASPECT_DEPTH_BIT = 2,
        VK_IMAGE_ASPECT_STENCIL_BIT = 4
    };


    typedef ENUM class VkPresentModeKHR_tag
    {
        VK_PRESENT_MODE_IMMEDIATE_KHR,
        VK_PRESENT_MODE_MAILBOX_KHR,
        VK_PRESENT_MODE_FIFO_KHR
    } VkPresentModeKHR;


    typedef ENUM class VkFormat_tag : int
    {
        VK_FORMAT_UNDEFINED,
        VK_FORMAT_R8_UNORM,
        VK_FORMAT_R8G8B8_UNORM
    } VkFormat;


    typedef ENUM class VkColorSpaceKHR_tag
    {
        VK_COLOR_SPACE_SRGB_NONLINEAR_KHR,
        VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT
    } VkColorSpaceKHR;

    typedef ENUM class VkSurfaceTransformFlagBitsKHR_tag
    {
        VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR,
        VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR,
        VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR,
        VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR
    } VkSurfaceTransformFlagBitsKHR;
    
    typedef ENUM class VkCompositeAlphaFlagBitsKHR_tag
    {
        VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR,
        VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR,
        VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR,
        VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR
    } VkCompositeAlphaFlagBitsKHR;
    

    typedef ENUM class VkImageViewType_tag
    {
        VK_IMAGE_VIEW_TYPE_1D,
        VK_IMAGE_VIEW_TYPE_2D,
        VK_IMAGE_VIEW_TYPE_3D,
        VK_IMAGE_VIEW_TYPE_CUBE
    } VkImageViewType;
    
}
