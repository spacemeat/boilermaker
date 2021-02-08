#pragma once
/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <humon/humon.hpp>
#include <vulkan/vulkan.h>
    
namespace hu
{

    template <>
    struct val<::VkResult>
    {
        static inline ::VkResult extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkStructureType>
    {
        static inline ::VkStructureType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageLayout>
    {
        static inline ::VkImageLayout extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkObjectType>
    {
        static inline ::VkObjectType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkVendorId>
    {
        static inline ::VkVendorId extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineCacheHeaderVersion>
    {
        static inline ::VkPipelineCacheHeaderVersion extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSystemAllocationScope>
    {
        static inline ::VkSystemAllocationScope extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkInternalAllocationType>
    {
        static inline ::VkInternalAllocationType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFormat>
    {
        static inline ::VkFormat extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageTiling>
    {
        static inline ::VkImageTiling extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageType>
    {
        static inline ::VkImageType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPhysicalDeviceType>
    {
        static inline ::VkPhysicalDeviceType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueryType>
    {
        static inline ::VkQueryType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSharingMode>
    {
        static inline ::VkSharingMode extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkComponentSwizzle>
    {
        static inline ::VkComponentSwizzle extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageViewType>
    {
        static inline ::VkImageViewType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBlendFactor>
    {
        static inline ::VkBlendFactor extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBlendOp>
    {
        static inline ::VkBlendOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCompareOp>
    {
        static inline ::VkCompareOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDynamicState>
    {
        static inline ::VkDynamicState extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFrontFace>
    {
        static inline ::VkFrontFace extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkVertexInputRate>
    {
        static inline ::VkVertexInputRate extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPrimitiveTopology>
    {
        static inline ::VkPrimitiveTopology extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPolygonMode>
    {
        static inline ::VkPolygonMode extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkStencilOp>
    {
        static inline ::VkStencilOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkLogicOp>
    {
        static inline ::VkLogicOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBorderColor>
    {
        static inline ::VkBorderColor extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFilter>
    {
        static inline ::VkFilter extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerAddressMode>
    {
        static inline ::VkSamplerAddressMode extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerMipmapMode>
    {
        static inline ::VkSamplerMipmapMode extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDescriptorType>
    {
        static inline ::VkDescriptorType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAttachmentLoadOp>
    {
        static inline ::VkAttachmentLoadOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAttachmentStoreOp>
    {
        static inline ::VkAttachmentStoreOp extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineBindPoint>
    {
        static inline ::VkPipelineBindPoint extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCommandBufferLevel>
    {
        static inline ::VkCommandBufferLevel extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkIndexType>
    {
        static inline ::VkIndexType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSubpassContents>
    {
        static inline ::VkSubpassContents extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccessFlagBits>
    {
        static inline ::VkAccessFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageAspectFlagBits>
    {
        static inline ::VkImageAspectFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFormatFeatureFlagBits>
    {
        static inline ::VkFormatFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageCreateFlagBits>
    {
        static inline ::VkImageCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSampleCountFlagBits>
    {
        static inline ::VkSampleCountFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageUsageFlagBits>
    {
        static inline ::VkImageUsageFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkMemoryHeapFlagBits>
    {
        static inline ::VkMemoryHeapFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkMemoryPropertyFlagBits>
    {
        static inline ::VkMemoryPropertyFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueueFlagBits>
    {
        static inline ::VkQueueFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDeviceQueueCreateFlagBits>
    {
        static inline ::VkDeviceQueueCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineStageFlagBits>
    {
        static inline ::VkPipelineStageFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSparseMemoryBindFlagBits>
    {
        static inline ::VkSparseMemoryBindFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSparseImageFormatFlagBits>
    {
        static inline ::VkSparseImageFormatFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFenceCreateFlagBits>
    {
        static inline ::VkFenceCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueryPipelineStatisticFlagBits>
    {
        static inline ::VkQueryPipelineStatisticFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueryResultFlagBits>
    {
        static inline ::VkQueryResultFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBufferCreateFlagBits>
    {
        static inline ::VkBufferCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBufferUsageFlagBits>
    {
        static inline ::VkBufferUsageFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkImageViewCreateFlagBits>
    {
        static inline ::VkImageViewCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderModuleCreateFlagBits>
    {
        static inline ::VkShaderModuleCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineCacheCreateFlagBits>
    {
        static inline ::VkPipelineCacheCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkColorComponentFlagBits>
    {
        static inline ::VkColorComponentFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineCreateFlagBits>
    {
        static inline ::VkPipelineCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineShaderStageCreateFlagBits>
    {
        static inline ::VkPipelineShaderStageCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderStageFlagBits>
    {
        static inline ::VkShaderStageFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCullModeFlagBits>
    {
        static inline ::VkCullModeFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerCreateFlagBits>
    {
        static inline ::VkSamplerCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDescriptorPoolCreateFlagBits>
    {
        static inline ::VkDescriptorPoolCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDescriptorSetLayoutCreateFlagBits>
    {
        static inline ::VkDescriptorSetLayoutCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAttachmentDescriptionFlagBits>
    {
        static inline ::VkAttachmentDescriptionFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDependencyFlagBits>
    {
        static inline ::VkDependencyFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFramebufferCreateFlagBits>
    {
        static inline ::VkFramebufferCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkRenderPassCreateFlagBits>
    {
        static inline ::VkRenderPassCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSubpassDescriptionFlagBits>
    {
        static inline ::VkSubpassDescriptionFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCommandPoolCreateFlagBits>
    {
        static inline ::VkCommandPoolCreateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCommandPoolResetFlagBits>
    {
        static inline ::VkCommandPoolResetFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCommandBufferUsageFlagBits>
    {
        static inline ::VkCommandBufferUsageFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueryControlFlagBits>
    {
        static inline ::VkQueryControlFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCommandBufferResetFlagBits>
    {
        static inline ::VkCommandBufferResetFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkStencilFaceFlagBits>
    {
        static inline ::VkStencilFaceFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPointClippingBehavior>
    {
        static inline ::VkPointClippingBehavior extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkTessellationDomainOrigin>
    {
        static inline ::VkTessellationDomainOrigin extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerYcbcrModelConversion>
    {
        static inline ::VkSamplerYcbcrModelConversion extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerYcbcrRange>
    {
        static inline ::VkSamplerYcbcrRange extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkChromaLocation>
    {
        static inline ::VkChromaLocation extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDescriptorUpdateTemplateType>
    {
        static inline ::VkDescriptorUpdateTemplateType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSubgroupFeatureFlagBits>
    {
        static inline ::VkSubgroupFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPeerMemoryFeatureFlagBits>
    {
        static inline ::VkPeerMemoryFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkMemoryAllocateFlagBits>
    {
        static inline ::VkMemoryAllocateFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalMemoryHandleTypeFlagBits>
    {
        static inline ::VkExternalMemoryHandleTypeFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalMemoryFeatureFlagBits>
    {
        static inline ::VkExternalMemoryFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalFenceHandleTypeFlagBits>
    {
        static inline ::VkExternalFenceHandleTypeFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalFenceFeatureFlagBits>
    {
        static inline ::VkExternalFenceFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFenceImportFlagBits>
    {
        static inline ::VkFenceImportFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSemaphoreImportFlagBits>
    {
        static inline ::VkSemaphoreImportFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalSemaphoreHandleTypeFlagBits>
    {
        static inline ::VkExternalSemaphoreHandleTypeFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalSemaphoreFeatureFlagBits>
    {
        static inline ::VkExternalSemaphoreFeatureFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDriverId>
    {
        static inline ::VkDriverId extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderFloatControlsIndependence>
    {
        static inline ::VkShaderFloatControlsIndependence extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSamplerReductionMode>
    {
        static inline ::VkSamplerReductionMode extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSemaphoreType>
    {
        static inline ::VkSemaphoreType extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkResolveModeFlagBits>
    {
        static inline ::VkResolveModeFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDescriptorBindingFlagBits>
    {
        static inline ::VkDescriptorBindingFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSemaphoreWaitFlagBits>
    {
        static inline ::VkSemaphoreWaitFlagBits extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPresentModeKHR>
    {
        static inline ::VkPresentModeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkColorSpaceKHR>
    {
        static inline ::VkColorSpaceKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSurfaceTransformFlagBitsKHR>
    {
        static inline ::VkSurfaceTransformFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCompositeAlphaFlagBitsKHR>
    {
        static inline ::VkCompositeAlphaFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSwapchainCreateFlagBitsKHR>
    {
        static inline ::VkSwapchainCreateFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDeviceGroupPresentModeFlagBitsKHR>
    {
        static inline ::VkDeviceGroupPresentModeFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDisplayPlaneAlphaFlagBitsKHR>
    {
        static inline ::VkDisplayPlaneAlphaFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceCounterUnitKHR>
    {
        static inline ::VkPerformanceCounterUnitKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceCounterScopeKHR>
    {
        static inline ::VkPerformanceCounterScopeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceCounterStorageKHR>
    {
        static inline ::VkPerformanceCounterStorageKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceCounterDescriptionFlagBitsKHR>
    {
        static inline ::VkPerformanceCounterDescriptionFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAcquireProfilingLockFlagBitsKHR>
    {
        static inline ::VkAcquireProfilingLockFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFragmentShadingRateCombinerOpKHR>
    {
        static inline ::VkFragmentShadingRateCombinerOpKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineExecutableStatisticFormatKHR>
    {
        static inline ::VkPipelineExecutableStatisticFormatKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDebugReportObjectTypeEXT>
    {
        static inline ::VkDebugReportObjectTypeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDebugReportFlagBitsEXT>
    {
        static inline ::VkDebugReportFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkRasterizationOrderAMD>
    {
        static inline ::VkRasterizationOrderAMD extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderInfoTypeAMD>
    {
        static inline ::VkShaderInfoTypeAMD extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalMemoryHandleTypeFlagBitsNV>
    {
        static inline ::VkExternalMemoryHandleTypeFlagBitsNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkExternalMemoryFeatureFlagBitsNV>
    {
        static inline ::VkExternalMemoryFeatureFlagBitsNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkValidationCheckEXT>
    {
        static inline ::VkValidationCheckEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkConditionalRenderingFlagBitsEXT>
    {
        static inline ::VkConditionalRenderingFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkSurfaceCounterFlagBitsEXT>
    {
        static inline ::VkSurfaceCounterFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDisplayPowerStateEXT>
    {
        static inline ::VkDisplayPowerStateEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDeviceEventTypeEXT>
    {
        static inline ::VkDeviceEventTypeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDisplayEventTypeEXT>
    {
        static inline ::VkDisplayEventTypeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkViewportCoordinateSwizzleNV>
    {
        static inline ::VkViewportCoordinateSwizzleNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDiscardRectangleModeEXT>
    {
        static inline ::VkDiscardRectangleModeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkConservativeRasterizationModeEXT>
    {
        static inline ::VkConservativeRasterizationModeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDebugUtilsMessageSeverityFlagBitsEXT>
    {
        static inline ::VkDebugUtilsMessageSeverityFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDebugUtilsMessageTypeFlagBitsEXT>
    {
        static inline ::VkDebugUtilsMessageTypeFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBlendOverlapEXT>
    {
        static inline ::VkBlendOverlapEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCoverageModulationModeNV>
    {
        static inline ::VkCoverageModulationModeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkValidationCacheHeaderVersionEXT>
    {
        static inline ::VkValidationCacheHeaderVersionEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShadingRatePaletteEntryNV>
    {
        static inline ::VkShadingRatePaletteEntryNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCoarseSampleOrderTypeNV>
    {
        static inline ::VkCoarseSampleOrderTypeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkRayTracingShaderGroupTypeKHR>
    {
        static inline ::VkRayTracingShaderGroupTypeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkGeometryTypeKHR>
    {
        static inline ::VkGeometryTypeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccelerationStructureTypeKHR>
    {
        static inline ::VkAccelerationStructureTypeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCopyAccelerationStructureModeKHR>
    {
        static inline ::VkCopyAccelerationStructureModeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccelerationStructureMemoryRequirementsTypeNV>
    {
        static inline ::VkAccelerationStructureMemoryRequirementsTypeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkGeometryFlagBitsKHR>
    {
        static inline ::VkGeometryFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkGeometryInstanceFlagBitsKHR>
    {
        static inline ::VkGeometryInstanceFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBuildAccelerationStructureFlagBitsKHR>
    {
        static inline ::VkBuildAccelerationStructureFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueueGlobalPriorityEXT>
    {
        static inline ::VkQueueGlobalPriorityEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineCompilerControlFlagBitsAMD>
    {
        static inline ::VkPipelineCompilerControlFlagBitsAMD extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkTimeDomainEXT>
    {
        static inline ::VkTimeDomainEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkMemoryOverallocationBehaviorAMD>
    {
        static inline ::VkMemoryOverallocationBehaviorAMD extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPipelineCreationFeedbackFlagBitsEXT>
    {
        static inline ::VkPipelineCreationFeedbackFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceConfigurationTypeINTEL>
    {
        static inline ::VkPerformanceConfigurationTypeINTEL extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkQueryPoolSamplingModeINTEL>
    {
        static inline ::VkQueryPoolSamplingModeINTEL extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceOverrideTypeINTEL>
    {
        static inline ::VkPerformanceOverrideTypeINTEL extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceParameterTypeINTEL>
    {
        static inline ::VkPerformanceParameterTypeINTEL extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPerformanceValueTypeINTEL>
    {
        static inline ::VkPerformanceValueTypeINTEL extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderCorePropertiesFlagBitsAMD>
    {
        static inline ::VkShaderCorePropertiesFlagBitsAMD extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkToolPurposeFlagBitsEXT>
    {
        static inline ::VkToolPurposeFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkValidationFeatureEnableEXT>
    {
        static inline ::VkValidationFeatureEnableEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkValidationFeatureDisableEXT>
    {
        static inline ::VkValidationFeatureDisableEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkComponentTypeNV>
    {
        static inline ::VkComponentTypeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkScopeNV>
    {
        static inline ::VkScopeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkCoverageReductionModeNV>
    {
        static inline ::VkCoverageReductionModeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkLineRasterizationModeEXT>
    {
        static inline ::VkLineRasterizationModeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkIndirectCommandsTokenTypeNV>
    {
        static inline ::VkIndirectCommandsTokenTypeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkIndirectStateFlagBitsNV>
    {
        static inline ::VkIndirectStateFlagBitsNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkIndirectCommandsLayoutUsageFlagBitsNV>
    {
        static inline ::VkIndirectCommandsLayoutUsageFlagBitsNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDeviceMemoryReportEventTypeEXT>
    {
        static inline ::VkDeviceMemoryReportEventTypeEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkPrivateDataSlotCreateFlagBitsEXT>
    {
        static inline ::VkPrivateDataSlotCreateFlagBitsEXT extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkDeviceDiagnosticsConfigFlagBitsNV>
    {
        static inline ::VkDeviceDiagnosticsConfigFlagBitsNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFragmentShadingRateTypeNV>
    {
        static inline ::VkFragmentShadingRateTypeNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkFragmentShadingRateNV>
    {
        static inline ::VkFragmentShadingRateNV extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkBuildAccelerationStructureModeKHR>
    {
        static inline ::VkBuildAccelerationStructureModeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccelerationStructureBuildTypeKHR>
    {
        static inline ::VkAccelerationStructureBuildTypeKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccelerationStructureCompatibilityKHR>
    {
        static inline ::VkAccelerationStructureCompatibilityKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkAccelerationStructureCreateFlagBitsKHR>
    {
        static inline ::VkAccelerationStructureCreateFlagBitsKHR extract(hu::Node node) noexcept;
    };

    template <>
    struct val<::VkShaderGroupShaderKHR>
    {
        static inline ::VkShaderGroupShaderKHR extract(hu::Node node) noexcept;
    };
}


namespace txtToBin
{
    inline std::ostream & operator <<(std::ostream & out, ::VkResult obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkStructureType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageLayout obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkObjectType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkVendorId obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineCacheHeaderVersion obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSystemAllocationScope obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkInternalAllocationType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFormat obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageTiling obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPhysicalDeviceType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueryType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSharingMode obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkComponentSwizzle obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageViewType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBlendFactor obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBlendOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCompareOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDynamicState obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFrontFace obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkVertexInputRate obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPrimitiveTopology obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPolygonMode obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkStencilOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkLogicOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBorderColor obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFilter obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerAddressMode obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerMipmapMode obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDescriptorType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAttachmentLoadOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAttachmentStoreOp obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineBindPoint obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCommandBufferLevel obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkIndexType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSubpassContents obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccessFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageAspectFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFormatFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSampleCountFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageUsageFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkMemoryHeapFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkMemoryPropertyFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueueFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDeviceQueueCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineStageFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSparseMemoryBindFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSparseImageFormatFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFenceCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueryPipelineStatisticFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueryResultFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBufferCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBufferUsageFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkImageViewCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderModuleCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineCacheCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkColorComponentFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineShaderStageCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderStageFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCullModeFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDescriptorPoolCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDescriptorSetLayoutCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAttachmentDescriptionFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDependencyFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFramebufferCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkRenderPassCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSubpassDescriptionFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCommandPoolCreateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCommandPoolResetFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCommandBufferUsageFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueryControlFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCommandBufferResetFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkStencilFaceFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPointClippingBehavior obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkTessellationDomainOrigin obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerYcbcrModelConversion obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerYcbcrRange obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkChromaLocation obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDescriptorUpdateTemplateType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSubgroupFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPeerMemoryFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkMemoryAllocateFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryHandleTypeFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalFenceHandleTypeFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalFenceFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFenceImportFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSemaphoreImportFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalSemaphoreHandleTypeFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalSemaphoreFeatureFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDriverId obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderFloatControlsIndependence obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSamplerReductionMode obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSemaphoreType obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkResolveModeFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDescriptorBindingFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSemaphoreWaitFlagBits obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPresentModeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkColorSpaceKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSurfaceTransformFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCompositeAlphaFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSwapchainCreateFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDeviceGroupPresentModeFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDisplayPlaneAlphaFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterUnitKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterScopeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterStorageKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterDescriptionFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAcquireProfilingLockFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateCombinerOpKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineExecutableStatisticFormatKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDebugReportObjectTypeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDebugReportFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkRasterizationOrderAMD obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderInfoTypeAMD obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryHandleTypeFlagBitsNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryFeatureFlagBitsNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkValidationCheckEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkConditionalRenderingFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkSurfaceCounterFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDisplayPowerStateEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDeviceEventTypeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDisplayEventTypeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkViewportCoordinateSwizzleNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDiscardRectangleModeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkConservativeRasterizationModeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDebugUtilsMessageSeverityFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDebugUtilsMessageTypeFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBlendOverlapEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCoverageModulationModeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkValidationCacheHeaderVersionEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShadingRatePaletteEntryNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCoarseSampleOrderTypeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkRayTracingShaderGroupTypeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkGeometryTypeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureTypeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCopyAccelerationStructureModeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureMemoryRequirementsTypeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkGeometryFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkGeometryInstanceFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBuildAccelerationStructureFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueueGlobalPriorityEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineCompilerControlFlagBitsAMD obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkTimeDomainEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkMemoryOverallocationBehaviorAMD obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPipelineCreationFeedbackFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceConfigurationTypeINTEL obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkQueryPoolSamplingModeINTEL obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceOverrideTypeINTEL obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceParameterTypeINTEL obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPerformanceValueTypeINTEL obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderCorePropertiesFlagBitsAMD obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkToolPurposeFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkValidationFeatureEnableEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkValidationFeatureDisableEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkComponentTypeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkScopeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkCoverageReductionModeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkLineRasterizationModeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkIndirectCommandsTokenTypeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkIndirectStateFlagBitsNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkIndirectCommandsLayoutUsageFlagBitsNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDeviceMemoryReportEventTypeEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkPrivateDataSlotCreateFlagBitsEXT obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkDeviceDiagnosticsConfigFlagBitsNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateTypeNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateNV obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkBuildAccelerationStructureModeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureBuildTypeKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureCompatibilityKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureCreateFlagBitsKHR obj);
    inline std::ostream & operator <<(std::ostream & out, ::VkShaderGroupShaderKHR obj);
}

#include "inl/enums.inl.hpp"