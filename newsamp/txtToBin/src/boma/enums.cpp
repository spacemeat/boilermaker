/*  THIS IS A GENERATED FILE. It is a Boilermaker artifact.
    Do not bother modifying this file, as your build process will overwrite
    your changes. */

#include <iostream>
#include "../../inc/boma/enums.hpp"

namespace txtToBin
{


    std::ostream & operator <<(std::ostream & out, ::VkResult obj)
    {
        using enumIntType = std::underlying_type<::VkResult>::type;
        switch (obj)
        {
        case ::VK_SUCCESS: out << "success"; break;
        case ::VK_NOT_READY: out << "not_ready"; break;
        case ::VK_TIMEOUT: out << "timeout"; break;
        case ::VK_EVENT_SET: out << "event_set"; break;
        case ::VK_EVENT_RESET: out << "event_reset"; break;
        case ::VK_INCOMPLETE: out << "incomplete"; break;
        case ::VK_ERROR_OUT_OF_HOST_MEMORY: out << "error_out_of_host_memory"; break;
        case ::VK_ERROR_OUT_OF_DEVICE_MEMORY: out << "error_out_of_device_memory"; break;
        case ::VK_ERROR_INITIALIZATION_FAILED: out << "error_initialization_failed"; break;
        case ::VK_ERROR_DEVICE_LOST: out << "error_device_lost"; break;
        case ::VK_ERROR_MEMORY_MAP_FAILED: out << "error_memory_map_failed"; break;
        case ::VK_ERROR_LAYER_NOT_PRESENT: out << "error_layer_not_present"; break;
        case ::VK_ERROR_EXTENSION_NOT_PRESENT: out << "error_extension_not_present"; break;
        case ::VK_ERROR_FEATURE_NOT_PRESENT: out << "error_feature_not_present"; break;
        case ::VK_ERROR_INCOMPATIBLE_DRIVER: out << "error_incompatible_driver"; break;
        case ::VK_ERROR_TOO_MANY_OBJECTS: out << "error_too_many_objects"; break;
        case ::VK_ERROR_FORMAT_NOT_SUPPORTED: out << "error_format_not_supported"; break;
        case ::VK_ERROR_FRAGMENTED_POOL: out << "error_fragmented_pool"; break;
        case ::VK_ERROR_UNKNOWN: out << "error_unknown"; break;
        case ::VK_ERROR_OUT_OF_POOL_MEMORY: out << "error_out_of_pool_memory"; break;
        case ::VK_ERROR_INVALID_EXTERNAL_HANDLE: out << "error_invalid_external_handle"; break;
        case ::VK_ERROR_FRAGMENTATION: out << "error_fragmentation"; break;
        case ::VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS: out << "error_invalid_opaque_capture_address"; break;
        case ::VK_ERROR_SURFACE_LOST_KHR: out << "error_surface_lost_khr"; break;
        case ::VK_ERROR_NATIVE_WINDOW_IN_USE_KHR: out << "error_native_window_in_use_khr"; break;
        case ::VK_SUBOPTIMAL_KHR: out << "suboptimal_khr"; break;
        case ::VK_ERROR_OUT_OF_DATE_KHR: out << "error_out_of_date_khr"; break;
        case ::VK_ERROR_INCOMPATIBLE_DISPLAY_KHR: out << "error_incompatible_display_khr"; break;
        case ::VK_ERROR_VALIDATION_FAILED_EXT: out << "error_validation_failed_ext"; break;
        case ::VK_ERROR_INVALID_SHADER_NV: out << "error_invalid_shader_nv"; break;
        case ::VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT: out << "error_invalid_drm_format_modifier_plane_layout_ext"; break;
        case ::VK_ERROR_NOT_PERMITTED_EXT: out << "error_not_permitted_ext"; break;
        case ::VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT: out << "error_full_screen_exclusive_mode_lost_ext"; break;
        case ::VK_THREAD_IDLE_KHR: out << "thread_idle_khr"; break;
        case ::VK_THREAD_DONE_KHR: out << "thread_done_khr"; break;
        case ::VK_OPERATION_DEFERRED_KHR: out << "operation_deferred_khr"; break;
        case ::VK_OPERATION_NOT_DEFERRED_KHR: out << "operation_not_deferred_khr"; break;
        case ::VK_PIPELINE_COMPILE_REQUIRED_EXT: out << "pipeline_compile_required_ext"; break;
        case ::VK_RESULT_MAX_ENUM: out << "result_max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkStructureType obj)
    {
        using enumIntType = std::underlying_type<::VkStructureType>::type;
        switch (obj)
        {
        case ::VK_STRUCTURE_TYPE_APPLICATION_INFO: out << "application_info"; break;
        case ::VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO: out << "instance_create_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO: out << "device_queue_create_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO: out << "device_create_info"; break;
        case ::VK_STRUCTURE_TYPE_SUBMIT_INFO: out << "submit_info"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO: out << "memory_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE: out << "mapped_memory_range"; break;
        case ::VK_STRUCTURE_TYPE_BIND_SPARSE_INFO: out << "bind_sparse_info"; break;
        case ::VK_STRUCTURE_TYPE_FENCE_CREATE_INFO: out << "fence_create_info"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO: out << "semaphore_create_info"; break;
        case ::VK_STRUCTURE_TYPE_EVENT_CREATE_INFO: out << "event_create_info"; break;
        case ::VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO: out << "query_pool_create_info"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO: out << "buffer_create_info"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO: out << "buffer_view_create_info"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO: out << "image_create_info"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO: out << "image_view_create_info"; break;
        case ::VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO: out << "shader_module_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO: out << "pipeline_cache_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO: out << "pipeline_shader_stage_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO: out << "pipeline_vertex_input_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO: out << "pipeline_input_assembly_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO: out << "pipeline_tessellation_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO: out << "pipeline_viewport_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO: out << "pipeline_rasterization_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO: out << "pipeline_multisample_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO: out << "pipeline_depth_stencil_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO: out << "pipeline_color_blend_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO: out << "pipeline_dynamic_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO: out << "graphics_pipeline_create_info"; break;
        case ::VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO: out << "compute_pipeline_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO: out << "pipeline_layout_create_info"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO: out << "sampler_create_info"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO: out << "descriptor_set_layout_create_info"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO: out << "descriptor_pool_create_info"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO: out << "descriptor_set_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET: out << "write_descriptor_set"; break;
        case ::VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET: out << "copy_descriptor_set"; break;
        case ::VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO: out << "framebuffer_create_info"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO: out << "render_pass_create_info"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO: out << "command_pool_create_info"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO: out << "command_buffer_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO: out << "command_buffer_inheritance_info"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO: out << "command_buffer_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO: out << "render_pass_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER: out << "buffer_memory_barrier"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER: out << "image_memory_barrier"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_BARRIER: out << "memory_barrier"; break;
        case ::VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO: out << "loader_instance_create_info"; break;
        case ::VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO: out << "loader_device_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES: out << "physical_device_subgroup_properties"; break;
        case ::VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO: out << "bind_buffer_memory_info"; break;
        case ::VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO: out << "bind_image_memory_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES: out << "physical_device_16bit_storage_features"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS: out << "memory_dedicated_requirements"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO: out << "memory_dedicated_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO: out << "memory_allocate_flags_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO: out << "device_group_render_pass_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO: out << "device_group_command_buffer_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO: out << "device_group_submit_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO: out << "device_group_bind_sparse_info"; break;
        case ::VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO: out << "bind_buffer_memory_device_group_info"; break;
        case ::VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO: out << "bind_image_memory_device_group_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES: out << "physical_device_group_properties"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO: out << "device_group_device_create_info"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2: out << "buffer_memory_requirements_info_2"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2: out << "image_memory_requirements_info_2"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2: out << "image_sparse_memory_requirements_info_2"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2: out << "memory_requirements_2"; break;
        case ::VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2: out << "sparse_image_memory_requirements_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2: out << "physical_device_features_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2: out << "physical_device_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2: out << "format_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2: out << "image_format_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2: out << "physical_device_image_format_info_2"; break;
        case ::VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2: out << "queue_family_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2: out << "physical_device_memory_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2: out << "sparse_image_format_properties_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2: out << "physical_device_sparse_image_format_info_2"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES: out << "physical_device_point_clipping_properties"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO: out << "render_pass_input_attachment_aspect_create_info"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO: out << "image_view_usage_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO: out << "pipeline_tessellation_domain_origin_state_create_info"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO: out << "render_pass_multiview_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES: out << "physical_device_multiview_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES: out << "physical_device_multiview_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES: out << "physical_device_variable_pointers_features"; break;
        case ::VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO: out << "protected_submit_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES: out << "physical_device_protected_memory_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES: out << "physical_device_protected_memory_properties"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2: out << "device_queue_info_2"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO: out << "sampler_ycbcr_conversion_create_info"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO: out << "sampler_ycbcr_conversion_info"; break;
        case ::VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO: out << "bind_image_plane_memory_info"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO: out << "image_plane_memory_requirements_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES: out << "physical_device_sampler_ycbcr_conversion_features"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES: out << "sampler_ycbcr_conversion_image_format_properties"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO: out << "descriptor_update_template_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO: out << "physical_device_external_image_format_info"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES: out << "external_image_format_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO: out << "physical_device_external_buffer_info"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES: out << "external_buffer_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES: out << "physical_device_id_properties"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO: out << "external_memory_buffer_create_info"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO: out << "external_memory_image_create_info"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO: out << "export_memory_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO: out << "physical_device_external_fence_info"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES: out << "external_fence_properties"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO: out << "export_fence_create_info"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO: out << "export_semaphore_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO: out << "physical_device_external_semaphore_info"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES: out << "external_semaphore_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES: out << "physical_device_maintenance_3_properties"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT: out << "descriptor_set_layout_support"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES: out << "physical_device_shader_draw_parameters_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES: out << "physical_device_vulkan_1_1_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES: out << "physical_device_vulkan_1_1_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES: out << "physical_device_vulkan_1_2_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES: out << "physical_device_vulkan_1_2_properties"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO: out << "image_format_list_create_info"; break;
        case ::VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2: out << "attachment_description_2"; break;
        case ::VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2: out << "attachment_reference_2"; break;
        case ::VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2: out << "subpass_description_2"; break;
        case ::VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2: out << "subpass_dependency_2"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2: out << "render_pass_create_info_2"; break;
        case ::VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO: out << "subpass_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_SUBPASS_END_INFO: out << "subpass_end_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES: out << "physical_device_8bit_storage_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES: out << "physical_device_driver_properties"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES: out << "physical_device_shader_atomic_int64_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES: out << "physical_device_shader_float16_int8_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES: out << "physical_device_float_controls_properties"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO: out << "descriptor_set_layout_binding_flags_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES: out << "physical_device_descriptor_indexing_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES: out << "physical_device_descriptor_indexing_properties"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO: out << "descriptor_set_variable_descriptor_count_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT: out << "descriptor_set_variable_descriptor_count_layout_support"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES: out << "physical_device_depth_stencil_resolve_properties"; break;
        case ::VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE: out << "subpass_description_depth_stencil_resolve"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES: out << "physical_device_scalar_block_layout_features"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO: out << "image_stencil_usage_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES: out << "physical_device_sampler_filter_minmax_properties"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO: out << "sampler_reduction_mode_create_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES: out << "physical_device_vulkan_memory_model_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES: out << "physical_device_imageless_framebuffer_features"; break;
        case ::VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO: out << "framebuffer_attachments_create_info"; break;
        case ::VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO: out << "framebuffer_attachment_image_info"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO: out << "render_pass_attachment_begin_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES: out << "physical_device_uniform_buffer_standard_layout_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES: out << "physical_device_shader_subgroup_extended_types_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES: out << "physical_device_separate_depth_stencil_layouts_features"; break;
        case ::VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT: out << "attachment_reference_stencil_layout"; break;
        case ::VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT: out << "attachment_description_stencil_layout"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES: out << "physical_device_host_query_reset_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES: out << "physical_device_timeline_semaphore_features"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES: out << "physical_device_timeline_semaphore_properties"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO: out << "semaphore_type_create_info"; break;
        case ::VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO: out << "timeline_semaphore_submit_info"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO: out << "semaphore_wait_info"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO: out << "semaphore_signal_info"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES: out << "physical_device_buffer_device_address_features"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO: out << "buffer_device_address_info"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO: out << "buffer_opaque_capture_address_create_info"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO: out << "memory_opaque_capture_address_allocate_info"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO: out << "device_memory_opaque_capture_address_info"; break;
        case ::VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR: out << "swapchain_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PRESENT_INFO_KHR: out << "present_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR: out << "device_group_present_capabilities_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR: out << "image_swapchain_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR: out << "bind_image_memory_swapchain_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR: out << "acquire_next_image_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR: out << "device_group_present_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR: out << "device_group_swapchain_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR: out << "display_mode_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR: out << "display_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR: out << "display_present_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR: out << "xlib_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR: out << "xcb_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR: out << "wayland_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR: out << "android_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR: out << "win32_surface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT: out << "debug_report_callback_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD: out << "pipeline_rasterization_state_rasterization_order_amd"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT: out << "debug_marker_object_name_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT: out << "debug_marker_object_tag_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT: out << "debug_marker_marker_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV: out << "dedicated_allocation_image_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV: out << "dedicated_allocation_buffer_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV: out << "dedicated_allocation_memory_allocate_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT: out << "physical_device_transform_feedback_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT: out << "physical_device_transform_feedback_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT: out << "pipeline_rasterization_state_stream_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX: out << "image_view_handle_info_nvx"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX: out << "image_view_address_properties_nvx"; break;
        case ::VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD: out << "texture_lod_gather_format_properties_amd"; break;
        case ::VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP: out << "stream_descriptor_surface_create_info_ggp"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV: out << "physical_device_corner_sampled_image_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV: out << "external_memory_image_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV: out << "export_memory_allocate_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV: out << "import_memory_win32_handle_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV: out << "export_memory_win32_handle_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV: out << "win32_keyed_mutex_acquire_release_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT: out << "validation_flags_ext"; break;
        case ::VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN: out << "vi_surface_create_info_nn"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT: out << "physical_device_texture_compression_astc_hdr_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT: out << "image_view_astc_decode_mode_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT: out << "physical_device_astc_decode_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR: out << "import_memory_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR: out << "export_memory_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR: out << "memory_win32_handle_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR: out << "memory_get_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR: out << "import_memory_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR: out << "memory_fd_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR: out << "memory_get_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR: out << "win32_keyed_mutex_acquire_release_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: out << "import_semaphore_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR: out << "export_semaphore_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR: out << "d3d12_fence_submit_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR: out << "semaphore_get_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR: out << "import_semaphore_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR: out << "semaphore_get_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR: out << "physical_device_push_descriptor_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT: out << "command_buffer_inheritance_conditional_rendering_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT: out << "physical_device_conditional_rendering_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT: out << "conditional_rendering_begin_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR: out << "present_regions_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV: out << "pipeline_viewport_w_scaling_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT: out << "surface_capabilities_2_ext"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT: out << "display_power_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT: out << "device_event_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT: out << "display_event_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT: out << "swapchain_counter_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE: out << "present_times_info_google"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX: out << "physical_device_multiview_per_view_attributes_properties_nvx"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV: out << "pipeline_viewport_swizzle_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT: out << "physical_device_discard_rectangle_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT: out << "pipeline_discard_rectangle_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT: out << "physical_device_conservative_rasterization_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT: out << "pipeline_rasterization_conservative_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT: out << "physical_device_depth_clip_enable_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT: out << "pipeline_rasterization_depth_clip_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_HDR_METADATA_EXT: out << "hdr_metadata_ext"; break;
        case ::VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR: out << "shared_present_surface_capabilities_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR: out << "import_fence_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR: out << "export_fence_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR: out << "fence_get_win32_handle_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR: out << "import_fence_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR: out << "fence_get_fd_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR: out << "physical_device_performance_query_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR: out << "physical_device_performance_query_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR: out << "query_pool_performance_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR: out << "performance_query_submit_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR: out << "acquire_profiling_lock_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR: out << "performance_counter_khr"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR: out << "performance_counter_description_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR: out << "physical_device_surface_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR: out << "surface_capabilities_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR: out << "surface_format_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR: out << "display_properties_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR: out << "display_plane_properties_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR: out << "display_mode_properties_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR: out << "display_plane_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR: out << "display_plane_capabilities_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK: out << "ios_surface_create_info_mvk"; break;
        case ::VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK: out << "macos_surface_create_info_mvk"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT: out << "debug_utils_object_name_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT: out << "debug_utils_object_tag_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT: out << "debug_utils_label_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT: out << "debug_utils_messenger_callback_data_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT: out << "debug_utils_messenger_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID: out << "android_hardware_buffer_usage_android"; break;
        case ::VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID: out << "android_hardware_buffer_properties_android"; break;
        case ::VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID: out << "android_hardware_buffer_format_properties_android"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: out << "import_android_hardware_buffer_info_android"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID: out << "memory_get_android_hardware_buffer_info_android"; break;
        case ::VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID: out << "external_format_android"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT: out << "physical_device_inline_uniform_block_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT: out << "physical_device_inline_uniform_block_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT: out << "write_descriptor_set_inline_uniform_block_ext"; break;
        case ::VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT: out << "descriptor_pool_inline_uniform_block_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT: out << "sample_locations_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT: out << "render_pass_sample_locations_begin_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT: out << "pipeline_sample_locations_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT: out << "physical_device_sample_locations_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT: out << "multisample_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT: out << "physical_device_blend_operation_advanced_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT: out << "physical_device_blend_operation_advanced_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT: out << "pipeline_color_blend_advanced_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV: out << "pipeline_coverage_to_color_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR: out << "write_descriptor_set_acceleration_structure_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR: out << "acceleration_structure_build_geometry_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR: out << "acceleration_structure_device_address_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR: out << "acceleration_structure_geometry_aabbs_data_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR: out << "acceleration_structure_geometry_instances_data_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR: out << "acceleration_structure_geometry_triangles_data_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR: out << "acceleration_structure_geometry_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR: out << "acceleration_structure_version_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR: out << "copy_acceleration_structure_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR: out << "copy_acceleration_structure_to_memory_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR: out << "copy_memory_to_acceleration_structure_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR: out << "physical_device_acceleration_structure_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR: out << "physical_device_acceleration_structure_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR: out << "acceleration_structure_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR: out << "acceleration_structure_build_sizes_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR: out << "physical_device_ray_tracing_pipeline_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR: out << "physical_device_ray_tracing_pipeline_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR: out << "ray_tracing_pipeline_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR: out << "ray_tracing_shader_group_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR: out << "ray_tracing_pipeline_interface_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR: out << "physical_device_ray_query_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV: out << "pipeline_coverage_modulation_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV: out << "physical_device_shader_sm_builtins_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV: out << "physical_device_shader_sm_builtins_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT: out << "drm_format_modifier_properties_list_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT: out << "physical_device_image_drm_format_modifier_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT: out << "image_drm_format_modifier_list_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT: out << "image_drm_format_modifier_explicit_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT: out << "image_drm_format_modifier_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT: out << "validation_cache_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT: out << "shader_module_validation_cache_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR: out << "physical_device_portability_subset_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR: out << "physical_device_portability_subset_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV: out << "pipeline_viewport_shading_rate_image_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV: out << "physical_device_shading_rate_image_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV: out << "physical_device_shading_rate_image_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV: out << "pipeline_viewport_coarse_sample_order_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV: out << "ray_tracing_pipeline_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV: out << "acceleration_structure_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_GEOMETRY_NV: out << "geometry_nv"; break;
        case ::VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV: out << "geometry_triangles_nv"; break;
        case ::VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV: out << "geometry_aabb_nv"; break;
        case ::VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV: out << "bind_acceleration_structure_memory_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV: out << "write_descriptor_set_acceleration_structure_nv"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV: out << "acceleration_structure_memory_requirements_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV: out << "physical_device_ray_tracing_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV: out << "ray_tracing_shader_group_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV: out << "acceleration_structure_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV: out << "physical_device_representative_fragment_test_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV: out << "pipeline_representative_fragment_test_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT: out << "physical_device_image_view_image_format_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT: out << "filter_cubic_image_view_image_format_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT: out << "device_queue_global_priority_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT: out << "import_memory_host_pointer_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT: out << "memory_host_pointer_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT: out << "physical_device_external_memory_host_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR: out << "physical_device_shader_clock_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD: out << "pipeline_compiler_control_create_info_amd"; break;
        case ::VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT: out << "calibrated_timestamp_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD: out << "physical_device_shader_core_properties_amd"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD: out << "device_memory_overallocation_create_info_amd"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT: out << "physical_device_vertex_attribute_divisor_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT: out << "pipeline_vertex_input_divisor_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT: out << "physical_device_vertex_attribute_divisor_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP: out << "present_frame_token_ggp"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT: out << "pipeline_creation_feedback_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV: out << "physical_device_compute_shader_derivatives_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV: out << "physical_device_mesh_shader_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV: out << "physical_device_mesh_shader_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV: out << "physical_device_fragment_shader_barycentric_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV: out << "physical_device_shader_image_footprint_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV: out << "pipeline_viewport_exclusive_scissor_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV: out << "physical_device_exclusive_scissor_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV: out << "checkpoint_data_nv"; break;
        case ::VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV: out << "queue_family_checkpoint_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL: out << "physical_device_shader_integer_functions_2_features_intel"; break;
        case ::VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL: out << "query_pool_performance_query_create_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL: out << "initialize_performance_api_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL: out << "performance_marker_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL: out << "performance_stream_marker_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL: out << "performance_override_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL: out << "performance_configuration_acquire_info_intel"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT: out << "physical_device_pci_bus_info_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD: out << "display_native_hdr_surface_capabilities_amd"; break;
        case ::VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD: out << "swapchain_display_native_hdr_create_info_amd"; break;
        case ::VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA: out << "imagepipe_surface_create_info_fuchsia"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR: out << "physical_device_shader_terminate_invocation_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT: out << "metal_surface_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT: out << "physical_device_fragment_density_map_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT: out << "physical_device_fragment_density_map_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT: out << "render_pass_fragment_density_map_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT: out << "physical_device_subgroup_size_control_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT: out << "pipeline_shader_stage_required_subgroup_size_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT: out << "physical_device_subgroup_size_control_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR: out << "fragment_shading_rate_attachment_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR: out << "pipeline_fragment_shading_rate_state_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR: out << "physical_device_fragment_shading_rate_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR: out << "physical_device_fragment_shading_rate_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR: out << "physical_device_fragment_shading_rate_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD: out << "physical_device_shader_core_properties_2_amd"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD: out << "physical_device_coherent_memory_features_amd"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT: out << "physical_device_shader_image_atomic_int64_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT: out << "physical_device_memory_budget_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT: out << "physical_device_memory_priority_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT: out << "memory_priority_allocate_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR: out << "surface_protected_capabilities_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV: out << "physical_device_dedicated_allocation_image_aliasing_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT: out << "physical_device_buffer_device_address_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT: out << "buffer_device_address_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT: out << "physical_device_tool_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT: out << "validation_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV: out << "physical_device_cooperative_matrix_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV: out << "cooperative_matrix_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV: out << "physical_device_cooperative_matrix_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV: out << "physical_device_coverage_reduction_mode_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV: out << "pipeline_coverage_reduction_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV: out << "framebuffer_mixed_samples_combination_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT: out << "physical_device_fragment_shader_interlock_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT: out << "physical_device_ycbcr_image_arrays_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT: out << "surface_full_screen_exclusive_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT: out << "surface_capabilities_full_screen_exclusive_ext"; break;
        case ::VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT: out << "surface_full_screen_exclusive_win32_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT: out << "headless_surface_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT: out << "physical_device_line_rasterization_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT: out << "pipeline_rasterization_line_state_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT: out << "physical_device_line_rasterization_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT: out << "physical_device_shader_atomic_float_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT: out << "physical_device_index_type_uint8_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT: out << "physical_device_extended_dynamic_state_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR: out << "physical_device_pipeline_executable_properties_features_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR: out << "pipeline_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR: out << "pipeline_executable_properties_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR: out << "pipeline_executable_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR: out << "pipeline_executable_statistic_khr"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR: out << "pipeline_executable_internal_representation_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT: out << "physical_device_shader_demote_to_helper_invocation_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV: out << "physical_device_device_generated_commands_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV: out << "graphics_shader_group_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV: out << "graphics_pipeline_shader_groups_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV: out << "indirect_commands_layout_token_nv"; break;
        case ::VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV: out << "indirect_commands_layout_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV: out << "generated_commands_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV: out << "generated_commands_memory_requirements_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV: out << "physical_device_device_generated_commands_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT: out << "physical_device_texel_buffer_alignment_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT: out << "physical_device_texel_buffer_alignment_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM: out << "command_buffer_inheritance_render_pass_transform_info_qcom"; break;
        case ::VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM: out << "render_pass_transform_begin_info_qcom"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT: out << "physical_device_device_memory_report_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT: out << "device_device_memory_report_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT: out << "device_memory_report_callback_data_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT: out << "physical_device_robustness_2_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT: out << "physical_device_robustness_2_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT: out << "sampler_custom_border_color_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT: out << "physical_device_custom_border_color_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT: out << "physical_device_custom_border_color_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR: out << "pipeline_library_create_info_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT: out << "physical_device_private_data_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT: out << "device_private_data_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO_EXT: out << "private_data_slot_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT: out << "physical_device_pipeline_creation_cache_control_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV: out << "physical_device_diagnostics_config_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV: out << "device_diagnostics_config_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV: out << "physical_device_fragment_shading_rate_enums_properties_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV: out << "physical_device_fragment_shading_rate_enums_features_nv"; break;
        case ::VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV: out << "pipeline_fragment_shading_rate_enum_state_create_info_nv"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT: out << "physical_device_fragment_density_map_2_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT: out << "physical_device_fragment_density_map_2_properties_ext"; break;
        case ::VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM: out << "copy_command_transform_info_qcom"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT: out << "physical_device_image_robustness_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2_KHR: out << "copy_buffer_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2_KHR: out << "copy_image_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2_KHR: out << "copy_buffer_to_image_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2_KHR: out << "copy_image_to_buffer_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2_KHR: out << "blit_image_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2_KHR: out << "resolve_image_info_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_COPY_2_KHR: out << "buffer_copy_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_COPY_2_KHR: out << "image_copy_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_BLIT_2_KHR: out << "image_blit_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2_KHR: out << "buffer_image_copy_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2_KHR: out << "image_resolve_2_khr"; break;
        case ::VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT: out << "physical_device_4444_formats_features_ext"; break;
        case ::VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT: out << "directfb_surface_create_info_ext"; break;
        case ::VK_STRUCTURE_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageLayout obj)
    {
        using enumIntType = std::underlying_type<::VkImageLayout>::type;
        switch (obj)
        {
        case ::VK_IMAGE_LAYOUT_UNDEFINED: out << "undefined"; break;
        case ::VK_IMAGE_LAYOUT_GENERAL: out << "general"; break;
        case ::VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL: out << "color_attachment_optimal"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL: out << "depth_stencil_attachment_optimal"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL: out << "depth_stencil_read_only_optimal"; break;
        case ::VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL: out << "shader_read_only_optimal"; break;
        case ::VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL: out << "transfer_src_optimal"; break;
        case ::VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL: out << "transfer_dst_optimal"; break;
        case ::VK_IMAGE_LAYOUT_PREINITIALIZED: out << "preinitialized"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL: out << "depth_read_only_stencil_attachment_optimal"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL: out << "depth_attachment_stencil_read_only_optimal"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL: out << "depth_attachment_optimal"; break;
        case ::VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL: out << "depth_read_only_optimal"; break;
        case ::VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL: out << "stencil_attachment_optimal"; break;
        case ::VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL: out << "stencil_read_only_optimal"; break;
        case ::VK_IMAGE_LAYOUT_PRESENT_SRC_KHR: out << "present_src_khr"; break;
        case ::VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR: out << "shared_present_khr"; break;
        case ::VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV: out << "shading_rate_optimal_nv"; break;
        case ::VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT: out << "fragment_density_map_optimal_ext"; break;
        case ::VK_IMAGE_LAYOUT_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkObjectType obj)
    {
        using enumIntType = std::underlying_type<::VkObjectType>::type;
        switch (obj)
        {
        case ::VK_OBJECT_TYPE_UNKNOWN: out << "unknown"; break;
        case ::VK_OBJECT_TYPE_INSTANCE: out << "instance"; break;
        case ::VK_OBJECT_TYPE_PHYSICAL_DEVICE: out << "physical_device"; break;
        case ::VK_OBJECT_TYPE_DEVICE: out << "device"; break;
        case ::VK_OBJECT_TYPE_QUEUE: out << "queue"; break;
        case ::VK_OBJECT_TYPE_SEMAPHORE: out << "semaphore"; break;
        case ::VK_OBJECT_TYPE_COMMAND_BUFFER: out << "command_buffer"; break;
        case ::VK_OBJECT_TYPE_FENCE: out << "fence"; break;
        case ::VK_OBJECT_TYPE_DEVICE_MEMORY: out << "device_memory"; break;
        case ::VK_OBJECT_TYPE_BUFFER: out << "buffer"; break;
        case ::VK_OBJECT_TYPE_IMAGE: out << "image"; break;
        case ::VK_OBJECT_TYPE_EVENT: out << "event"; break;
        case ::VK_OBJECT_TYPE_QUERY_POOL: out << "query_pool"; break;
        case ::VK_OBJECT_TYPE_BUFFER_VIEW: out << "buffer_view"; break;
        case ::VK_OBJECT_TYPE_IMAGE_VIEW: out << "image_view"; break;
        case ::VK_OBJECT_TYPE_SHADER_MODULE: out << "shader_module"; break;
        case ::VK_OBJECT_TYPE_PIPELINE_CACHE: out << "pipeline_cache"; break;
        case ::VK_OBJECT_TYPE_PIPELINE_LAYOUT: out << "pipeline_layout"; break;
        case ::VK_OBJECT_TYPE_RENDER_PASS: out << "render_pass"; break;
        case ::VK_OBJECT_TYPE_PIPELINE: out << "pipeline"; break;
        case ::VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT: out << "descriptor_set_layout"; break;
        case ::VK_OBJECT_TYPE_SAMPLER: out << "sampler"; break;
        case ::VK_OBJECT_TYPE_DESCRIPTOR_POOL: out << "descriptor_pool"; break;
        case ::VK_OBJECT_TYPE_DESCRIPTOR_SET: out << "descriptor_set"; break;
        case ::VK_OBJECT_TYPE_FRAMEBUFFER: out << "framebuffer"; break;
        case ::VK_OBJECT_TYPE_COMMAND_POOL: out << "command_pool"; break;
        case ::VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION: out << "sampler_ycbcr_conversion"; break;
        case ::VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE: out << "descriptor_update_template"; break;
        case ::VK_OBJECT_TYPE_SURFACE_KHR: out << "surface_khr"; break;
        case ::VK_OBJECT_TYPE_SWAPCHAIN_KHR: out << "swapchain_khr"; break;
        case ::VK_OBJECT_TYPE_DISPLAY_KHR: out << "display_khr"; break;
        case ::VK_OBJECT_TYPE_DISPLAY_MODE_KHR: out << "display_mode_khr"; break;
        case ::VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT: out << "debug_report_callback_ext"; break;
        case ::VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT: out << "debug_utils_messenger_ext"; break;
        case ::VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR: out << "acceleration_structure_khr"; break;
        case ::VK_OBJECT_TYPE_VALIDATION_CACHE_EXT: out << "validation_cache_ext"; break;
        case ::VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV: out << "acceleration_structure_nv"; break;
        case ::VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL: out << "performance_configuration_intel"; break;
        case ::VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR: out << "deferred_operation_khr"; break;
        case ::VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV: out << "indirect_commands_layout_nv"; break;
        case ::VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT: out << "private_data_slot_ext"; break;
        case ::VK_OBJECT_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkVendorId obj)
    {
        using enumIntType = std::underlying_type<::VkVendorId>::type;
        switch (obj)
        {
        case ::VK_VENDOR_ID_VIV: out << "viv"; break;
        case ::VK_VENDOR_ID_VSI: out << "vsi"; break;
        case ::VK_VENDOR_ID_KAZAN: out << "kazan"; break;
        case ::VK_VENDOR_ID_CODEPLAY: out << "codeplay"; break;
        case ::VK_VENDOR_ID_MESA: out << "mesa"; break;
        case ::VK_VENDOR_ID_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineCacheHeaderVersion obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineCacheHeaderVersion>::type;
        switch (obj)
        {
        case ::VK_PIPELINE_CACHE_HEADER_VERSION_ONE: out << "one"; break;
        case ::VK_PIPELINE_CACHE_HEADER_VERSION_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSystemAllocationScope obj)
    {
        using enumIntType = std::underlying_type<::VkSystemAllocationScope>::type;
        switch (obj)
        {
        case ::VK_SYSTEM_ALLOCATION_SCOPE_COMMAND: out << "command"; break;
        case ::VK_SYSTEM_ALLOCATION_SCOPE_OBJECT: out << "object"; break;
        case ::VK_SYSTEM_ALLOCATION_SCOPE_CACHE: out << "cache"; break;
        case ::VK_SYSTEM_ALLOCATION_SCOPE_DEVICE: out << "device"; break;
        case ::VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE: out << "instance"; break;
        case ::VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkInternalAllocationType obj)
    {
        using enumIntType = std::underlying_type<::VkInternalAllocationType>::type;
        switch (obj)
        {
        case ::VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE: out << "executable"; break;
        case ::VK_INTERNAL_ALLOCATION_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFormat obj)
    {
        using enumIntType = std::underlying_type<::VkFormat>::type;
        switch (obj)
        {
        case ::VK_FORMAT_UNDEFINED: out << "undefined"; break;
        case ::VK_FORMAT_R4G4_UNORM_PACK8: out << "r4g4_unorm_pack8"; break;
        case ::VK_FORMAT_R4G4B4A4_UNORM_PACK16: out << "r4g4b4a4_unorm_pack16"; break;
        case ::VK_FORMAT_B4G4R4A4_UNORM_PACK16: out << "b4g4r4a4_unorm_pack16"; break;
        case ::VK_FORMAT_R5G6B5_UNORM_PACK16: out << "r5g6b5_unorm_pack16"; break;
        case ::VK_FORMAT_B5G6R5_UNORM_PACK16: out << "b5g6r5_unorm_pack16"; break;
        case ::VK_FORMAT_R5G5B5A1_UNORM_PACK16: out << "r5g5b5a1_unorm_pack16"; break;
        case ::VK_FORMAT_B5G5R5A1_UNORM_PACK16: out << "b5g5r5a1_unorm_pack16"; break;
        case ::VK_FORMAT_A1R5G5B5_UNORM_PACK16: out << "a1r5g5b5_unorm_pack16"; break;
        case ::VK_FORMAT_R8_UNORM: out << "r8_unorm"; break;
        case ::VK_FORMAT_R8_SNORM: out << "r8_snorm"; break;
        case ::VK_FORMAT_R8_USCALED: out << "r8_uscaled"; break;
        case ::VK_FORMAT_R8_SSCALED: out << "r8_sscaled"; break;
        case ::VK_FORMAT_R8_UINT: out << "r8_uint"; break;
        case ::VK_FORMAT_R8_SINT: out << "r8_sint"; break;
        case ::VK_FORMAT_R8_SRGB: out << "r8_srgb"; break;
        case ::VK_FORMAT_R8G8_UNORM: out << "r8g8_unorm"; break;
        case ::VK_FORMAT_R8G8_SNORM: out << "r8g8_snorm"; break;
        case ::VK_FORMAT_R8G8_USCALED: out << "r8g8_uscaled"; break;
        case ::VK_FORMAT_R8G8_SSCALED: out << "r8g8_sscaled"; break;
        case ::VK_FORMAT_R8G8_UINT: out << "r8g8_uint"; break;
        case ::VK_FORMAT_R8G8_SINT: out << "r8g8_sint"; break;
        case ::VK_FORMAT_R8G8_SRGB: out << "r8g8_srgb"; break;
        case ::VK_FORMAT_R8G8B8_UNORM: out << "r8g8b8_unorm"; break;
        case ::VK_FORMAT_R8G8B8_SNORM: out << "r8g8b8_snorm"; break;
        case ::VK_FORMAT_R8G8B8_USCALED: out << "r8g8b8_uscaled"; break;
        case ::VK_FORMAT_R8G8B8_SSCALED: out << "r8g8b8_sscaled"; break;
        case ::VK_FORMAT_R8G8B8_UINT: out << "r8g8b8_uint"; break;
        case ::VK_FORMAT_R8G8B8_SINT: out << "r8g8b8_sint"; break;
        case ::VK_FORMAT_R8G8B8_SRGB: out << "r8g8b8_srgb"; break;
        case ::VK_FORMAT_B8G8R8_UNORM: out << "b8g8r8_unorm"; break;
        case ::VK_FORMAT_B8G8R8_SNORM: out << "b8g8r8_snorm"; break;
        case ::VK_FORMAT_B8G8R8_USCALED: out << "b8g8r8_uscaled"; break;
        case ::VK_FORMAT_B8G8R8_SSCALED: out << "b8g8r8_sscaled"; break;
        case ::VK_FORMAT_B8G8R8_UINT: out << "b8g8r8_uint"; break;
        case ::VK_FORMAT_B8G8R8_SINT: out << "b8g8r8_sint"; break;
        case ::VK_FORMAT_B8G8R8_SRGB: out << "b8g8r8_srgb"; break;
        case ::VK_FORMAT_R8G8B8A8_UNORM: out << "r8g8b8a8_unorm"; break;
        case ::VK_FORMAT_R8G8B8A8_SNORM: out << "r8g8b8a8_snorm"; break;
        case ::VK_FORMAT_R8G8B8A8_USCALED: out << "r8g8b8a8_uscaled"; break;
        case ::VK_FORMAT_R8G8B8A8_SSCALED: out << "r8g8b8a8_sscaled"; break;
        case ::VK_FORMAT_R8G8B8A8_UINT: out << "r8g8b8a8_uint"; break;
        case ::VK_FORMAT_R8G8B8A8_SINT: out << "r8g8b8a8_sint"; break;
        case ::VK_FORMAT_R8G8B8A8_SRGB: out << "r8g8b8a8_srgb"; break;
        case ::VK_FORMAT_B8G8R8A8_UNORM: out << "b8g8r8a8_unorm"; break;
        case ::VK_FORMAT_B8G8R8A8_SNORM: out << "b8g8r8a8_snorm"; break;
        case ::VK_FORMAT_B8G8R8A8_USCALED: out << "b8g8r8a8_uscaled"; break;
        case ::VK_FORMAT_B8G8R8A8_SSCALED: out << "b8g8r8a8_sscaled"; break;
        case ::VK_FORMAT_B8G8R8A8_UINT: out << "b8g8r8a8_uint"; break;
        case ::VK_FORMAT_B8G8R8A8_SINT: out << "b8g8r8a8_sint"; break;
        case ::VK_FORMAT_B8G8R8A8_SRGB: out << "b8g8r8a8_srgb"; break;
        case ::VK_FORMAT_A8B8G8R8_UNORM_PACK32: out << "a8b8g8r8_unorm_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_SNORM_PACK32: out << "a8b8g8r8_snorm_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_USCALED_PACK32: out << "a8b8g8r8_uscaled_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_SSCALED_PACK32: out << "a8b8g8r8_sscaled_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_UINT_PACK32: out << "a8b8g8r8_uint_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_SINT_PACK32: out << "a8b8g8r8_sint_pack32"; break;
        case ::VK_FORMAT_A8B8G8R8_SRGB_PACK32: out << "a8b8g8r8_srgb_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_UNORM_PACK32: out << "a2r10g10b10_unorm_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_SNORM_PACK32: out << "a2r10g10b10_snorm_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_USCALED_PACK32: out << "a2r10g10b10_uscaled_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_SSCALED_PACK32: out << "a2r10g10b10_sscaled_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_UINT_PACK32: out << "a2r10g10b10_uint_pack32"; break;
        case ::VK_FORMAT_A2R10G10B10_SINT_PACK32: out << "a2r10g10b10_sint_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_UNORM_PACK32: out << "a2b10g10r10_unorm_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_SNORM_PACK32: out << "a2b10g10r10_snorm_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_USCALED_PACK32: out << "a2b10g10r10_uscaled_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_SSCALED_PACK32: out << "a2b10g10r10_sscaled_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_UINT_PACK32: out << "a2b10g10r10_uint_pack32"; break;
        case ::VK_FORMAT_A2B10G10R10_SINT_PACK32: out << "a2b10g10r10_sint_pack32"; break;
        case ::VK_FORMAT_R16_UNORM: out << "r16_unorm"; break;
        case ::VK_FORMAT_R16_SNORM: out << "r16_snorm"; break;
        case ::VK_FORMAT_R16_USCALED: out << "r16_uscaled"; break;
        case ::VK_FORMAT_R16_SSCALED: out << "r16_sscaled"; break;
        case ::VK_FORMAT_R16_UINT: out << "r16_uint"; break;
        case ::VK_FORMAT_R16_SINT: out << "r16_sint"; break;
        case ::VK_FORMAT_R16_SFLOAT: out << "r16_sfloat"; break;
        case ::VK_FORMAT_R16G16_UNORM: out << "r16g16_unorm"; break;
        case ::VK_FORMAT_R16G16_SNORM: out << "r16g16_snorm"; break;
        case ::VK_FORMAT_R16G16_USCALED: out << "r16g16_uscaled"; break;
        case ::VK_FORMAT_R16G16_SSCALED: out << "r16g16_sscaled"; break;
        case ::VK_FORMAT_R16G16_UINT: out << "r16g16_uint"; break;
        case ::VK_FORMAT_R16G16_SINT: out << "r16g16_sint"; break;
        case ::VK_FORMAT_R16G16_SFLOAT: out << "r16g16_sfloat"; break;
        case ::VK_FORMAT_R16G16B16_UNORM: out << "r16g16b16_unorm"; break;
        case ::VK_FORMAT_R16G16B16_SNORM: out << "r16g16b16_snorm"; break;
        case ::VK_FORMAT_R16G16B16_USCALED: out << "r16g16b16_uscaled"; break;
        case ::VK_FORMAT_R16G16B16_SSCALED: out << "r16g16b16_sscaled"; break;
        case ::VK_FORMAT_R16G16B16_UINT: out << "r16g16b16_uint"; break;
        case ::VK_FORMAT_R16G16B16_SINT: out << "r16g16b16_sint"; break;
        case ::VK_FORMAT_R16G16B16_SFLOAT: out << "r16g16b16_sfloat"; break;
        case ::VK_FORMAT_R16G16B16A16_UNORM: out << "r16g16b16a16_unorm"; break;
        case ::VK_FORMAT_R16G16B16A16_SNORM: out << "r16g16b16a16_snorm"; break;
        case ::VK_FORMAT_R16G16B16A16_USCALED: out << "r16g16b16a16_uscaled"; break;
        case ::VK_FORMAT_R16G16B16A16_SSCALED: out << "r16g16b16a16_sscaled"; break;
        case ::VK_FORMAT_R16G16B16A16_UINT: out << "r16g16b16a16_uint"; break;
        case ::VK_FORMAT_R16G16B16A16_SINT: out << "r16g16b16a16_sint"; break;
        case ::VK_FORMAT_R16G16B16A16_SFLOAT: out << "r16g16b16a16_sfloat"; break;
        case ::VK_FORMAT_R32_UINT: out << "r32_uint"; break;
        case ::VK_FORMAT_R32_SINT: out << "r32_sint"; break;
        case ::VK_FORMAT_R32_SFLOAT: out << "r32_sfloat"; break;
        case ::VK_FORMAT_R32G32_UINT: out << "r32g32_uint"; break;
        case ::VK_FORMAT_R32G32_SINT: out << "r32g32_sint"; break;
        case ::VK_FORMAT_R32G32_SFLOAT: out << "r32g32_sfloat"; break;
        case ::VK_FORMAT_R32G32B32_UINT: out << "r32g32b32_uint"; break;
        case ::VK_FORMAT_R32G32B32_SINT: out << "r32g32b32_sint"; break;
        case ::VK_FORMAT_R32G32B32_SFLOAT: out << "r32g32b32_sfloat"; break;
        case ::VK_FORMAT_R32G32B32A32_UINT: out << "r32g32b32a32_uint"; break;
        case ::VK_FORMAT_R32G32B32A32_SINT: out << "r32g32b32a32_sint"; break;
        case ::VK_FORMAT_R32G32B32A32_SFLOAT: out << "r32g32b32a32_sfloat"; break;
        case ::VK_FORMAT_R64_UINT: out << "r64_uint"; break;
        case ::VK_FORMAT_R64_SINT: out << "r64_sint"; break;
        case ::VK_FORMAT_R64_SFLOAT: out << "r64_sfloat"; break;
        case ::VK_FORMAT_R64G64_UINT: out << "r64g64_uint"; break;
        case ::VK_FORMAT_R64G64_SINT: out << "r64g64_sint"; break;
        case ::VK_FORMAT_R64G64_SFLOAT: out << "r64g64_sfloat"; break;
        case ::VK_FORMAT_R64G64B64_UINT: out << "r64g64b64_uint"; break;
        case ::VK_FORMAT_R64G64B64_SINT: out << "r64g64b64_sint"; break;
        case ::VK_FORMAT_R64G64B64_SFLOAT: out << "r64g64b64_sfloat"; break;
        case ::VK_FORMAT_R64G64B64A64_UINT: out << "r64g64b64a64_uint"; break;
        case ::VK_FORMAT_R64G64B64A64_SINT: out << "r64g64b64a64_sint"; break;
        case ::VK_FORMAT_R64G64B64A64_SFLOAT: out << "r64g64b64a64_sfloat"; break;
        case ::VK_FORMAT_B10G11R11_UFLOAT_PACK32: out << "b10g11r11_ufloat_pack32"; break;
        case ::VK_FORMAT_E5B9G9R9_UFLOAT_PACK32: out << "e5b9g9r9_ufloat_pack32"; break;
        case ::VK_FORMAT_D16_UNORM: out << "d16_unorm"; break;
        case ::VK_FORMAT_X8_D24_UNORM_PACK32: out << "x8_d24_unorm_pack32"; break;
        case ::VK_FORMAT_D32_SFLOAT: out << "d32_sfloat"; break;
        case ::VK_FORMAT_S8_UINT: out << "s8_uint"; break;
        case ::VK_FORMAT_D16_UNORM_S8_UINT: out << "d16_unorm_s8_uint"; break;
        case ::VK_FORMAT_D24_UNORM_S8_UINT: out << "d24_unorm_s8_uint"; break;
        case ::VK_FORMAT_D32_SFLOAT_S8_UINT: out << "d32_sfloat_s8_uint"; break;
        case ::VK_FORMAT_BC1_RGB_UNORM_BLOCK: out << "bc1_rgb_unorm_block"; break;
        case ::VK_FORMAT_BC1_RGB_SRGB_BLOCK: out << "bc1_rgb_srgb_block"; break;
        case ::VK_FORMAT_BC1_RGBA_UNORM_BLOCK: out << "bc1_rgba_unorm_block"; break;
        case ::VK_FORMAT_BC1_RGBA_SRGB_BLOCK: out << "bc1_rgba_srgb_block"; break;
        case ::VK_FORMAT_BC2_UNORM_BLOCK: out << "bc2_unorm_block"; break;
        case ::VK_FORMAT_BC2_SRGB_BLOCK: out << "bc2_srgb_block"; break;
        case ::VK_FORMAT_BC3_UNORM_BLOCK: out << "bc3_unorm_block"; break;
        case ::VK_FORMAT_BC3_SRGB_BLOCK: out << "bc3_srgb_block"; break;
        case ::VK_FORMAT_BC4_UNORM_BLOCK: out << "bc4_unorm_block"; break;
        case ::VK_FORMAT_BC4_SNORM_BLOCK: out << "bc4_snorm_block"; break;
        case ::VK_FORMAT_BC5_UNORM_BLOCK: out << "bc5_unorm_block"; break;
        case ::VK_FORMAT_BC5_SNORM_BLOCK: out << "bc5_snorm_block"; break;
        case ::VK_FORMAT_BC6H_UFLOAT_BLOCK: out << "bc6h_ufloat_block"; break;
        case ::VK_FORMAT_BC6H_SFLOAT_BLOCK: out << "bc6h_sfloat_block"; break;
        case ::VK_FORMAT_BC7_UNORM_BLOCK: out << "bc7_unorm_block"; break;
        case ::VK_FORMAT_BC7_SRGB_BLOCK: out << "bc7_srgb_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK: out << "etc2_r8g8b8_unorm_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK: out << "etc2_r8g8b8_srgb_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK: out << "etc2_r8g8b8a1_unorm_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK: out << "etc2_r8g8b8a1_srgb_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK: out << "etc2_r8g8b8a8_unorm_block"; break;
        case ::VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK: out << "etc2_r8g8b8a8_srgb_block"; break;
        case ::VK_FORMAT_EAC_R11_UNORM_BLOCK: out << "eac_r11_unorm_block"; break;
        case ::VK_FORMAT_EAC_R11_SNORM_BLOCK: out << "eac_r11_snorm_block"; break;
        case ::VK_FORMAT_EAC_R11G11_UNORM_BLOCK: out << "eac_r11g11_unorm_block"; break;
        case ::VK_FORMAT_EAC_R11G11_SNORM_BLOCK: out << "eac_r11g11_snorm_block"; break;
        case ::VK_FORMAT_ASTC_4x4_UNORM_BLOCK: out << "astc_4x4_unorm_block"; break;
        case ::VK_FORMAT_ASTC_4x4_SRGB_BLOCK: out << "astc_4x4_srgb_block"; break;
        case ::VK_FORMAT_ASTC_5x4_UNORM_BLOCK: out << "astc_5x4_unorm_block"; break;
        case ::VK_FORMAT_ASTC_5x4_SRGB_BLOCK: out << "astc_5x4_srgb_block"; break;
        case ::VK_FORMAT_ASTC_5x5_UNORM_BLOCK: out << "astc_5x5_unorm_block"; break;
        case ::VK_FORMAT_ASTC_5x5_SRGB_BLOCK: out << "astc_5x5_srgb_block"; break;
        case ::VK_FORMAT_ASTC_6x5_UNORM_BLOCK: out << "astc_6x5_unorm_block"; break;
        case ::VK_FORMAT_ASTC_6x5_SRGB_BLOCK: out << "astc_6x5_srgb_block"; break;
        case ::VK_FORMAT_ASTC_6x6_UNORM_BLOCK: out << "astc_6x6_unorm_block"; break;
        case ::VK_FORMAT_ASTC_6x6_SRGB_BLOCK: out << "astc_6x6_srgb_block"; break;
        case ::VK_FORMAT_ASTC_8x5_UNORM_BLOCK: out << "astc_8x5_unorm_block"; break;
        case ::VK_FORMAT_ASTC_8x5_SRGB_BLOCK: out << "astc_8x5_srgb_block"; break;
        case ::VK_FORMAT_ASTC_8x6_UNORM_BLOCK: out << "astc_8x6_unorm_block"; break;
        case ::VK_FORMAT_ASTC_8x6_SRGB_BLOCK: out << "astc_8x6_srgb_block"; break;
        case ::VK_FORMAT_ASTC_8x8_UNORM_BLOCK: out << "astc_8x8_unorm_block"; break;
        case ::VK_FORMAT_ASTC_8x8_SRGB_BLOCK: out << "astc_8x8_srgb_block"; break;
        case ::VK_FORMAT_ASTC_10x5_UNORM_BLOCK: out << "astc_10x5_unorm_block"; break;
        case ::VK_FORMAT_ASTC_10x5_SRGB_BLOCK: out << "astc_10x5_srgb_block"; break;
        case ::VK_FORMAT_ASTC_10x6_UNORM_BLOCK: out << "astc_10x6_unorm_block"; break;
        case ::VK_FORMAT_ASTC_10x6_SRGB_BLOCK: out << "astc_10x6_srgb_block"; break;
        case ::VK_FORMAT_ASTC_10x8_UNORM_BLOCK: out << "astc_10x8_unorm_block"; break;
        case ::VK_FORMAT_ASTC_10x8_SRGB_BLOCK: out << "astc_10x8_srgb_block"; break;
        case ::VK_FORMAT_ASTC_10x10_UNORM_BLOCK: out << "astc_10x10_unorm_block"; break;
        case ::VK_FORMAT_ASTC_10x10_SRGB_BLOCK: out << "astc_10x10_srgb_block"; break;
        case ::VK_FORMAT_ASTC_12x10_UNORM_BLOCK: out << "astc_12x10_unorm_block"; break;
        case ::VK_FORMAT_ASTC_12x10_SRGB_BLOCK: out << "astc_12x10_srgb_block"; break;
        case ::VK_FORMAT_ASTC_12x12_UNORM_BLOCK: out << "astc_12x12_unorm_block"; break;
        case ::VK_FORMAT_ASTC_12x12_SRGB_BLOCK: out << "astc_12x12_srgb_block"; break;
        case ::VK_FORMAT_G8B8G8R8_422_UNORM: out << "g8b8g8r8_422_unorm"; break;
        case ::VK_FORMAT_B8G8R8G8_422_UNORM: out << "b8g8r8g8_422_unorm"; break;
        case ::VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM: out << "g8_b8_r8_3plane_420_unorm"; break;
        case ::VK_FORMAT_G8_B8R8_2PLANE_420_UNORM: out << "g8_b8r8_2plane_420_unorm"; break;
        case ::VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM: out << "g8_b8_r8_3plane_422_unorm"; break;
        case ::VK_FORMAT_G8_B8R8_2PLANE_422_UNORM: out << "g8_b8r8_2plane_422_unorm"; break;
        case ::VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM: out << "g8_b8_r8_3plane_444_unorm"; break;
        case ::VK_FORMAT_R10X6_UNORM_PACK16: out << "r10x6_unorm_pack16"; break;
        case ::VK_FORMAT_R10X6G10X6_UNORM_2PACK16: out << "r10x6g10x6_unorm_2pack16"; break;
        case ::VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16: out << "r10x6g10x6b10x6a10x6_unorm_4pack16"; break;
        case ::VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16: out << "g10x6b10x6g10x6r10x6_422_unorm_4pack16"; break;
        case ::VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16: out << "b10x6g10x6r10x6g10x6_422_unorm_4pack16"; break;
        case ::VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16: out << "g10x6_b10x6_r10x6_3plane_420_unorm_3pack16"; break;
        case ::VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16: out << "g10x6_b10x6r10x6_2plane_420_unorm_3pack16"; break;
        case ::VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16: out << "g10x6_b10x6_r10x6_3plane_422_unorm_3pack16"; break;
        case ::VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16: out << "g10x6_b10x6r10x6_2plane_422_unorm_3pack16"; break;
        case ::VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16: out << "g10x6_b10x6_r10x6_3plane_444_unorm_3pack16"; break;
        case ::VK_FORMAT_R12X4_UNORM_PACK16: out << "r12x4_unorm_pack16"; break;
        case ::VK_FORMAT_R12X4G12X4_UNORM_2PACK16: out << "r12x4g12x4_unorm_2pack16"; break;
        case ::VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16: out << "r12x4g12x4b12x4a12x4_unorm_4pack16"; break;
        case ::VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16: out << "g12x4b12x4g12x4r12x4_422_unorm_4pack16"; break;
        case ::VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16: out << "b12x4g12x4r12x4g12x4_422_unorm_4pack16"; break;
        case ::VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16: out << "g12x4_b12x4_r12x4_3plane_420_unorm_3pack16"; break;
        case ::VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16: out << "g12x4_b12x4r12x4_2plane_420_unorm_3pack16"; break;
        case ::VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16: out << "g12x4_b12x4_r12x4_3plane_422_unorm_3pack16"; break;
        case ::VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16: out << "g12x4_b12x4r12x4_2plane_422_unorm_3pack16"; break;
        case ::VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16: out << "g12x4_b12x4_r12x4_3plane_444_unorm_3pack16"; break;
        case ::VK_FORMAT_G16B16G16R16_422_UNORM: out << "g16b16g16r16_422_unorm"; break;
        case ::VK_FORMAT_B16G16R16G16_422_UNORM: out << "b16g16r16g16_422_unorm"; break;
        case ::VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM: out << "g16_b16_r16_3plane_420_unorm"; break;
        case ::VK_FORMAT_G16_B16R16_2PLANE_420_UNORM: out << "g16_b16r16_2plane_420_unorm"; break;
        case ::VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM: out << "g16_b16_r16_3plane_422_unorm"; break;
        case ::VK_FORMAT_G16_B16R16_2PLANE_422_UNORM: out << "g16_b16r16_2plane_422_unorm"; break;
        case ::VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM: out << "g16_b16_r16_3plane_444_unorm"; break;
        case ::VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG: out << "pvrtc1_2bpp_unorm_block_img"; break;
        case ::VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG: out << "pvrtc1_4bpp_unorm_block_img"; break;
        case ::VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG: out << "pvrtc2_2bpp_unorm_block_img"; break;
        case ::VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG: out << "pvrtc2_4bpp_unorm_block_img"; break;
        case ::VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG: out << "pvrtc1_2bpp_srgb_block_img"; break;
        case ::VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG: out << "pvrtc1_4bpp_srgb_block_img"; break;
        case ::VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG: out << "pvrtc2_2bpp_srgb_block_img"; break;
        case ::VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG: out << "pvrtc2_4bpp_srgb_block_img"; break;
        case ::VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT: out << "astc_4x4_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT: out << "astc_5x4_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT: out << "astc_5x5_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT: out << "astc_6x5_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT: out << "astc_6x6_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT: out << "astc_8x5_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT: out << "astc_8x6_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT: out << "astc_8x8_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT: out << "astc_10x5_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT: out << "astc_10x6_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT: out << "astc_10x8_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT: out << "astc_10x10_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT: out << "astc_12x10_sfloat_block_ext"; break;
        case ::VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT: out << "astc_12x12_sfloat_block_ext"; break;
        case ::VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT: out << "a4r4g4b4_unorm_pack16_ext"; break;
        case ::VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT: out << "a4b4g4r4_unorm_pack16_ext"; break;
        case ::VK_FORMAT_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageTiling obj)
    {
        using enumIntType = std::underlying_type<::VkImageTiling>::type;
        switch (obj)
        {
        case ::VK_IMAGE_TILING_OPTIMAL: out << "optimal"; break;
        case ::VK_IMAGE_TILING_LINEAR: out << "linear"; break;
        case ::VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT: out << "drm_format_modifier_ext"; break;
        case ::VK_IMAGE_TILING_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageType obj)
    {
        using enumIntType = std::underlying_type<::VkImageType>::type;
        switch (obj)
        {
        case ::VK_IMAGE_TYPE_1D: out << "1d"; break;
        case ::VK_IMAGE_TYPE_2D: out << "2d"; break;
        case ::VK_IMAGE_TYPE_3D: out << "3d"; break;
        case ::VK_IMAGE_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPhysicalDeviceType obj)
    {
        using enumIntType = std::underlying_type<::VkPhysicalDeviceType>::type;
        switch (obj)
        {
        case ::VK_PHYSICAL_DEVICE_TYPE_OTHER: out << "other"; break;
        case ::VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: out << "integrated_gpu"; break;
        case ::VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU: out << "discrete_gpu"; break;
        case ::VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU: out << "virtual_gpu"; break;
        case ::VK_PHYSICAL_DEVICE_TYPE_CPU: out << "cpu"; break;
        case ::VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueryType obj)
    {
        using enumIntType = std::underlying_type<::VkQueryType>::type;
        switch (obj)
        {
        case ::VK_QUERY_TYPE_OCCLUSION: out << "occlusion"; break;
        case ::VK_QUERY_TYPE_PIPELINE_STATISTICS: out << "pipeline_statistics"; break;
        case ::VK_QUERY_TYPE_TIMESTAMP: out << "timestamp"; break;
        case ::VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT: out << "transform_feedback_stream_ext"; break;
        case ::VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR: out << "performance_query_khr"; break;
        case ::VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR: out << "acceleration_structure_compacted_size_khr"; break;
        case ::VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR: out << "acceleration_structure_serialization_size_khr"; break;
        case ::VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV: out << "acceleration_structure_compacted_size_nv"; break;
        case ::VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL: out << "performance_query_intel"; break;
        case ::VK_QUERY_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSharingMode obj)
    {
        using enumIntType = std::underlying_type<::VkSharingMode>::type;
        switch (obj)
        {
        case ::VK_SHARING_MODE_EXCLUSIVE: out << "exclusive"; break;
        case ::VK_SHARING_MODE_CONCURRENT: out << "concurrent"; break;
        case ::VK_SHARING_MODE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkComponentSwizzle obj)
    {
        using enumIntType = std::underlying_type<::VkComponentSwizzle>::type;
        switch (obj)
        {
        case ::VK_COMPONENT_SWIZZLE_IDENTITY: out << "identity"; break;
        case ::VK_COMPONENT_SWIZZLE_ZERO: out << "zero"; break;
        case ::VK_COMPONENT_SWIZZLE_ONE: out << "one"; break;
        case ::VK_COMPONENT_SWIZZLE_R: out << "r"; break;
        case ::VK_COMPONENT_SWIZZLE_G: out << "g"; break;
        case ::VK_COMPONENT_SWIZZLE_B: out << "b"; break;
        case ::VK_COMPONENT_SWIZZLE_A: out << "a"; break;
        case ::VK_COMPONENT_SWIZZLE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageViewType obj)
    {
        using enumIntType = std::underlying_type<::VkImageViewType>::type;
        switch (obj)
        {
        case ::VK_IMAGE_VIEW_TYPE_1D: out << "1d"; break;
        case ::VK_IMAGE_VIEW_TYPE_2D: out << "2d"; break;
        case ::VK_IMAGE_VIEW_TYPE_3D: out << "3d"; break;
        case ::VK_IMAGE_VIEW_TYPE_CUBE: out << "cube"; break;
        case ::VK_IMAGE_VIEW_TYPE_1D_ARRAY: out << "1d_array"; break;
        case ::VK_IMAGE_VIEW_TYPE_2D_ARRAY: out << "2d_array"; break;
        case ::VK_IMAGE_VIEW_TYPE_CUBE_ARRAY: out << "cube_array"; break;
        case ::VK_IMAGE_VIEW_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBlendFactor obj)
    {
        using enumIntType = std::underlying_type<::VkBlendFactor>::type;
        switch (obj)
        {
        case ::VK_BLEND_FACTOR_ZERO: out << "zero"; break;
        case ::VK_BLEND_FACTOR_ONE: out << "one"; break;
        case ::VK_BLEND_FACTOR_SRC_COLOR: out << "src_color"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR: out << "one_minus_src_color"; break;
        case ::VK_BLEND_FACTOR_DST_COLOR: out << "dst_color"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR: out << "one_minus_dst_color"; break;
        case ::VK_BLEND_FACTOR_SRC_ALPHA: out << "src_alpha"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA: out << "one_minus_src_alpha"; break;
        case ::VK_BLEND_FACTOR_DST_ALPHA: out << "dst_alpha"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA: out << "one_minus_dst_alpha"; break;
        case ::VK_BLEND_FACTOR_CONSTANT_COLOR: out << "constant_color"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR: out << "one_minus_constant_color"; break;
        case ::VK_BLEND_FACTOR_CONSTANT_ALPHA: out << "constant_alpha"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA: out << "one_minus_constant_alpha"; break;
        case ::VK_BLEND_FACTOR_SRC_ALPHA_SATURATE: out << "src_alpha_saturate"; break;
        case ::VK_BLEND_FACTOR_SRC1_COLOR: out << "src1_color"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR: out << "one_minus_src1_color"; break;
        case ::VK_BLEND_FACTOR_SRC1_ALPHA: out << "src1_alpha"; break;
        case ::VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA: out << "one_minus_src1_alpha"; break;
        case ::VK_BLEND_FACTOR_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBlendOp obj)
    {
        using enumIntType = std::underlying_type<::VkBlendOp>::type;
        switch (obj)
        {
        case ::VK_BLEND_OP_ADD: out << "add"; break;
        case ::VK_BLEND_OP_SUBTRACT: out << "subtract"; break;
        case ::VK_BLEND_OP_REVERSE_SUBTRACT: out << "reverse_subtract"; break;
        case ::VK_BLEND_OP_MIN: out << "min"; break;
        case ::VK_BLEND_OP_MAX: out << "max"; break;
        case ::VK_BLEND_OP_ZERO_EXT: out << "zero_ext"; break;
        case ::VK_BLEND_OP_SRC_EXT: out << "src_ext"; break;
        case ::VK_BLEND_OP_DST_EXT: out << "dst_ext"; break;
        case ::VK_BLEND_OP_SRC_OVER_EXT: out << "src_over_ext"; break;
        case ::VK_BLEND_OP_DST_OVER_EXT: out << "dst_over_ext"; break;
        case ::VK_BLEND_OP_SRC_IN_EXT: out << "src_in_ext"; break;
        case ::VK_BLEND_OP_DST_IN_EXT: out << "dst_in_ext"; break;
        case ::VK_BLEND_OP_SRC_OUT_EXT: out << "src_out_ext"; break;
        case ::VK_BLEND_OP_DST_OUT_EXT: out << "dst_out_ext"; break;
        case ::VK_BLEND_OP_SRC_ATOP_EXT: out << "src_atop_ext"; break;
        case ::VK_BLEND_OP_DST_ATOP_EXT: out << "dst_atop_ext"; break;
        case ::VK_BLEND_OP_XOR_EXT: out << "xor_ext"; break;
        case ::VK_BLEND_OP_MULTIPLY_EXT: out << "multiply_ext"; break;
        case ::VK_BLEND_OP_SCREEN_EXT: out << "screen_ext"; break;
        case ::VK_BLEND_OP_OVERLAY_EXT: out << "overlay_ext"; break;
        case ::VK_BLEND_OP_DARKEN_EXT: out << "darken_ext"; break;
        case ::VK_BLEND_OP_LIGHTEN_EXT: out << "lighten_ext"; break;
        case ::VK_BLEND_OP_COLORDODGE_EXT: out << "colordodge_ext"; break;
        case ::VK_BLEND_OP_COLORBURN_EXT: out << "colorburn_ext"; break;
        case ::VK_BLEND_OP_HARDLIGHT_EXT: out << "hardlight_ext"; break;
        case ::VK_BLEND_OP_SOFTLIGHT_EXT: out << "softlight_ext"; break;
        case ::VK_BLEND_OP_DIFFERENCE_EXT: out << "difference_ext"; break;
        case ::VK_BLEND_OP_EXCLUSION_EXT: out << "exclusion_ext"; break;
        case ::VK_BLEND_OP_INVERT_EXT: out << "invert_ext"; break;
        case ::VK_BLEND_OP_INVERT_RGB_EXT: out << "invert_rgb_ext"; break;
        case ::VK_BLEND_OP_LINEARDODGE_EXT: out << "lineardodge_ext"; break;
        case ::VK_BLEND_OP_LINEARBURN_EXT: out << "linearburn_ext"; break;
        case ::VK_BLEND_OP_VIVIDLIGHT_EXT: out << "vividlight_ext"; break;
        case ::VK_BLEND_OP_LINEARLIGHT_EXT: out << "linearlight_ext"; break;
        case ::VK_BLEND_OP_PINLIGHT_EXT: out << "pinlight_ext"; break;
        case ::VK_BLEND_OP_HARDMIX_EXT: out << "hardmix_ext"; break;
        case ::VK_BLEND_OP_HSL_HUE_EXT: out << "hsl_hue_ext"; break;
        case ::VK_BLEND_OP_HSL_SATURATION_EXT: out << "hsl_saturation_ext"; break;
        case ::VK_BLEND_OP_HSL_COLOR_EXT: out << "hsl_color_ext"; break;
        case ::VK_BLEND_OP_HSL_LUMINOSITY_EXT: out << "hsl_luminosity_ext"; break;
        case ::VK_BLEND_OP_PLUS_EXT: out << "plus_ext"; break;
        case ::VK_BLEND_OP_PLUS_CLAMPED_EXT: out << "plus_clamped_ext"; break;
        case ::VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT: out << "plus_clamped_alpha_ext"; break;
        case ::VK_BLEND_OP_PLUS_DARKER_EXT: out << "plus_darker_ext"; break;
        case ::VK_BLEND_OP_MINUS_EXT: out << "minus_ext"; break;
        case ::VK_BLEND_OP_MINUS_CLAMPED_EXT: out << "minus_clamped_ext"; break;
        case ::VK_BLEND_OP_CONTRAST_EXT: out << "contrast_ext"; break;
        case ::VK_BLEND_OP_INVERT_OVG_EXT: out << "invert_ovg_ext"; break;
        case ::VK_BLEND_OP_RED_EXT: out << "red_ext"; break;
        case ::VK_BLEND_OP_GREEN_EXT: out << "green_ext"; break;
        case ::VK_BLEND_OP_BLUE_EXT: out << "blue_ext"; break;
        case ::VK_BLEND_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCompareOp obj)
    {
        using enumIntType = std::underlying_type<::VkCompareOp>::type;
        switch (obj)
        {
        case ::VK_COMPARE_OP_NEVER: out << "never"; break;
        case ::VK_COMPARE_OP_LESS: out << "less"; break;
        case ::VK_COMPARE_OP_EQUAL: out << "equal"; break;
        case ::VK_COMPARE_OP_LESS_OR_EQUAL: out << "less_or_equal"; break;
        case ::VK_COMPARE_OP_GREATER: out << "greater"; break;
        case ::VK_COMPARE_OP_NOT_EQUAL: out << "not_equal"; break;
        case ::VK_COMPARE_OP_GREATER_OR_EQUAL: out << "greater_or_equal"; break;
        case ::VK_COMPARE_OP_ALWAYS: out << "always"; break;
        case ::VK_COMPARE_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDynamicState obj)
    {
        using enumIntType = std::underlying_type<::VkDynamicState>::type;
        switch (obj)
        {
        case ::VK_DYNAMIC_STATE_VIEWPORT: out << "viewport"; break;
        case ::VK_DYNAMIC_STATE_SCISSOR: out << "scissor"; break;
        case ::VK_DYNAMIC_STATE_LINE_WIDTH: out << "line_width"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_BIAS: out << "depth_bias"; break;
        case ::VK_DYNAMIC_STATE_BLEND_CONSTANTS: out << "blend_constants"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_BOUNDS: out << "depth_bounds"; break;
        case ::VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK: out << "stencil_compare_mask"; break;
        case ::VK_DYNAMIC_STATE_STENCIL_WRITE_MASK: out << "stencil_write_mask"; break;
        case ::VK_DYNAMIC_STATE_STENCIL_REFERENCE: out << "stencil_reference"; break;
        case ::VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV: out << "viewport_w_scaling_nv"; break;
        case ::VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT: out << "discard_rectangle_ext"; break;
        case ::VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT: out << "sample_locations_ext"; break;
        case ::VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR: out << "ray_tracing_pipeline_stack_size_khr"; break;
        case ::VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV: out << "viewport_shading_rate_palette_nv"; break;
        case ::VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV: out << "viewport_coarse_sample_order_nv"; break;
        case ::VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV: out << "exclusive_scissor_nv"; break;
        case ::VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR: out << "fragment_shading_rate_khr"; break;
        case ::VK_DYNAMIC_STATE_LINE_STIPPLE_EXT: out << "line_stipple_ext"; break;
        case ::VK_DYNAMIC_STATE_CULL_MODE_EXT: out << "cull_mode_ext"; break;
        case ::VK_DYNAMIC_STATE_FRONT_FACE_EXT: out << "front_face_ext"; break;
        case ::VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT: out << "primitive_topology_ext"; break;
        case ::VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT: out << "viewport_with_count_ext"; break;
        case ::VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT: out << "scissor_with_count_ext"; break;
        case ::VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT: out << "vertex_input_binding_stride_ext"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT: out << "depth_test_enable_ext"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT: out << "depth_write_enable_ext"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT: out << "depth_compare_op_ext"; break;
        case ::VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT: out << "depth_bounds_test_enable_ext"; break;
        case ::VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT: out << "stencil_test_enable_ext"; break;
        case ::VK_DYNAMIC_STATE_STENCIL_OP_EXT: out << "stencil_op_ext"; break;
        case ::VK_DYNAMIC_STATE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFrontFace obj)
    {
        using enumIntType = std::underlying_type<::VkFrontFace>::type;
        switch (obj)
        {
        case ::VK_FRONT_FACE_COUNTER_CLOCKWISE: out << "counter_clockwise"; break;
        case ::VK_FRONT_FACE_CLOCKWISE: out << "clockwise"; break;
        case ::VK_FRONT_FACE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkVertexInputRate obj)
    {
        using enumIntType = std::underlying_type<::VkVertexInputRate>::type;
        switch (obj)
        {
        case ::VK_VERTEX_INPUT_RATE_VERTEX: out << "vertex"; break;
        case ::VK_VERTEX_INPUT_RATE_INSTANCE: out << "instance"; break;
        case ::VK_VERTEX_INPUT_RATE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPrimitiveTopology obj)
    {
        using enumIntType = std::underlying_type<::VkPrimitiveTopology>::type;
        switch (obj)
        {
        case ::VK_PRIMITIVE_TOPOLOGY_POINT_LIST: out << "point_list"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_LINE_LIST: out << "line_list"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_LINE_STRIP: out << "line_strip"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST: out << "triangle_list"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP: out << "triangle_strip"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN: out << "triangle_fan"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY: out << "line_list_with_adjacency"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY: out << "line_strip_with_adjacency"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY: out << "triangle_list_with_adjacency"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY: out << "triangle_strip_with_adjacency"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_PATCH_LIST: out << "patch_list"; break;
        case ::VK_PRIMITIVE_TOPOLOGY_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPolygonMode obj)
    {
        using enumIntType = std::underlying_type<::VkPolygonMode>::type;
        switch (obj)
        {
        case ::VK_POLYGON_MODE_FILL: out << "fill"; break;
        case ::VK_POLYGON_MODE_LINE: out << "line"; break;
        case ::VK_POLYGON_MODE_POINT: out << "point"; break;
        case ::VK_POLYGON_MODE_FILL_RECTANGLE_NV: out << "fill_rectangle_nv"; break;
        case ::VK_POLYGON_MODE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkStencilOp obj)
    {
        using enumIntType = std::underlying_type<::VkStencilOp>::type;
        switch (obj)
        {
        case ::VK_STENCIL_OP_KEEP: out << "keep"; break;
        case ::VK_STENCIL_OP_ZERO: out << "zero"; break;
        case ::VK_STENCIL_OP_REPLACE: out << "replace"; break;
        case ::VK_STENCIL_OP_INCREMENT_AND_CLAMP: out << "increment_and_clamp"; break;
        case ::VK_STENCIL_OP_DECREMENT_AND_CLAMP: out << "decrement_and_clamp"; break;
        case ::VK_STENCIL_OP_INVERT: out << "invert"; break;
        case ::VK_STENCIL_OP_INCREMENT_AND_WRAP: out << "increment_and_wrap"; break;
        case ::VK_STENCIL_OP_DECREMENT_AND_WRAP: out << "decrement_and_wrap"; break;
        case ::VK_STENCIL_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkLogicOp obj)
    {
        using enumIntType = std::underlying_type<::VkLogicOp>::type;
        switch (obj)
        {
        case ::VK_LOGIC_OP_CLEAR: out << "clear"; break;
        case ::VK_LOGIC_OP_AND: out << "and"; break;
        case ::VK_LOGIC_OP_AND_REVERSE: out << "and_reverse"; break;
        case ::VK_LOGIC_OP_COPY: out << "copy"; break;
        case ::VK_LOGIC_OP_AND_INVERTED: out << "and_inverted"; break;
        case ::VK_LOGIC_OP_NO_OP: out << "no_op"; break;
        case ::VK_LOGIC_OP_XOR: out << "xor"; break;
        case ::VK_LOGIC_OP_OR: out << "or"; break;
        case ::VK_LOGIC_OP_NOR: out << "nor"; break;
        case ::VK_LOGIC_OP_EQUIVALENT: out << "equivalent"; break;
        case ::VK_LOGIC_OP_INVERT: out << "invert"; break;
        case ::VK_LOGIC_OP_OR_REVERSE: out << "or_reverse"; break;
        case ::VK_LOGIC_OP_COPY_INVERTED: out << "copy_inverted"; break;
        case ::VK_LOGIC_OP_OR_INVERTED: out << "or_inverted"; break;
        case ::VK_LOGIC_OP_NAND: out << "nand"; break;
        case ::VK_LOGIC_OP_SET: out << "set"; break;
        case ::VK_LOGIC_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBorderColor obj)
    {
        using enumIntType = std::underlying_type<::VkBorderColor>::type;
        switch (obj)
        {
        case ::VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK: out << "float_transparent_black"; break;
        case ::VK_BORDER_COLOR_INT_TRANSPARENT_BLACK: out << "int_transparent_black"; break;
        case ::VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK: out << "float_opaque_black"; break;
        case ::VK_BORDER_COLOR_INT_OPAQUE_BLACK: out << "int_opaque_black"; break;
        case ::VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE: out << "float_opaque_white"; break;
        case ::VK_BORDER_COLOR_INT_OPAQUE_WHITE: out << "int_opaque_white"; break;
        case ::VK_BORDER_COLOR_FLOAT_CUSTOM_EXT: out << "float_custom_ext"; break;
        case ::VK_BORDER_COLOR_INT_CUSTOM_EXT: out << "int_custom_ext"; break;
        case ::VK_BORDER_COLOR_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFilter obj)
    {
        using enumIntType = std::underlying_type<::VkFilter>::type;
        switch (obj)
        {
        case ::VK_FILTER_NEAREST: out << "nearest"; break;
        case ::VK_FILTER_LINEAR: out << "linear"; break;
        case ::VK_FILTER_CUBIC_IMG: out << "cubic_img"; break;
        case ::VK_FILTER_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerAddressMode obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerAddressMode>::type;
        switch (obj)
        {
        case ::VK_SAMPLER_ADDRESS_MODE_REPEAT: out << "repeat"; break;
        case ::VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT: out << "mirrored_repeat"; break;
        case ::VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE: out << "clamp_to_edge"; break;
        case ::VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER: out << "clamp_to_border"; break;
        case ::VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE: out << "mirror_clamp_to_edge"; break;
        case ::VK_SAMPLER_ADDRESS_MODE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerMipmapMode obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerMipmapMode>::type;
        switch (obj)
        {
        case ::VK_SAMPLER_MIPMAP_MODE_NEAREST: out << "nearest"; break;
        case ::VK_SAMPLER_MIPMAP_MODE_LINEAR: out << "linear"; break;
        case ::VK_SAMPLER_MIPMAP_MODE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDescriptorType obj)
    {
        using enumIntType = std::underlying_type<::VkDescriptorType>::type;
        switch (obj)
        {
        case ::VK_DESCRIPTOR_TYPE_SAMPLER: out << "sampler"; break;
        case ::VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER: out << "combined_image_sampler"; break;
        case ::VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE: out << "sampled_image"; break;
        case ::VK_DESCRIPTOR_TYPE_STORAGE_IMAGE: out << "storage_image"; break;
        case ::VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER: out << "uniform_texel_buffer"; break;
        case ::VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER: out << "storage_texel_buffer"; break;
        case ::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER: out << "uniform_buffer"; break;
        case ::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER: out << "storage_buffer"; break;
        case ::VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC: out << "uniform_buffer_dynamic"; break;
        case ::VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC: out << "storage_buffer_dynamic"; break;
        case ::VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT: out << "input_attachment"; break;
        case ::VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT: out << "inline_uniform_block_ext"; break;
        case ::VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR: out << "acceleration_structure_khr"; break;
        case ::VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV: out << "acceleration_structure_nv"; break;
        case ::VK_DESCRIPTOR_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAttachmentLoadOp obj)
    {
        using enumIntType = std::underlying_type<::VkAttachmentLoadOp>::type;
        switch (obj)
        {
        case ::VK_ATTACHMENT_LOAD_OP_LOAD: out << "load"; break;
        case ::VK_ATTACHMENT_LOAD_OP_CLEAR: out << "clear"; break;
        case ::VK_ATTACHMENT_LOAD_OP_DONT_CARE: out << "dont_care"; break;
        case ::VK_ATTACHMENT_LOAD_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAttachmentStoreOp obj)
    {
        using enumIntType = std::underlying_type<::VkAttachmentStoreOp>::type;
        switch (obj)
        {
        case ::VK_ATTACHMENT_STORE_OP_STORE: out << "store"; break;
        case ::VK_ATTACHMENT_STORE_OP_DONT_CARE: out << "dont_care"; break;
        case ::VK_ATTACHMENT_STORE_OP_NONE_QCOM: out << "none_qcom"; break;
        case ::VK_ATTACHMENT_STORE_OP_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineBindPoint obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineBindPoint>::type;
        switch (obj)
        {
        case ::VK_PIPELINE_BIND_POINT_GRAPHICS: out << "graphics"; break;
        case ::VK_PIPELINE_BIND_POINT_COMPUTE: out << "compute"; break;
        case ::VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR: out << "ray_tracing_khr"; break;
        case ::VK_PIPELINE_BIND_POINT_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCommandBufferLevel obj)
    {
        using enumIntType = std::underlying_type<::VkCommandBufferLevel>::type;
        switch (obj)
        {
        case ::VK_COMMAND_BUFFER_LEVEL_PRIMARY: out << "primary"; break;
        case ::VK_COMMAND_BUFFER_LEVEL_SECONDARY: out << "secondary"; break;
        case ::VK_COMMAND_BUFFER_LEVEL_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkIndexType obj)
    {
        using enumIntType = std::underlying_type<::VkIndexType>::type;
        switch (obj)
        {
        case ::VK_INDEX_TYPE_UINT16: out << "uint16"; break;
        case ::VK_INDEX_TYPE_UINT32: out << "uint32"; break;
        case ::VK_INDEX_TYPE_NONE_KHR: out << "none_khr"; break;
        case ::VK_INDEX_TYPE_UINT8_EXT: out << "uint8_ext"; break;
        case ::VK_INDEX_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSubpassContents obj)
    {
        using enumIntType = std::underlying_type<::VkSubpassContents>::type;
        switch (obj)
        {
        case ::VK_SUBPASS_CONTENTS_INLINE: out << "inline"; break;
        case ::VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS: out << "secondary_command_buffers"; break;
        case ::VK_SUBPASS_CONTENTS_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccessFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkAccessFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_ACCESS_INDIRECT_COMMAND_READ_BIT))
        {
            out << " indirect_command_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_INDIRECT_COMMAND_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_INDEX_READ_BIT))
        {
            out << " index_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_INDEX_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT))
        {
            out << " vertex_attribute_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_UNIFORM_READ_BIT))
        {
            out << " uniform_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_UNIFORM_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_INPUT_ATTACHMENT_READ_BIT))
        {
            out << " input_attachment_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_INPUT_ATTACHMENT_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_SHADER_READ_BIT))
        {
            out << " shader_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_SHADER_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_SHADER_WRITE_BIT))
        {
            out << " shader_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_SHADER_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_READ_BIT))
        {
            out << " color_attachment_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT))
        {
            out << " color_attachment_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT))
        {
            out << " depth_stencil_attachment_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT))
        {
            out << " depth_stencil_attachment_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_TRANSFER_READ_BIT))
        {
            out << " transfer_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_TRANSFER_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_TRANSFER_WRITE_BIT))
        {
            out << " transfer_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_TRANSFER_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_HOST_READ_BIT))
        {
            out << " host_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_HOST_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_HOST_WRITE_BIT))
        {
            out << " host_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_HOST_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_MEMORY_READ_BIT))
        {
            out << " memory_read_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_MEMORY_READ_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_MEMORY_WRITE_BIT))
        {
            out << " memory_write_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_MEMORY_WRITE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT))
        {
            out << " transform_feedback_write_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT))
        {
            out << " transform_feedback_counter_read_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT))
        {
            out << " transform_feedback_counter_write_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT))
        {
            out << " conditional_rendering_read_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT))
        {
            out << " color_attachment_read_noncoherent_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR))
        {
            out << " acceleration_structure_read_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR))
        {
            out << " acceleration_structure_write_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV))
        {
            out << " shading_rate_image_read_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT))
        {
            out << " fragment_density_map_read_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV))
        {
            out << " command_preprocess_read_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV))
        {
            out << " command_preprocess_write_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCESS_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_ACCESS_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageAspectFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkImageAspectFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_COLOR_BIT))
        {
            out << " color_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_COLOR_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_DEPTH_BIT))
        {
            out << " depth_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_DEPTH_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_STENCIL_BIT))
        {
            out << " stencil_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_STENCIL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_METADATA_BIT))
        {
            out << " metadata_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_METADATA_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_0_BIT))
        {
            out << " plane_0_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_0_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_1_BIT))
        {
            out << " plane_1_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_1_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_2_BIT))
        {
            out << " plane_2_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_PLANE_2_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT))
        {
            out << " memory_plane_0_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT))
        {
            out << " memory_plane_1_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT))
        {
            out << " memory_plane_2_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT))
        {
            out << " memory_plane_3_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFormatFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkFormatFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT))
        {
            out << " sampled_image_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT))
        {
            out << " storage_image_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT))
        {
            out << " storage_image_atomic_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT))
        {
            out << " uniform_texel_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT))
        {
            out << " storage_texel_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT))
        {
            out << " storage_texel_buffer_atomic_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT))
        {
            out << " vertex_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT))
        {
            out << " color_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT))
        {
            out << " color_attachment_blend_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT))
        {
            out << " depth_stencil_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_BLIT_SRC_BIT))
        {
            out << " blit_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_BLIT_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_BLIT_DST_BIT))
        {
            out << " blit_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_BLIT_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT))
        {
            out << " sampled_image_filter_linear_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_TRANSFER_SRC_BIT))
        {
            out << " transfer_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_TRANSFER_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_TRANSFER_DST_BIT))
        {
            out << " transfer_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_TRANSFER_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT))
        {
            out << " midpoint_chroma_samples_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT))
        {
            out << " sampled_image_ycbcr_conversion_linear_filter_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT))
        {
            out << " sampled_image_ycbcr_conversion_separate_reconstruction_filter_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT))
        {
            out << " sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT))
        {
            out << " sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_forceable_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_DISJOINT_BIT))
        {
            out << " disjoint_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_DISJOINT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT))
        {
            out << " cosited_chroma_samples_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT))
        {
            out << " sampled_image_filter_minmax_bit";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG))
        {
            out << " sampled_image_filter_cubic_bit_img";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR))
        {
            out << " acceleration_structure_vertex_buffer_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT))
        {
            out << " fragment_density_map_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR))
        {
            out << " fragment_shading_rate_attachment_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkImageCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_BINDING_BIT))
        {
            out << " sparse_binding_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_BINDING_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT))
        {
            out << " sparse_residency_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_ALIASED_BIT))
        {
            out << " sparse_aliased_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SPARSE_ALIASED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT))
        {
            out << " mutable_format_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT))
        {
            out << " cube_compatible_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_ALIAS_BIT))
        {
            out << " alias_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_ALIAS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT))
        {
            out << " split_instance_bind_regions_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT))
        {
            out << " 2d_array_compatible_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT))
        {
            out << " block_texel_view_compatible_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_EXTENDED_USAGE_BIT))
        {
            out << " extended_usage_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_EXTENDED_USAGE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_DISJOINT_BIT))
        {
            out << " disjoint_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_DISJOINT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV))
        {
            out << " corner_sampled_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT))
        {
            out << " sample_locations_compatible_depth_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT))
        {
            out << " subsampled_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSampleCountFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSampleCountFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_1_BIT))
        {
            out << " 1_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_1_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_2_BIT))
        {
            out << " 2_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_2_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_4_BIT))
        {
            out << " 4_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_4_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_8_BIT))
        {
            out << " 8_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_8_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_16_BIT))
        {
            out << " 16_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_16_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_32_BIT))
        {
            out << " 32_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_32_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_64_BIT))
        {
            out << " 64_bit";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_64_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageUsageFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkImageUsageFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSFER_SRC_BIT))
        {
            out << " transfer_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSFER_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSFER_DST_BIT))
        {
            out << " transfer_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSFER_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_SAMPLED_BIT))
        {
            out << " sampled_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_SAMPLED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_STORAGE_BIT))
        {
            out << " storage_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_STORAGE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT))
        {
            out << " color_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT))
        {
            out << " depth_stencil_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT))
        {
            out << " transient_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT))
        {
            out << " input_attachment_bit";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV))
        {
            out << " shading_rate_image_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT))
        {
            out << " fragment_density_map_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkMemoryHeapFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkMemoryHeapFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_MEMORY_HEAP_DEVICE_LOCAL_BIT))
        {
            out << " device_local_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_HEAP_DEVICE_LOCAL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_HEAP_MULTI_INSTANCE_BIT))
        {
            out << " multi_instance_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_HEAP_MULTI_INSTANCE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkMemoryPropertyFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkMemoryPropertyFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT))
        {
            out << " device_local_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT))
        {
            out << " host_visible_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT))
        {
            out << " host_coherent_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_CACHED_BIT))
        {
            out << " host_cached_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_HOST_CACHED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT))
        {
            out << " lazily_allocated_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD))
        {
            out << " device_coherent_bit_amd";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD))
        {
            out << " device_uncached_bit_amd";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueueFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkQueueFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_QUEUE_GRAPHICS_BIT))
        {
            out << " graphics_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_GRAPHICS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUEUE_COMPUTE_BIT))
        {
            out << " compute_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_COMPUTE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUEUE_TRANSFER_BIT))
        {
            out << " transfer_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_TRANSFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUEUE_SPARSE_BINDING_BIT))
        {
            out << " sparse_binding_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_SPARSE_BINDING_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUEUE_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUEUE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_QUEUE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDeviceQueueCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkDeviceQueueCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineStageFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineStageFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT))
        {
            out << " top_of_pipe_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT))
        {
            out << " draw_indirect_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_VERTEX_INPUT_BIT))
        {
            out << " vertex_input_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_VERTEX_INPUT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_VERTEX_SHADER_BIT))
        {
            out << " vertex_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_VERTEX_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT))
        {
            out << " tessellation_control_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT))
        {
            out << " tessellation_evaluation_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT))
        {
            out << " geometry_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT))
        {
            out << " fragment_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT))
        {
            out << " early_fragment_tests_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT))
        {
            out << " late_fragment_tests_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT))
        {
            out << " color_attachment_output_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT))
        {
            out << " compute_shader_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TRANSFER_BIT))
        {
            out << " transfer_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TRANSFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT))
        {
            out << " bottom_of_pipe_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_HOST_BIT))
        {
            out << " host_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_HOST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT))
        {
            out << " all_graphics_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_ALL_COMMANDS_BIT))
        {
            out << " all_commands_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_ALL_COMMANDS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT))
        {
            out << " transform_feedback_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT))
        {
            out << " conditional_rendering_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR))
        {
            out << " acceleration_structure_build_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR))
        {
            out << " ray_tracing_shader_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV))
        {
            out << " shading_rate_image_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV))
        {
            out << " task_shader_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV))
        {
            out << " mesh_shader_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT))
        {
            out << " fragment_density_process_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV))
        {
            out << " command_preprocess_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSparseMemoryBindFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSparseMemoryBindFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SPARSE_MEMORY_BIND_METADATA_BIT))
        {
            out << " metadata_bit";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_MEMORY_BIND_METADATA_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSparseImageFormatFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSparseImageFormatFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT))
        {
            out << " single_miptail_bit";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT))
        {
            out << " aligned_mip_size_bit";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT))
        {
            out << " nonstandard_block_size_bit";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFenceCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkFenceCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_FENCE_CREATE_SIGNALED_BIT))
        {
            out << " signaled_bit";
            bits &= ~static_cast<enumIntType>(::VK_FENCE_CREATE_SIGNALED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueryPipelineStatisticFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkQueryPipelineStatisticFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT))
        {
            out << " input_assembly_vertices_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT))
        {
            out << " input_assembly_primitives_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT))
        {
            out << " vertex_shader_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT))
        {
            out << " geometry_shader_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT))
        {
            out << " geometry_shader_primitives_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT))
        {
            out << " clipping_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT))
        {
            out << " clipping_primitives_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT))
        {
            out << " fragment_shader_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT))
        {
            out << " tessellation_control_shader_patches_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT))
        {
            out << " tessellation_evaluation_shader_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT))
        {
            out << " compute_shader_invocations_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueryResultFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkQueryResultFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_QUERY_RESULT_64_BIT))
        {
            out << " 64_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_RESULT_64_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_RESULT_WAIT_BIT))
        {
            out << " wait_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_RESULT_WAIT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_RESULT_WITH_AVAILABILITY_BIT))
        {
            out << " with_availability_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_RESULT_WITH_AVAILABILITY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_RESULT_PARTIAL_BIT))
        {
            out << " partial_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_RESULT_PARTIAL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBufferCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkBufferCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_BINDING_BIT))
        {
            out << " sparse_binding_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_BINDING_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT))
        {
            out << " sparse_residency_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_ALIASED_BIT))
        {
            out << " sparse_aliased_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_SPARSE_ALIASED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT))
        {
            out << " device_address_capture_replay_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBufferUsageFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkBufferUsageFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFER_SRC_BIT))
        {
            out << " transfer_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFER_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFER_DST_BIT))
        {
            out << " transfer_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFER_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT))
        {
            out << " uniform_texel_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT))
        {
            out << " storage_texel_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT))
        {
            out << " uniform_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_STORAGE_BUFFER_BIT))
        {
            out << " storage_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_STORAGE_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_INDEX_BUFFER_BIT))
        {
            out << " index_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_INDEX_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT))
        {
            out << " vertex_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_VERTEX_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT))
        {
            out << " indirect_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT))
        {
            out << " shader_device_address_bit";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT))
        {
            out << " transform_feedback_buffer_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT))
        {
            out << " transform_feedback_counter_buffer_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT))
        {
            out << " conditional_rendering_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR))
        {
            out << " acceleration_structure_build_input_read_only_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR))
        {
            out << " acceleration_structure_storage_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR))
        {
            out << " shader_binding_table_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkImageViewCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkImageViewCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT))
        {
            out << " fragment_density_map_dynamic_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT))
        {
            out << " fragment_density_map_deferred_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_IMAGE_VIEW_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderModuleCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkShaderModuleCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SHADER_MODULE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " vk_shader_module_create_flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_MODULE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineCacheCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineCacheCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT))
        {
            out << " externally_synchronized_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CACHE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CACHE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkColorComponentFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkColorComponentFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COLOR_COMPONENT_R_BIT))
        {
            out << " r_bit";
            bits &= ~static_cast<enumIntType>(::VK_COLOR_COMPONENT_R_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COLOR_COMPONENT_G_BIT))
        {
            out << " g_bit";
            bits &= ~static_cast<enumIntType>(::VK_COLOR_COMPONENT_G_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COLOR_COMPONENT_B_BIT))
        {
            out << " b_bit";
            bits &= ~static_cast<enumIntType>(::VK_COLOR_COMPONENT_B_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COLOR_COMPONENT_A_BIT))
        {
            out << " a_bit";
            bits &= ~static_cast<enumIntType>(::VK_COLOR_COMPONENT_A_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT))
        {
            out << " disable_optimization_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT))
        {
            out << " allow_derivatives_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_DERIVATIVE_BIT))
        {
            out << " derivative_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_DERIVATIVE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT))
        {
            out << " view_index_from_device_index_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_DISPATCH_BASE_BIT))
        {
            out << " dispatch_base_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_DISPATCH_BASE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR))
        {
            out << " ray_tracing_no_null_any_hit_shaders_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR))
        {
            out << " ray_tracing_no_null_closest_hit_shaders_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR))
        {
            out << " ray_tracing_no_null_miss_shaders_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR))
        {
            out << " ray_tracing_no_null_intersection_shaders_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR))
        {
            out << " ray_tracing_skip_triangles_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR))
        {
            out << " ray_tracing_skip_aabbs_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR))
        {
            out << " ray_tracing_shader_group_handle_capture_replay_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV))
        {
            out << " defer_compile_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR))
        {
            out << " capture_statistics_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR))
        {
            out << " capture_internal_representations_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV))
        {
            out << " indirect_bindable_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_LIBRARY_BIT_KHR))
        {
            out << " library_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_LIBRARY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT))
        {
            out << " fail_on_pipeline_compile_required_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT))
        {
            out << " early_return_on_failure_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineShaderStageCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineShaderStageCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT))
        {
            out << " allow_varying_subgroup_size_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT))
        {
            out << " require_full_subgroups_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderStageFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkShaderStageFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_VERTEX_BIT))
        {
            out << " vertex_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_VERTEX_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT))
        {
            out << " tessellation_control_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT))
        {
            out << " tessellation_evaluation_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_GEOMETRY_BIT))
        {
            out << " geometry_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_GEOMETRY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_FRAGMENT_BIT))
        {
            out << " fragment_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_FRAGMENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_COMPUTE_BIT))
        {
            out << " compute_bit";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_COMPUTE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_ALL_GRAPHICS))
        {
            out << " all_graphics";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_ALL_GRAPHICS);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_ALL))
        {
            out << " all";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_ALL);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_RAYGEN_BIT_KHR))
        {
            out << " raygen_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_RAYGEN_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_ANY_HIT_BIT_KHR))
        {
            out << " any_hit_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_ANY_HIT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR))
        {
            out << " closest_hit_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_MISS_BIT_KHR))
        {
            out << " miss_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_MISS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_INTERSECTION_BIT_KHR))
        {
            out << " intersection_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_INTERSECTION_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_CALLABLE_BIT_KHR))
        {
            out << " callable_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_CALLABLE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_TASK_BIT_NV))
        {
            out << " task_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_TASK_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SHADER_STAGE_MESH_BIT_NV))
        {
            out << " mesh_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_STAGE_MESH_BIT_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCullModeFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkCullModeFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_CULL_MODE_NONE))
        {
            out << " none";
            bits &= ~static_cast<enumIntType>(::VK_CULL_MODE_NONE);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_CULL_MODE_FRONT_BIT))
        {
            out << " front_bit";
            bits &= ~static_cast<enumIntType>(::VK_CULL_MODE_FRONT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_CULL_MODE_BACK_BIT))
        {
            out << " back_bit";
            bits &= ~static_cast<enumIntType>(::VK_CULL_MODE_BACK_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_CULL_MODE_FRONT_AND_BACK))
        {
            out << " front_and_back";
            bits &= ~static_cast<enumIntType>(::VK_CULL_MODE_FRONT_AND_BACK);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_CULL_MODE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_CULL_MODE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT))
        {
            out << " subsampled_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT))
        {
            out << " subsampled_coarse_reconstruction_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDescriptorPoolCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkDescriptorPoolCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT))
        {
            out << " free_descriptor_set_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT))
        {
            out << " update_after_bind_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDescriptorSetLayoutCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkDescriptorSetLayoutCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT))
        {
            out << " update_after_bind_pool_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR))
        {
            out << " push_descriptor_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAttachmentDescriptionFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkAttachmentDescriptionFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT))
        {
            out << " may_alias_bit";
            bits &= ~static_cast<enumIntType>(::VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDependencyFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkDependencyFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEPENDENCY_BY_REGION_BIT))
        {
            out << " by_region_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEPENDENCY_BY_REGION_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEPENDENCY_DEVICE_GROUP_BIT))
        {
            out << " device_group_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEPENDENCY_DEVICE_GROUP_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEPENDENCY_VIEW_LOCAL_BIT))
        {
            out << " view_local_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEPENDENCY_VIEW_LOCAL_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEPENDENCY_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEPENDENCY_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFramebufferCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkFramebufferCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT))
        {
            out << " imageless_bit";
            bits &= ~static_cast<enumIntType>(::VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FRAMEBUFFER_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_FRAMEBUFFER_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkRenderPassCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkRenderPassCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM))
        {
            out << " transform_bit_qcom";
            bits &= ~static_cast<enumIntType>(::VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RENDER_PASS_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_RENDER_PASS_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSubpassDescriptionFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSubpassDescriptionFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX))
        {
            out << " per_view_attributes_bit_nvx";
            bits &= ~static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX))
        {
            out << " per_view_position_x_only_bit_nvx";
            bits &= ~static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM))
        {
            out << " fragment_region_bit_qcom";
            bits &= ~static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM))
        {
            out << " shader_resolve_bit_qcom";
            bits &= ~static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCommandPoolCreateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkCommandPoolCreateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT))
        {
            out << " transient_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_TRANSIENT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT))
        {
            out << " reset_command_buffer_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_PROTECTED_BIT))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_PROTECTED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCommandPoolResetFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkCommandPoolResetFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT))
        {
            out << " release_resources_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCommandBufferUsageFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkCommandBufferUsageFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT))
        {
            out << " one_time_submit_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT))
        {
            out << " render_pass_continue_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT))
        {
            out << " simultaneous_use_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueryControlFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkQueryControlFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_QUERY_CONTROL_PRECISE_BIT))
        {
            out << " precise_bit";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_CONTROL_PRECISE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCommandBufferResetFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkCommandBufferResetFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT))
        {
            out << " release_resources_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkStencilFaceFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkStencilFaceFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_STENCIL_FACE_FRONT_BIT))
        {
            out << " face_front_bit";
            bits &= ~static_cast<enumIntType>(::VK_STENCIL_FACE_FRONT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_STENCIL_FACE_BACK_BIT))
        {
            out << " face_back_bit";
            bits &= ~static_cast<enumIntType>(::VK_STENCIL_FACE_BACK_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_STENCIL_FACE_FRONT_AND_BACK))
        {
            out << " face_front_and_back";
            bits &= ~static_cast<enumIntType>(::VK_STENCIL_FACE_FRONT_AND_BACK);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM))
        {
            out << " face_flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPointClippingBehavior obj)
    {
        using enumIntType = std::underlying_type<::VkPointClippingBehavior>::type;
        switch (obj)
        {
        case ::VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES: out << "all_clip_planes"; break;
        case ::VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY: out << "user_clip_planes_only"; break;
        case ::VK_POINT_CLIPPING_BEHAVIOR_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkTessellationDomainOrigin obj)
    {
        using enumIntType = std::underlying_type<::VkTessellationDomainOrigin>::type;
        switch (obj)
        {
        case ::VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT: out << "upper_left"; break;
        case ::VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT: out << "lower_left"; break;
        case ::VK_TESSELLATION_DOMAIN_ORIGIN_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerYcbcrModelConversion obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerYcbcrModelConversion>::type;
        switch (obj)
        {
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY: out << "rgb_identity"; break;
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY: out << "ycbcr_identity"; break;
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709: out << "ycbcr_709"; break;
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601: out << "ycbcr_601"; break;
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020: out << "ycbcr_2020"; break;
        case ::VK_SAMPLER_YCBCR_MODEL_CONVERSION_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerYcbcrRange obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerYcbcrRange>::type;
        switch (obj)
        {
        case ::VK_SAMPLER_YCBCR_RANGE_ITU_FULL: out << "itu_full"; break;
        case ::VK_SAMPLER_YCBCR_RANGE_ITU_NARROW: out << "itu_narrow"; break;
        case ::VK_SAMPLER_YCBCR_RANGE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkChromaLocation obj)
    {
        using enumIntType = std::underlying_type<::VkChromaLocation>::type;
        switch (obj)
        {
        case ::VK_CHROMA_LOCATION_COSITED_EVEN: out << "cosited_even"; break;
        case ::VK_CHROMA_LOCATION_MIDPOINT: out << "midpoint"; break;
        case ::VK_CHROMA_LOCATION_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDescriptorUpdateTemplateType obj)
    {
        using enumIntType = std::underlying_type<::VkDescriptorUpdateTemplateType>::type;
        switch (obj)
        {
        case ::VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET: out << "descriptor_set"; break;
        case ::VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR: out << "push_descriptors_khr"; break;
        case ::VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSubgroupFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSubgroupFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_BASIC_BIT))
        {
            out << " basic_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_BASIC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_VOTE_BIT))
        {
            out << " vote_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_VOTE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_ARITHMETIC_BIT))
        {
            out << " arithmetic_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_ARITHMETIC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_BALLOT_BIT))
        {
            out << " ballot_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_BALLOT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_SHUFFLE_BIT))
        {
            out << " shuffle_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_SHUFFLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT))
        {
            out << " shuffle_relative_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_CLUSTERED_BIT))
        {
            out << " clustered_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_CLUSTERED_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_QUAD_BIT))
        {
            out << " quad_bit";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_QUAD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV))
        {
            out << " partitioned_bit_nv";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPeerMemoryFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkPeerMemoryFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT))
        {
            out << " copy_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_COPY_DST_BIT))
        {
            out << " copy_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_COPY_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT))
        {
            out << " generic_src_bit";
            bits &= ~static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT))
        {
            out << " generic_dst_bit";
            bits &= ~static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PEER_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkMemoryAllocateFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkMemoryAllocateFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT))
        {
            out << " device_mask_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT))
        {
            out << " device_address_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT))
        {
            out << " device_address_capture_replay_bit";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_MEMORY_ALLOCATE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryHandleTypeFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalMemoryHandleTypeFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT))
        {
            out << " opaque_fd_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT))
        {
            out << " opaque_win32_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT))
        {
            out << " opaque_win32_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT))
        {
            out << " d3d11_texture_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT))
        {
            out << " d3d11_texture_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT))
        {
            out << " d3d12_heap_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT))
        {
            out << " d3d12_resource_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT))
        {
            out << " dma_buf_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID))
        {
            out << " android_hardware_buffer_bit_android";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT))
        {
            out << " host_allocation_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT))
        {
            out << " host_mapped_foreign_memory_bit_ext";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalMemoryFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT))
        {
            out << " dedicated_only_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT))
        {
            out << " exportable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT))
        {
            out << " importable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalFenceHandleTypeFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalFenceHandleTypeFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT))
        {
            out << " opaque_fd_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT))
        {
            out << " opaque_win32_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT))
        {
            out << " opaque_win32_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT))
        {
            out << " sync_fd_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalFenceFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalFenceFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT))
        {
            out << " exportable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT))
        {
            out << " importable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFenceImportFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkFenceImportFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_FENCE_IMPORT_TEMPORARY_BIT))
        {
            out << " temporary_bit";
            bits &= ~static_cast<enumIntType>(::VK_FENCE_IMPORT_TEMPORARY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSemaphoreImportFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSemaphoreImportFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SEMAPHORE_IMPORT_TEMPORARY_BIT))
        {
            out << " temporary_bit";
            bits &= ~static_cast<enumIntType>(::VK_SEMAPHORE_IMPORT_TEMPORARY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalSemaphoreHandleTypeFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalSemaphoreHandleTypeFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT))
        {
            out << " opaque_fd_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT))
        {
            out << " opaque_win32_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT))
        {
            out << " opaque_win32_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT))
        {
            out << " d3d12_fence_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT))
        {
            out << " sync_fd_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalSemaphoreFeatureFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkExternalSemaphoreFeatureFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT))
        {
            out << " exportable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT))
        {
            out << " importable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDriverId obj)
    {
        using enumIntType = std::underlying_type<::VkDriverId>::type;
        switch (obj)
        {
        case ::VK_DRIVER_ID_AMD_PROPRIETARY: out << "amd_proprietary"; break;
        case ::VK_DRIVER_ID_AMD_OPEN_SOURCE: out << "amd_open_source"; break;
        case ::VK_DRIVER_ID_MESA_RADV: out << "mesa_radv"; break;
        case ::VK_DRIVER_ID_NVIDIA_PROPRIETARY: out << "nvidia_proprietary"; break;
        case ::VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS: out << "intel_proprietary_windows"; break;
        case ::VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA: out << "intel_open_source_mesa"; break;
        case ::VK_DRIVER_ID_IMAGINATION_PROPRIETARY: out << "imagination_proprietary"; break;
        case ::VK_DRIVER_ID_QUALCOMM_PROPRIETARY: out << "qualcomm_proprietary"; break;
        case ::VK_DRIVER_ID_ARM_PROPRIETARY: out << "arm_proprietary"; break;
        case ::VK_DRIVER_ID_GOOGLE_SWIFTSHADER: out << "google_swiftshader"; break;
        case ::VK_DRIVER_ID_GGP_PROPRIETARY: out << "ggp_proprietary"; break;
        case ::VK_DRIVER_ID_BROADCOM_PROPRIETARY: out << "broadcom_proprietary"; break;
        case ::VK_DRIVER_ID_MESA_LLVMPIPE: out << "mesa_llvmpipe"; break;
        case ::VK_DRIVER_ID_MOLTENVK: out << "moltenvk"; break;
        case ::VK_DRIVER_ID_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderFloatControlsIndependence obj)
    {
        using enumIntType = std::underlying_type<::VkShaderFloatControlsIndependence>::type;
        switch (obj)
        {
        case ::VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY: out << "32_bit_only"; break;
        case ::VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL: out << "all"; break;
        case ::VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE: out << "none"; break;
        case ::VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSamplerReductionMode obj)
    {
        using enumIntType = std::underlying_type<::VkSamplerReductionMode>::type;
        switch (obj)
        {
        case ::VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE: out << "weighted_average"; break;
        case ::VK_SAMPLER_REDUCTION_MODE_MIN: out << "min"; break;
        case ::VK_SAMPLER_REDUCTION_MODE_MAX: out << "max"; break;
        case ::VK_SAMPLER_REDUCTION_MODE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSemaphoreType obj)
    {
        using enumIntType = std::underlying_type<::VkSemaphoreType>::type;
        switch (obj)
        {
        case ::VK_SEMAPHORE_TYPE_BINARY: out << "binary"; break;
        case ::VK_SEMAPHORE_TYPE_TIMELINE: out << "timeline"; break;
        case ::VK_SEMAPHORE_TYPE_MAX_ENUM: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkResolveModeFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkResolveModeFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_NONE))
        {
            out << " none";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_NONE);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_SAMPLE_ZERO_BIT))
        {
            out << " sample_zero_bit";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_SAMPLE_ZERO_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_AVERAGE_BIT))
        {
            out << " average_bit";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_AVERAGE_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_MIN_BIT))
        {
            out << " min_bit";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_MIN_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_MAX_BIT))
        {
            out << " max_bit";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_MAX_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDescriptorBindingFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkDescriptorBindingFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT))
        {
            out << " update_after_bind_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT))
        {
            out << " update_unused_while_pending_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT))
        {
            out << " partially_bound_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT))
        {
            out << " variable_descriptor_count_bit";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSemaphoreWaitFlagBits obj)
    {
        using enumIntType = std::underlying_type<::VkSemaphoreWaitFlagBits>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SEMAPHORE_WAIT_ANY_BIT))
        {
            out << " any_bit";
            bits &= ~static_cast<enumIntType>(::VK_SEMAPHORE_WAIT_ANY_BIT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPresentModeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPresentModeKHR>::type;
        switch (obj)
        {
        case ::VK_PRESENT_MODE_IMMEDIATE_KHR: out << "immediate"; break;
        case ::VK_PRESENT_MODE_MAILBOX_KHR: out << "mailbox"; break;
        case ::VK_PRESENT_MODE_FIFO_KHR: out << "fifo"; break;
        case ::VK_PRESENT_MODE_FIFO_RELAXED_KHR: out << "fifo_relaxed"; break;
        case ::VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR: out << "shared_demand_refresh"; break;
        case ::VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR: out << "shared_continuous_refresh"; break;
        case ::VK_PRESENT_MODE_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkColorSpaceKHR obj)
    {
        using enumIntType = std::underlying_type<::VkColorSpaceKHR>::type;
        switch (obj)
        {
        case ::VK_COLOR_SPACE_SRGB_NONLINEAR_KHR: out << "color_space_srgb_nonlinear_khr"; break;
        case ::VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT: out << "color_space_display_p3_nonlinear_ext"; break;
        case ::VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT: out << "color_space_extended_srgb_linear_ext"; break;
        case ::VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT: out << "color_space_display_p3_linear_ext"; break;
        case ::VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT: out << "color_space_dci_p3_nonlinear_ext"; break;
        case ::VK_COLOR_SPACE_BT709_LINEAR_EXT: out << "color_space_bt709_linear_ext"; break;
        case ::VK_COLOR_SPACE_BT709_NONLINEAR_EXT: out << "color_space_bt709_nonlinear_ext"; break;
        case ::VK_COLOR_SPACE_BT2020_LINEAR_EXT: out << "color_space_bt2020_linear_ext"; break;
        case ::VK_COLOR_SPACE_HDR10_ST2084_EXT: out << "color_space_hdr10_st2084_ext"; break;
        case ::VK_COLOR_SPACE_DOLBYVISION_EXT: out << "color_space_dolbyvision_ext"; break;
        case ::VK_COLOR_SPACE_HDR10_HLG_EXT: out << "color_space_hdr10_hlg_ext"; break;
        case ::VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT: out << "color_space_adobergb_linear_ext"; break;
        case ::VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT: out << "color_space_adobergb_nonlinear_ext"; break;
        case ::VK_COLOR_SPACE_PASS_THROUGH_EXT: out << "color_space_pass_through_ext"; break;
        case ::VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT: out << "color_space_extended_srgb_nonlinear_ext"; break;
        case ::VK_COLOR_SPACE_DISPLAY_NATIVE_AMD: out << "color_space_display_native_amd"; break;
        case ::VK_COLOR_SPACE_MAX_ENUM_KHR: out << "color_space_max_enum_khr"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSurfaceTransformFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkSurfaceTransformFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR))
        {
            out << " identity_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR))
        {
            out << " rotate_90_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR))
        {
            out << " rotate_180_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR))
        {
            out << " rotate_270_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR))
        {
            out << " horizontal_mirror_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR))
        {
            out << " horizontal_mirror_rotate_90_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR))
        {
            out << " horizontal_mirror_rotate_180_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR))
        {
            out << " horizontal_mirror_rotate_270_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR))
        {
            out << " inherit_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCompositeAlphaFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkCompositeAlphaFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR))
        {
            out << " opaque_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR))
        {
            out << " pre_multiplied_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR))
        {
            out << " post_multiplied_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR))
        {
            out << " inherit_bit";
            bits &= ~static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSwapchainCreateFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkSwapchainCreateFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR))
        {
            out << " split_instance_bind_regions_bit";
            bits &= ~static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR))
        {
            out << " protected_bit";
            bits &= ~static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR))
        {
            out << " mutable_format_bit";
            bits &= ~static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDeviceGroupPresentModeFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkDeviceGroupPresentModeFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR))
        {
            out << " local_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR))
        {
            out << " remote_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR))
        {
            out << " sum_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR))
        {
            out << " local_multi_device_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDisplayPlaneAlphaFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkDisplayPlaneAlphaFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR))
        {
            out << " opaque_bit";
            bits &= ~static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR))
        {
            out << " global_bit";
            bits &= ~static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR))
        {
            out << " per_pixel_bit";
            bits &= ~static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR))
        {
            out << " per_pixel_premultiplied_bit";
            bits &= ~static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterUnitKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceCounterUnitKHR>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR: out << "generic"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR: out << "percentage"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR: out << "nanoseconds"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR: out << "bytes"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR: out << "bytes_per_second"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR: out << "kelvin"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR: out << "watts"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR: out << "volts"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR: out << "amps"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR: out << "hertz"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR: out << "cycles"; break;
        case ::VK_PERFORMANCE_COUNTER_UNIT_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterScopeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceCounterScopeKHR>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR: out << "performance_counter_scope_command_buffer"; break;
        case ::VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR: out << "performance_counter_scope_render_pass"; break;
        case ::VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR: out << "performance_counter_scope_command"; break;
        case ::VK_PERFORMANCE_COUNTER_SCOPE_MAX_ENUM_KHR: out << "performance_counter_scope_max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterStorageKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceCounterStorageKHR>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR: out << "int32"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR: out << "int64"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR: out << "uint32"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR: out << "uint64"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR: out << "float32"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR: out << "float64"; break;
        case ::VK_PERFORMANCE_COUNTER_STORAGE_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceCounterDescriptionFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceCounterDescriptionFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR))
        {
            out << " performance_impacting_bit";
            bits &= ~static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR))
        {
            out << " concurrently_impacted_bit";
            bits &= ~static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAcquireProfilingLockFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkAcquireProfilingLockFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_ACQUIRE_PROFILING_LOCK_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " vk_acquire_profiling_lock_flag_bits_max_enum_khr";
            bits &= ~static_cast<enumIntType>(::VK_ACQUIRE_PROFILING_LOCK_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateCombinerOpKHR obj)
    {
        using enumIntType = std::underlying_type<::VkFragmentShadingRateCombinerOpKHR>::type;
        switch (obj)
        {
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR: out << "keep"; break;
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR: out << "replace"; break;
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR: out << "min"; break;
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR: out << "max"; break;
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR: out << "mul"; break;
        case ::VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineExecutableStatisticFormatKHR obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineExecutableStatisticFormatKHR>::type;
        switch (obj)
        {
        case ::VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR: out << "bool32"; break;
        case ::VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR: out << "int64"; break;
        case ::VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR: out << "uint64"; break;
        case ::VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR: out << "float64"; break;
        case ::VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDebugReportObjectTypeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDebugReportObjectTypeEXT>::type;
        switch (obj)
        {
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT: out << "unknown"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT: out << "instance"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT: out << "physical_device"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT: out << "device"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT: out << "queue"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT: out << "semaphore"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT: out << "command_buffer"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT: out << "fence"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT: out << "device_memory"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT: out << "buffer"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT: out << "image"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT: out << "event"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT: out << "query_pool"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT: out << "buffer_view"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT: out << "image_view"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT: out << "shader_module"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT: out << "pipeline_cache"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT: out << "pipeline_layout"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT: out << "render_pass"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT: out << "pipeline"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT: out << "descriptor_set_layout"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT: out << "sampler"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT: out << "descriptor_pool"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT: out << "descriptor_set"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT: out << "framebuffer"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT: out << "command_pool"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT: out << "surface_khr"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT: out << "swapchain_khr"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT: out << "debug_report_callback_ext"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT: out << "display_khr"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT: out << "display_mode_khr"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT: out << "validation_cache_ext"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT: out << "sampler_ycbcr_conversion"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT: out << "descriptor_update_template"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT: out << "acceleration_structure_khr"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT: out << "acceleration_structure_nv"; break;
        case ::VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDebugReportFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDebugReportFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_INFORMATION_BIT_EXT))
        {
            out << " information_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_INFORMATION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_WARNING_BIT_EXT))
        {
            out << " warning_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_WARNING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT))
        {
            out << " performance_warning_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_ERROR_BIT_EXT))
        {
            out << " error_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_ERROR_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_DEBUG_BIT_EXT))
        {
            out << " debug_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_DEBUG_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkRasterizationOrderAMD obj)
    {
        using enumIntType = std::underlying_type<::VkRasterizationOrderAMD>::type;
        switch (obj)
        {
        case ::VK_RASTERIZATION_ORDER_STRICT_AMD: out << "strict"; break;
        case ::VK_RASTERIZATION_ORDER_RELAXED_AMD: out << "relaxed"; break;
        case ::VK_RASTERIZATION_ORDER_MAX_ENUM_AMD: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderInfoTypeAMD obj)
    {
        using enumIntType = std::underlying_type<::VkShaderInfoTypeAMD>::type;
        switch (obj)
        {
        case ::VK_SHADER_INFO_TYPE_STATISTICS_AMD: out << "statistics"; break;
        case ::VK_SHADER_INFO_TYPE_BINARY_AMD: out << "binary"; break;
        case ::VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD: out << "disassembly"; break;
        case ::VK_SHADER_INFO_TYPE_MAX_ENUM_AMD: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryHandleTypeFlagBitsNV obj)
    {
        using enumIntType = std::underlying_type<::VkExternalMemoryHandleTypeFlagBitsNV>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV))
        {
            out << " opaque_win32_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV))
        {
            out << " opaque_win32_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV))
        {
            out << " d3d11_image_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV))
        {
            out << " d3d11_image_kmt_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkExternalMemoryFeatureFlagBitsNV obj)
    {
        using enumIntType = std::underlying_type<::VkExternalMemoryFeatureFlagBitsNV>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV))
        {
            out << " dedicated_only_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV))
        {
            out << " exportable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV))
        {
            out << " importable_bit";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkValidationCheckEXT obj)
    {
        using enumIntType = std::underlying_type<::VkValidationCheckEXT>::type;
        switch (obj)
        {
        case ::VK_VALIDATION_CHECK_ALL_EXT: out << "all"; break;
        case ::VK_VALIDATION_CHECK_SHADERS_EXT: out << "shaders"; break;
        case ::VK_VALIDATION_CHECK_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkConditionalRenderingFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkConditionalRenderingFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT))
        {
            out << " inverted_bit";
            bits &= ~static_cast<enumIntType>(::VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_CONDITIONAL_RENDERING_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_CONDITIONAL_RENDERING_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkSurfaceCounterFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkSurfaceCounterFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SURFACE_COUNTER_VBLANK_BIT_EXT))
        {
            out << " vblank_bit";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_COUNTER_VBLANK_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDisplayPowerStateEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDisplayPowerStateEXT>::type;
        switch (obj)
        {
        case ::VK_DISPLAY_POWER_STATE_OFF_EXT: out << "off"; break;
        case ::VK_DISPLAY_POWER_STATE_SUSPEND_EXT: out << "suspend"; break;
        case ::VK_DISPLAY_POWER_STATE_ON_EXT: out << "on"; break;
        case ::VK_DISPLAY_POWER_STATE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDeviceEventTypeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDeviceEventTypeEXT>::type;
        switch (obj)
        {
        case ::VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT: out << "display_hotplug"; break;
        case ::VK_DEVICE_EVENT_TYPE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDisplayEventTypeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDisplayEventTypeEXT>::type;
        switch (obj)
        {
        case ::VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT: out << "first_pixel_out"; break;
        case ::VK_DISPLAY_EVENT_TYPE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkViewportCoordinateSwizzleNV obj)
    {
        using enumIntType = std::underlying_type<::VkViewportCoordinateSwizzleNV>::type;
        switch (obj)
        {
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV: out << "positive_x"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV: out << "negative_x"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV: out << "positive_y"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV: out << "negative_y"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV: out << "positive_z"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV: out << "negative_z"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV: out << "positive_w"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV: out << "negative_w"; break;
        case ::VK_VIEWPORT_COORDINATE_SWIZZLE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDiscardRectangleModeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDiscardRectangleModeEXT>::type;
        switch (obj)
        {
        case ::VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT: out << "inclusive"; break;
        case ::VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT: out << "exclusive"; break;
        case ::VK_DISCARD_RECTANGLE_MODE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkConservativeRasterizationModeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkConservativeRasterizationModeEXT>::type;
        switch (obj)
        {
        case ::VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT: out << "disabled"; break;
        case ::VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT: out << "overestimate"; break;
        case ::VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT: out << "underestimate"; break;
        case ::VK_CONSERVATIVE_RASTERIZATION_MODE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDebugUtilsMessageSeverityFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDebugUtilsMessageSeverityFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT))
        {
            out << " verbose_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT))
        {
            out << " info_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT))
        {
            out << " warning_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT))
        {
            out << " error_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDebugUtilsMessageTypeFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDebugUtilsMessageTypeFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT))
        {
            out << " general_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT))
        {
            out << " validation_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT))
        {
            out << " performance_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBlendOverlapEXT obj)
    {
        using enumIntType = std::underlying_type<::VkBlendOverlapEXT>::type;
        switch (obj)
        {
        case ::VK_BLEND_OVERLAP_UNCORRELATED_EXT: out << "uncorrelated"; break;
        case ::VK_BLEND_OVERLAP_DISJOINT_EXT: out << "disjoint"; break;
        case ::VK_BLEND_OVERLAP_CONJOINT_EXT: out << "conjoint"; break;
        case ::VK_BLEND_OVERLAP_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCoverageModulationModeNV obj)
    {
        using enumIntType = std::underlying_type<::VkCoverageModulationModeNV>::type;
        switch (obj)
        {
        case ::VK_COVERAGE_MODULATION_MODE_NONE_NV: out << "none"; break;
        case ::VK_COVERAGE_MODULATION_MODE_RGB_NV: out << "rgb"; break;
        case ::VK_COVERAGE_MODULATION_MODE_ALPHA_NV: out << "alpha"; break;
        case ::VK_COVERAGE_MODULATION_MODE_RGBA_NV: out << "rgba"; break;
        case ::VK_COVERAGE_MODULATION_MODE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkValidationCacheHeaderVersionEXT obj)
    {
        using enumIntType = std::underlying_type<::VkValidationCacheHeaderVersionEXT>::type;
        switch (obj)
        {
        case ::VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT: out << "one"; break;
        case ::VK_VALIDATION_CACHE_HEADER_VERSION_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShadingRatePaletteEntryNV obj)
    {
        using enumIntType = std::underlying_type<::VkShadingRatePaletteEntryNV>::type;
        switch (obj)
        {
        case ::VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV: out << "no_invocations"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV: out << "16_invocations_per_pixel"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV: out << "8_invocations_per_pixel"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV: out << "4_invocations_per_pixel"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV: out << "2_invocations_per_pixel"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV: out << "1_invocation_per_pixel"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV: out << "1_invocation_per_2x1_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV: out << "1_invocation_per_1x2_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV: out << "1_invocation_per_2x2_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV: out << "1_invocation_per_4x2_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV: out << "1_invocation_per_2x4_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV: out << "1_invocation_per_4x4_pixels"; break;
        case ::VK_SHADING_RATE_PALETTE_ENTRY_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCoarseSampleOrderTypeNV obj)
    {
        using enumIntType = std::underlying_type<::VkCoarseSampleOrderTypeNV>::type;
        switch (obj)
        {
        case ::VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV: out << "default"; break;
        case ::VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV: out << "custom"; break;
        case ::VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV: out << "pixel_major"; break;
        case ::VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV: out << "sample_major"; break;
        case ::VK_COARSE_SAMPLE_ORDER_TYPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkRayTracingShaderGroupTypeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkRayTracingShaderGroupTypeKHR>::type;
        switch (obj)
        {
        case ::VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR: out << "general_khr"; break;
        case ::VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR: out << "triangles_hit_group_khr"; break;
        case ::VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR: out << "procedural_hit_group_khr"; break;
        case ::VK_RAY_TRACING_SHADER_GROUP_TYPE_MAX_ENUM_KHR: out << "max_enum_khr"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkGeometryTypeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkGeometryTypeKHR>::type;
        switch (obj)
        {
        case ::VK_GEOMETRY_TYPE_TRIANGLES_KHR: out << "triangles_khr"; break;
        case ::VK_GEOMETRY_TYPE_AABBS_KHR: out << "aabbs_khr"; break;
        case ::VK_GEOMETRY_TYPE_INSTANCES_KHR: out << "instances_khr"; break;
        case ::VK_GEOMETRY_TYPE_MAX_ENUM_KHR: out << "max_enum_khr"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureTypeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkAccelerationStructureTypeKHR>::type;
        switch (obj)
        {
        case ::VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR: out << "top_level_khr"; break;
        case ::VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR: out << "bottom_level_khr"; break;
        case ::VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR: out << "generic_khr"; break;
        case ::VK_ACCELERATION_STRUCTURE_TYPE_MAX_ENUM_KHR: out << "max_enum_khr"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCopyAccelerationStructureModeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkCopyAccelerationStructureModeKHR>::type;
        switch (obj)
        {
        case ::VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR: out << "clone_khr"; break;
        case ::VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR: out << "compact_khr"; break;
        case ::VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR: out << "serialize_khr"; break;
        case ::VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR: out << "deserialize_khr"; break;
        case ::VK_COPY_ACCELERATION_STRUCTURE_MODE_MAX_ENUM_KHR: out << "max_enum_khr"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureMemoryRequirementsTypeNV obj)
    {
        using enumIntType = std::underlying_type<::VkAccelerationStructureMemoryRequirementsTypeNV>::type;
        switch (obj)
        {
        case ::VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV: out << "object"; break;
        case ::VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV: out << "build_scratch"; break;
        case ::VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV: out << "update_scratch"; break;
        case ::VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkGeometryFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkGeometryFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_OPAQUE_BIT_KHR))
        {
            out << " opaque_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_OPAQUE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR))
        {
            out << " no_duplicate_any_hit_invocation_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkGeometryInstanceFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkGeometryInstanceFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR))
        {
            out << " triangle_facing_cull_disable_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR))
        {
            out << " triangle_front_counterclockwise_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR))
        {
            out << " force_opaque_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR))
        {
            out << " force_no_opaque_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum_khr";
            bits &= ~static_cast<enumIntType>(::VK_GEOMETRY_INSTANCE_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBuildAccelerationStructureFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkBuildAccelerationStructureFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR))
        {
            out << " allow_update_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR))
        {
            out << " allow_compaction_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR))
        {
            out << " prefer_fast_trace_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR))
        {
            out << " prefer_fast_build_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR))
        {
            out << " low_memory_bit_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum_khr";
            bits &= ~static_cast<enumIntType>(::VK_BUILD_ACCELERATION_STRUCTURE_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueueGlobalPriorityEXT obj)
    {
        using enumIntType = std::underlying_type<::VkQueueGlobalPriorityEXT>::type;
        switch (obj)
        {
        case ::VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT: out << "low"; break;
        case ::VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT: out << "medium"; break;
        case ::VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT: out << "high"; break;
        case ::VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT: out << "realtime"; break;
        case ::VK_QUEUE_GLOBAL_PRIORITY_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineCompilerControlFlagBitsAMD obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineCompilerControlFlagBitsAMD>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_COMPILER_CONTROL_FLAG_BITS_MAX_ENUM_AMD))
        {
            out << " vk_pipeline_compiler_control_flag_bits_max_enum_amd";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_COMPILER_CONTROL_FLAG_BITS_MAX_ENUM_AMD);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkTimeDomainEXT obj)
    {
        using enumIntType = std::underlying_type<::VkTimeDomainEXT>::type;
        switch (obj)
        {
        case ::VK_TIME_DOMAIN_DEVICE_EXT: out << "device"; break;
        case ::VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT: out << "clock_monotonic"; break;
        case ::VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT: out << "clock_monotonic_raw"; break;
        case ::VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT: out << "query_performance_counter"; break;
        case ::VK_TIME_DOMAIN_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkMemoryOverallocationBehaviorAMD obj)
    {
        using enumIntType = std::underlying_type<::VkMemoryOverallocationBehaviorAMD>::type;
        switch (obj)
        {
        case ::VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD: out << "default"; break;
        case ::VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD: out << "allowed"; break;
        case ::VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD: out << "disallowed"; break;
        case ::VK_MEMORY_OVERALLOCATION_BEHAVIOR_MAX_ENUM_AMD: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPipelineCreationFeedbackFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkPipelineCreationFeedbackFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT))
        {
            out << " valid_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT))
        {
            out << " application_pipeline_cache_hit_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT))
        {
            out << " base_pipeline_acceleration_bit";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_PIPELINE_CREATION_FEEDBACK_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceConfigurationTypeINTEL obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceConfigurationTypeINTEL>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL: out << "command_queue_metrics_discovery_activated"; break;
        case ::VK_PERFORMANCE_CONFIGURATION_TYPE_MAX_ENUM_INTEL: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkQueryPoolSamplingModeINTEL obj)
    {
        using enumIntType = std::underlying_type<::VkQueryPoolSamplingModeINTEL>::type;
        switch (obj)
        {
        case ::VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL: out << "manual"; break;
        case ::VK_QUERY_POOL_SAMPLING_MODE_MAX_ENUM_INTEL: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceOverrideTypeINTEL obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceOverrideTypeINTEL>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL: out << "null_hardware"; break;
        case ::VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL: out << "flush_gpu_caches"; break;
        case ::VK_PERFORMANCE_OVERRIDE_TYPE_MAX_ENUM_INTEL: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceParameterTypeINTEL obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceParameterTypeINTEL>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL: out << "hw_counters_supported"; break;
        case ::VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL: out << "stream_marker_valid_bits"; break;
        case ::VK_PERFORMANCE_PARAMETER_TYPE_MAX_ENUM_INTEL: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPerformanceValueTypeINTEL obj)
    {
        using enumIntType = std::underlying_type<::VkPerformanceValueTypeINTEL>::type;
        switch (obj)
        {
        case ::VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL: out << "uint32"; break;
        case ::VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL: out << "uint64"; break;
        case ::VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL: out << "float"; break;
        case ::VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL: out << "bool"; break;
        case ::VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL: out << "string"; break;
        case ::VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderCorePropertiesFlagBitsAMD obj)
    {
        using enumIntType = std::underlying_type<::VkShaderCorePropertiesFlagBitsAMD>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_SHADER_CORE_PROPERTIES_FLAG_BITS_MAX_ENUM_AMD))
        {
            out << " vk_shader_core_properties_flag_bits_max_enum_amd";
            bits &= ~static_cast<enumIntType>(::VK_SHADER_CORE_PROPERTIES_FLAG_BITS_MAX_ENUM_AMD);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkToolPurposeFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkToolPurposeFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_VALIDATION_BIT_EXT))
        {
            out << " validation_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_VALIDATION_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_PROFILING_BIT_EXT))
        {
            out << " profiling_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_PROFILING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_TRACING_BIT_EXT))
        {
            out << " tracing_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_TRACING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT))
        {
            out << " additional_features_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT))
        {
            out << " modifying_features_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT))
        {
            out << " debug_reporting_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT))
        {
            out << " debug_markers_bit";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_TOOL_PURPOSE_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_TOOL_PURPOSE_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkValidationFeatureEnableEXT obj)
    {
        using enumIntType = std::underlying_type<::VkValidationFeatureEnableEXT>::type;
        switch (obj)
        {
        case ::VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT: out << "gpu_assisted"; break;
        case ::VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT: out << "gpu_assisted_reserve_binding_slot"; break;
        case ::VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT: out << "best_practices"; break;
        case ::VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT: out << "debug_printf"; break;
        case ::VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT: out << "synchronization_validation"; break;
        case ::VK_VALIDATION_FEATURE_ENABLE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkValidationFeatureDisableEXT obj)
    {
        using enumIntType = std::underlying_type<::VkValidationFeatureDisableEXT>::type;
        switch (obj)
        {
        case ::VK_VALIDATION_FEATURE_DISABLE_ALL_EXT: out << "all"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT: out << "shaders"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT: out << "thread_safety"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT: out << "api_parameters"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT: out << "object_lifetimes"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT: out << "core_checks"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT: out << "unique_handles"; break;
        case ::VK_VALIDATION_FEATURE_DISABLE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkComponentTypeNV obj)
    {
        using enumIntType = std::underlying_type<::VkComponentTypeNV>::type;
        switch (obj)
        {
        case ::VK_COMPONENT_TYPE_FLOAT16_NV: out << "float16"; break;
        case ::VK_COMPONENT_TYPE_FLOAT32_NV: out << "float32"; break;
        case ::VK_COMPONENT_TYPE_FLOAT64_NV: out << "float64"; break;
        case ::VK_COMPONENT_TYPE_SINT8_NV: out << "sint8"; break;
        case ::VK_COMPONENT_TYPE_SINT16_NV: out << "sint16"; break;
        case ::VK_COMPONENT_TYPE_SINT32_NV: out << "sint32"; break;
        case ::VK_COMPONENT_TYPE_SINT64_NV: out << "sint64"; break;
        case ::VK_COMPONENT_TYPE_UINT8_NV: out << "uint8"; break;
        case ::VK_COMPONENT_TYPE_UINT16_NV: out << "uint16"; break;
        case ::VK_COMPONENT_TYPE_UINT32_NV: out << "uint32"; break;
        case ::VK_COMPONENT_TYPE_UINT64_NV: out << "uint64"; break;
        case ::VK_COMPONENT_TYPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkScopeNV obj)
    {
        using enumIntType = std::underlying_type<::VkScopeNV>::type;
        switch (obj)
        {
        case ::VK_SCOPE_DEVICE_NV: out << "device"; break;
        case ::VK_SCOPE_WORKGROUP_NV: out << "workgroup"; break;
        case ::VK_SCOPE_SUBGROUP_NV: out << "subgroup"; break;
        case ::VK_SCOPE_QUEUE_FAMILY_NV: out << "queue_family"; break;
        case ::VK_SCOPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkCoverageReductionModeNV obj)
    {
        using enumIntType = std::underlying_type<::VkCoverageReductionModeNV>::type;
        switch (obj)
        {
        case ::VK_COVERAGE_REDUCTION_MODE_MERGE_NV: out << "merge"; break;
        case ::VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV: out << "truncate"; break;
        case ::VK_COVERAGE_REDUCTION_MODE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkLineRasterizationModeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkLineRasterizationModeEXT>::type;
        switch (obj)
        {
        case ::VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT: out << "default"; break;
        case ::VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT: out << "rectangular"; break;
        case ::VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT: out << "bresenham"; break;
        case ::VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT: out << "rectangular_smooth"; break;
        case ::VK_LINE_RASTERIZATION_MODE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkIndirectCommandsTokenTypeNV obj)
    {
        using enumIntType = std::underlying_type<::VkIndirectCommandsTokenTypeNV>::type;
        switch (obj)
        {
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV: out << "shader_group"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV: out << "state_flags"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV: out << "index_buffer"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV: out << "vertex_buffer"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV: out << "push_constant"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV: out << "draw_indexed"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV: out << "draw"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV: out << "draw_tasks"; break;
        case ::VK_INDIRECT_COMMANDS_TOKEN_TYPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkIndirectStateFlagBitsNV obj)
    {
        using enumIntType = std::underlying_type<::VkIndirectStateFlagBitsNV>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV))
        {
            out << " frontface_bit";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_INDIRECT_STATE_FLAG_BITS_MAX_ENUM_NV))
        {
            out << " bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_STATE_FLAG_BITS_MAX_ENUM_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkIndirectCommandsLayoutUsageFlagBitsNV obj)
    {
        using enumIntType = std::underlying_type<::VkIndirectCommandsLayoutUsageFlagBitsNV>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV))
        {
            out << " explicit_preprocess_bit";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV))
        {
            out << " indexed_sequences_bit";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV))
        {
            out << " unordered_sequences_bit";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_FLAG_BITS_MAX_ENUM_NV))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_INDIRECT_COMMANDS_LAYOUT_USAGE_FLAG_BITS_MAX_ENUM_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDeviceMemoryReportEventTypeEXT obj)
    {
        using enumIntType = std::underlying_type<::VkDeviceMemoryReportEventTypeEXT>::type;
        switch (obj)
        {
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT: out << "allocate"; break;
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT: out << "free"; break;
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT: out << "import"; break;
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT: out << "unimport"; break;
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT: out << "allocation_failed"; break;
        case ::VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_MAX_ENUM_EXT: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkPrivateDataSlotCreateFlagBitsEXT obj)
    {
        using enumIntType = std::underlying_type<::VkPrivateDataSlotCreateFlagBitsEXT>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_PRIVATE_DATA_SLOT_CREATE_FLAG_BITS_MAX_ENUM_EXT))
        {
            out << " vk_private_data_slot_create_flag_bits_max_enum_ext";
            bits &= ~static_cast<enumIntType>(::VK_PRIVATE_DATA_SLOT_CREATE_FLAG_BITS_MAX_ENUM_EXT);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkDeviceDiagnosticsConfigFlagBitsNV obj)
    {
        using enumIntType = std::underlying_type<::VkDeviceDiagnosticsConfigFlagBitsNV>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV))
        {
            out << " enable_shader_debug_info_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV))
        {
            out << " enable_resource_tracking_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV))
        {
            out << " enable_automatic_checkpoints_bit";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_FLAG_BITS_MAX_ENUM_NV))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_DEVICE_DIAGNOSTICS_CONFIG_FLAG_BITS_MAX_ENUM_NV);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateTypeNV obj)
    {
        using enumIntType = std::underlying_type<::VkFragmentShadingRateTypeNV>::type;
        switch (obj)
        {
        case ::VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV: out << "fragment_size"; break;
        case ::VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV: out << "enums"; break;
        case ::VK_FRAGMENT_SHADING_RATE_TYPE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkFragmentShadingRateNV obj)
    {
        using enumIntType = std::underlying_type<::VkFragmentShadingRateNV>::type;
        switch (obj)
        {
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV: out << "1_invocation_per_pixel"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV: out << "1_invocation_per_1x2_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV: out << "1_invocation_per_2x1_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV: out << "1_invocation_per_2x2_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV: out << "1_invocation_per_2x4_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV: out << "1_invocation_per_4x2_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV: out << "1_invocation_per_4x4_pixels"; break;
        case ::VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV: out << "2_invocations_per_pixel"; break;
        case ::VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV: out << "4_invocations_per_pixel"; break;
        case ::VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV: out << "8_invocations_per_pixel"; break;
        case ::VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV: out << "16_invocations_per_pixel"; break;
        case ::VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV: out << "no_invocations"; break;
        case ::VK_FRAGMENT_SHADING_RATE_MAX_ENUM_NV: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkBuildAccelerationStructureModeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkBuildAccelerationStructureModeKHR>::type;
        switch (obj)
        {
        case ::VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR: out << "build"; break;
        case ::VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR: out << "update"; break;
        case ::VK_BUILD_ACCELERATION_STRUCTURE_MODE_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureBuildTypeKHR obj)
    {
        using enumIntType = std::underlying_type<::VkAccelerationStructureBuildTypeKHR>::type;
        switch (obj)
        {
        case ::VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR: out << "host"; break;
        case ::VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR: out << "device"; break;
        case ::VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR: out << "host_or_device"; break;
        case ::VK_ACCELERATION_STRUCTURE_BUILD_TYPE_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureCompatibilityKHR obj)
    {
        using enumIntType = std::underlying_type<::VkAccelerationStructureCompatibilityKHR>::type;
        switch (obj)
        {
        case ::VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR: out << "compatible"; break;
        case ::VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR: out << "incompatible"; break;
        case ::VK_ACCELERATION_STRUCTURE_COMPATIBILITY_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkAccelerationStructureCreateFlagBitsKHR obj)
    {
        using enumIntType = std::underlying_type<::VkAccelerationStructureCreateFlagBitsKHR>::type;
        enumIntType bits = static_cast<enumIntType>(obj);
        out << "[";
        if (bits & static_cast<enumIntType>(::VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR))
        {
            out << " device_address_capture_replay_bit";
            bits &= ~static_cast<enumIntType>(::VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR);
            if (! bits)
                { goto done; }
        }

        if (bits & static_cast<enumIntType>(::VK_ACCELERATION_STRUCTURE_CREATE_FLAG_BITS_MAX_ENUM_KHR))
        {
            out << " flag_bits_max_enum";
            bits &= ~static_cast<enumIntType>(::VK_ACCELERATION_STRUCTURE_CREATE_FLAG_BITS_MAX_ENUM_KHR);
            if (! bits)
                { goto done; }
        }

    done:
        out << " ]";

        return out;
    }


    std::ostream & operator <<(std::ostream & out, ::VkShaderGroupShaderKHR obj)
    {
        using enumIntType = std::underlying_type<::VkShaderGroupShaderKHR>::type;
        switch (obj)
        {
        case ::VK_SHADER_GROUP_SHADER_GENERAL_KHR: out << "general"; break;
        case ::VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR: out << "closest_hit"; break;
        case ::VK_SHADER_GROUP_SHADER_ANY_HIT_KHR: out << "any_hit"; break;
        case ::VK_SHADER_GROUP_SHADER_INTERSECTION_KHR: out << "intersection"; break;
        case ::VK_SHADER_GROUP_SHADER_MAX_ENUM_KHR: out << "max_enum"; break;
        default: out << static_cast<enumIntType>(obj); break;
        }

        return out;
    }
}
