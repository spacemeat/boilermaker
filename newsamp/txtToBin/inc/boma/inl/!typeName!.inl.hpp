


static inline ::VkResult hu::val<::VkResult>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkResult>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "success", 7) == 0) { e |= static_cast<enumIntType>(VK_SUCCESS); }
        else if (std::strncmp(nodeVal, "not_ready", 9) == 0) { e |= static_cast<enumIntType>(VK_NOT_READY); }
        else if (std::strncmp(nodeVal, "timeout", 7) == 0) { e |= static_cast<enumIntType>(VK_TIMEOUT); }
        else if (std::strncmp(nodeVal, "event_set", 9) == 0) { e |= static_cast<enumIntType>(VK_EVENT_SET); }
        else if (std::strncmp(nodeVal, "event_reset", 11) == 0) { e |= static_cast<enumIntType>(VK_EVENT_RESET); }
        else if (std::strncmp(nodeVal, "incomplete", 10) == 0) { e |= static_cast<enumIntType>(VK_INCOMPLETE); }
        else if (std::strncmp(nodeVal, "error_out_of_host_memory", 24) == 0) { e |= static_cast<enumIntType>(VK_ERROR_OUT_OF_HOST_MEMORY); }
        else if (std::strncmp(nodeVal, "error_out_of_device_memory", 26) == 0) { e |= static_cast<enumIntType>(VK_ERROR_OUT_OF_DEVICE_MEMORY); }
        else if (std::strncmp(nodeVal, "error_initialization_failed", 27) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INITIALIZATION_FAILED); }
        else if (std::strncmp(nodeVal, "error_device_lost", 17) == 0) { e |= static_cast<enumIntType>(VK_ERROR_DEVICE_LOST); }
        else if (std::strncmp(nodeVal, "error_memory_map_failed", 23) == 0) { e |= static_cast<enumIntType>(VK_ERROR_MEMORY_MAP_FAILED); }
        else if (std::strncmp(nodeVal, "error_layer_not_present", 23) == 0) { e |= static_cast<enumIntType>(VK_ERROR_LAYER_NOT_PRESENT); }
        else if (std::strncmp(nodeVal, "error_extension_not_present", 27) == 0) { e |= static_cast<enumIntType>(VK_ERROR_EXTENSION_NOT_PRESENT); }
        else if (std::strncmp(nodeVal, "error_feature_not_present", 25) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FEATURE_NOT_PRESENT); }
        else if (std::strncmp(nodeVal, "error_incompatible_driver", 25) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INCOMPATIBLE_DRIVER); }
        else if (std::strncmp(nodeVal, "error_too_many_objects", 22) == 0) { e |= static_cast<enumIntType>(VK_ERROR_TOO_MANY_OBJECTS); }
        else if (std::strncmp(nodeVal, "error_format_not_supported", 26) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FORMAT_NOT_SUPPORTED); }
        else if (std::strncmp(nodeVal, "error_fragmented_pool", 21) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FRAGMENTED_POOL); }
        else if (std::strncmp(nodeVal, "error_unknown", 13) == 0) { e |= static_cast<enumIntType>(VK_ERROR_UNKNOWN); }
        else if (std::strncmp(nodeVal, "error_out_of_pool_memory", 24) == 0) { e |= static_cast<enumIntType>(VK_ERROR_OUT_OF_POOL_MEMORY); }
        else if (std::strncmp(nodeVal, "error_invalid_external_handle", 29) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_EXTERNAL_HANDLE); }
        else if (std::strncmp(nodeVal, "error_fragmentation", 19) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FRAGMENTATION); }
        else if (std::strncmp(nodeVal, "error_invalid_opaque_capture_address", 36) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS); }
        else if (std::strncmp(nodeVal, "error_surface_lost_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_ERROR_SURFACE_LOST_KHR); }
        else if (std::strncmp(nodeVal, "error_native_window_in_use_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_ERROR_NATIVE_WINDOW_IN_USE_KHR); }
        else if (std::strncmp(nodeVal, "suboptimal_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_SUBOPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "error_out_of_date_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_ERROR_OUT_OF_DATE_KHR); }
        else if (std::strncmp(nodeVal, "error_incompatible_display_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INCOMPATIBLE_DISPLAY_KHR); }
        else if (std::strncmp(nodeVal, "error_validation_failed_ext", 27) == 0) { e |= static_cast<enumIntType>(VK_ERROR_VALIDATION_FAILED_EXT); }
        else if (std::strncmp(nodeVal, "error_invalid_shader_nv", 23) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_SHADER_NV); }
        else if (std::strncmp(nodeVal, "error_invalid_drm_format_modifier_plane_layout_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_DRM_FORMAT_MODIFIER_PLANE_LAYOUT_EXT); }
        else if (std::strncmp(nodeVal, "error_not_permitted_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_ERROR_NOT_PERMITTED_EXT); }
        else if (std::strncmp(nodeVal, "error_full_screen_exclusive_mode_lost_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FULL_SCREEN_EXCLUSIVE_MODE_LOST_EXT); }
        else if (std::strncmp(nodeVal, "thread_idle_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_THREAD_IDLE_KHR); }
        else if (std::strncmp(nodeVal, "thread_done_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_THREAD_DONE_KHR); }
        else if (std::strncmp(nodeVal, "operation_deferred_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_OPERATION_DEFERRED_KHR); }
        else if (std::strncmp(nodeVal, "operation_not_deferred_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_OPERATION_NOT_DEFERRED_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_compile_required_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_COMPILE_REQUIRED_EXT); }
        else if (std::strncmp(nodeVal, "error_out_of_pool_memory_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_ERROR_OUT_OF_POOL_MEMORY_KHR); }
        else if (std::strncmp(nodeVal, "error_invalid_external_handle_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_EXTERNAL_HANDLE_KHR); }
        else if (std::strncmp(nodeVal, "error_fragmentation_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_ERROR_FRAGMENTATION_EXT); }
        else if (std::strncmp(nodeVal, "error_invalid_device_address_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_DEVICE_ADDRESS_EXT); }
        else if (std::strncmp(nodeVal, "error_invalid_opaque_capture_address_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_ERROR_INVALID_OPAQUE_CAPTURE_ADDRESS_KHR); }
        else if (std::strncmp(nodeVal, "error_pipeline_compile_required_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_ERROR_PIPELINE_COMPILE_REQUIRED_EXT); }
        else if (std::strncmp(nodeVal, "result_max_enum", 15) == 0) { e |= static_cast<enumIntType>(VK_RESULT_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkResult>(e);
}


static inline ::VkStructureType hu::val<::VkStructureType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkStructureType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "application_info", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_APPLICATION_INFO); }
        else if (std::strncmp(nodeVal, "instance_create_info", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "device_queue_create_info", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "device_create_info", 18) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "submit_info", 11) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBMIT_INFO); }
        else if (std::strncmp(nodeVal, "memory_allocate_info", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "mapped_memory_range", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MAPPED_MEMORY_RANGE); }
        else if (std::strncmp(nodeVal, "bind_sparse_info", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_SPARSE_INFO); }
        else if (std::strncmp(nodeVal, "fence_create_info", 17) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FENCE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "semaphore_create_info", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "event_create_info", 17) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EVENT_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "query_pool_create_info", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "buffer_create_info", 18) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "buffer_view_create_info", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_VIEW_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "image_create_info", 17) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "image_view_create_info", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "shader_module_create_info", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SHADER_MODULE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_cache_create_info", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_shader_stage_create_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_vertex_input_state_create_info", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_input_assembly_state_create_info", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_tessellation_state_create_info", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_state_create_info", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_state_create_info", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_multisample_state_create_info", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_depth_stencil_state_create_info", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_color_blend_state_create_info", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_dynamic_state_create_info", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "graphics_pipeline_create_info", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "compute_pipeline_create_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMPUTE_PIPELINE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_layout_create_info", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "sampler_create_info", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout_create_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "descriptor_pool_create_info", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "descriptor_set_allocate_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "write_descriptor_set", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET); }
        else if (std::strncmp(nodeVal, "copy_descriptor_set", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_DESCRIPTOR_SET); }
        else if (std::strncmp(nodeVal, "framebuffer_create_info", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "render_pass_create_info", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "command_pool_create_info", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "command_buffer_allocate_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "command_buffer_inheritance_info", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_INFO); }
        else if (std::strncmp(nodeVal, "command_buffer_begin_info", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "render_pass_begin_info", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "buffer_memory_barrier", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_MEMORY_BARRIER); }
        else if (std::strncmp(nodeVal, "image_memory_barrier", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER); }
        else if (std::strncmp(nodeVal, "memory_barrier", 14) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_BARRIER); }
        else if (std::strncmp(nodeVal, "loader_instance_create_info", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "loader_device_create_info", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_subgroup_properties", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES); }
        else if (std::strncmp(nodeVal, "bind_buffer_memory_info", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO); }
        else if (std::strncmp(nodeVal, "bind_image_memory_info", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_16bit_storage_features", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES); }
        else if (std::strncmp(nodeVal, "memory_dedicated_requirements", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS); }
        else if (std::strncmp(nodeVal, "memory_dedicated_allocate_info", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "memory_allocate_flags_info", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO); }
        else if (std::strncmp(nodeVal, "device_group_render_pass_begin_info", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "device_group_command_buffer_begin_info", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "device_group_submit_info", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO); }
        else if (std::strncmp(nodeVal, "device_group_bind_sparse_info", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO); }
        else if (std::strncmp(nodeVal, "bind_buffer_memory_device_group_info", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO); }
        else if (std::strncmp(nodeVal, "bind_image_memory_device_group_info", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_group_properties", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES); }
        else if (std::strncmp(nodeVal, "device_group_device_create_info", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "buffer_memory_requirements_info_2", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2); }
        else if (std::strncmp(nodeVal, "image_memory_requirements_info_2", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2); }
        else if (std::strncmp(nodeVal, "image_sparse_memory_requirements_info_2", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2); }
        else if (std::strncmp(nodeVal, "memory_requirements_2", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2); }
        else if (std::strncmp(nodeVal, "sparse_image_memory_requirements_2", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2); }
        else if (std::strncmp(nodeVal, "physical_device_features_2", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2); }
        else if (std::strncmp(nodeVal, "physical_device_properties_2", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "format_properties_2", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "image_format_properties_2", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "physical_device_image_format_info_2", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2); }
        else if (std::strncmp(nodeVal, "queue_family_properties_2", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "physical_device_memory_properties_2", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "sparse_image_format_properties_2", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2); }
        else if (std::strncmp(nodeVal, "physical_device_sparse_image_format_info_2", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2); }
        else if (std::strncmp(nodeVal, "physical_device_point_clipping_properties", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES); }
        else if (std::strncmp(nodeVal, "render_pass_input_attachment_aspect_create_info", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "image_view_usage_create_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "pipeline_tessellation_domain_origin_state_create_info", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "render_pass_multiview_create_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_multiview_features", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_multiview_properties", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_variable_pointers_features", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES); }
        else if (std::strncmp(nodeVal, "protected_submit_info", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_protected_memory_features", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_protected_memory_properties", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES); }
        else if (std::strncmp(nodeVal, "device_queue_info_2", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_QUEUE_INFO_2); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_create_info", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_info", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO); }
        else if (std::strncmp(nodeVal, "bind_image_plane_memory_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO); }
        else if (std::strncmp(nodeVal, "image_plane_memory_requirements_info", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_sampler_ycbcr_conversion_features", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_image_format_properties", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES); }
        else if (std::strncmp(nodeVal, "descriptor_update_template_create_info", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_external_image_format_info", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO); }
        else if (std::strncmp(nodeVal, "external_image_format_properties", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_external_buffer_info", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO); }
        else if (std::strncmp(nodeVal, "external_buffer_properties", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_id_properties", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES); }
        else if (std::strncmp(nodeVal, "external_memory_buffer_create_info", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "external_memory_image_create_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "export_memory_allocate_info", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_external_fence_info", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO); }
        else if (std::strncmp(nodeVal, "external_fence_properties", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES); }
        else if (std::strncmp(nodeVal, "export_fence_create_info", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "export_semaphore_create_info", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_external_semaphore_info", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO); }
        else if (std::strncmp(nodeVal, "external_semaphore_properties", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_maintenance_3_properties", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout_support", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT); }
        else if (std::strncmp(nodeVal, "physical_device_shader_draw_parameters_features", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_1_1_features", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_1_1_properties", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_1_2_features", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_1_2_properties", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES); }
        else if (std::strncmp(nodeVal, "image_format_list_create_info", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "attachment_description_2", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2); }
        else if (std::strncmp(nodeVal, "attachment_reference_2", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2); }
        else if (std::strncmp(nodeVal, "subpass_description_2", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2); }
        else if (std::strncmp(nodeVal, "subpass_dependency_2", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2); }
        else if (std::strncmp(nodeVal, "render_pass_create_info_2", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2); }
        else if (std::strncmp(nodeVal, "subpass_begin_info", 18) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "subpass_end_info", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_END_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_8bit_storage_features", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_driver_properties", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES); }
        else if (std::strncmp(nodeVal, "physical_device_shader_atomic_int64_features", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_shader_float16_int8_features", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_float_controls_properties", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout_binding_flags_create_info", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_descriptor_indexing_features", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_descriptor_indexing_properties", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES); }
        else if (std::strncmp(nodeVal, "descriptor_set_variable_descriptor_count_allocate_info", 54) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "descriptor_set_variable_descriptor_count_layout_support", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT); }
        else if (std::strncmp(nodeVal, "physical_device_depth_stencil_resolve_properties", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES); }
        else if (std::strncmp(nodeVal, "subpass_description_depth_stencil_resolve", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE); }
        else if (std::strncmp(nodeVal, "physical_device_scalar_block_layout_features", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES); }
        else if (std::strncmp(nodeVal, "image_stencil_usage_create_info", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_sampler_filter_minmax_properties", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES); }
        else if (std::strncmp(nodeVal, "sampler_reduction_mode_create_info", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_memory_model_features", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_imageless_framebuffer_features", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES); }
        else if (std::strncmp(nodeVal, "framebuffer_attachments_create_info", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "framebuffer_attachment_image_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO); }
        else if (std::strncmp(nodeVal, "render_pass_attachment_begin_info", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_uniform_buffer_standard_layout_features", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_shader_subgroup_extended_types_features", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_separate_depth_stencil_layouts_features", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES); }
        else if (std::strncmp(nodeVal, "attachment_reference_stencil_layout", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT); }
        else if (std::strncmp(nodeVal, "attachment_description_stencil_layout", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT); }
        else if (std::strncmp(nodeVal, "physical_device_host_query_reset_features", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_timeline_semaphore_features", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_timeline_semaphore_properties", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES); }
        else if (std::strncmp(nodeVal, "semaphore_type_create_info", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "timeline_semaphore_submit_info", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO); }
        else if (std::strncmp(nodeVal, "semaphore_wait_info", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO); }
        else if (std::strncmp(nodeVal, "semaphore_signal_info", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO); }
        else if (std::strncmp(nodeVal, "physical_device_buffer_device_address_features", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES); }
        else if (std::strncmp(nodeVal, "buffer_device_address_info", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO); }
        else if (std::strncmp(nodeVal, "buffer_opaque_capture_address_create_info", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO); }
        else if (std::strncmp(nodeVal, "memory_opaque_capture_address_allocate_info", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO); }
        else if (std::strncmp(nodeVal, "device_memory_opaque_capture_address_info", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO); }
        else if (std::strncmp(nodeVal, "swapchain_create_info_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "present_info_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PRESENT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_present_capabilities_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_CAPABILITIES_KHR); }
        else if (std::strncmp(nodeVal, "image_swapchain_create_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "bind_image_memory_swapchain_info_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR); }
        else if (std::strncmp(nodeVal, "acquire_next_image_info_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACQUIRE_NEXT_IMAGE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_present_info_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_swapchain_create_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "display_mode_create_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_MODE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "display_surface_create_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "display_present_info_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "xlib_surface_create_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "xcb_surface_create_info_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_XCB_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "wayland_surface_create_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "android_surface_create_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "win32_surface_create_info_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "debug_report_callback_create_info_ext", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_state_rasterization_order_amd", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD); }
        else if (std::strncmp(nodeVal, "debug_marker_object_name_info_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_NAME_INFO_EXT); }
        else if (std::strncmp(nodeVal, "debug_marker_object_tag_info_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_MARKER_OBJECT_TAG_INFO_EXT); }
        else if (std::strncmp(nodeVal, "debug_marker_marker_info_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_MARKER_MARKER_INFO_EXT); }
        else if (std::strncmp(nodeVal, "dedicated_allocation_image_create_info_nv", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "dedicated_allocation_buffer_create_info_nv", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "dedicated_allocation_memory_allocate_info_nv", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_transform_feedback_features_ext", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_transform_feedback_properties_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_state_stream_create_info_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "image_view_handle_info_nvx", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_HANDLE_INFO_NVX); }
        else if (std::strncmp(nodeVal, "image_view_address_properties_nvx", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_ADDRESS_PROPERTIES_NVX); }
        else if (std::strncmp(nodeVal, "texture_lod_gather_format_properties_amd", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD); }
        else if (std::strncmp(nodeVal, "stream_descriptor_surface_create_info_ggp", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_STREAM_DESCRIPTOR_SURFACE_CREATE_INFO_GGP); }
        else if (std::strncmp(nodeVal, "physical_device_corner_sampled_image_features_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "external_memory_image_create_info_nv", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "export_memory_allocate_info_nv", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "import_memory_win32_handle_info_nv", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV); }
        else if (std::strncmp(nodeVal, "export_memory_win32_handle_info_nv", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV); }
        else if (std::strncmp(nodeVal, "win32_keyed_mutex_acquire_release_info_nv", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV); }
        else if (std::strncmp(nodeVal, "validation_flags_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT); }
        else if (std::strncmp(nodeVal, "vi_surface_create_info_nn", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_VI_SURFACE_CREATE_INFO_NN); }
        else if (std::strncmp(nodeVal, "physical_device_texture_compression_astc_hdr_features_ext", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "image_view_astc_decode_mode_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_astc_decode_features_ext", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "import_memory_win32_handle_info_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "export_memory_win32_handle_info_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "memory_win32_handle_properties_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_WIN32_HANDLE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "memory_get_win32_handle_info_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_GET_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "import_memory_fd_info_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "memory_fd_properties_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_FD_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "memory_get_fd_info_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_GET_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "win32_keyed_mutex_acquire_release_info_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "import_semaphore_win32_handle_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "export_semaphore_win32_handle_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "d3d12_fence_submit_info_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "semaphore_get_win32_handle_info_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_GET_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "import_semaphore_fd_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_SEMAPHORE_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "semaphore_get_fd_info_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_GET_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_push_descriptor_properties_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "command_buffer_inheritance_conditional_rendering_info_ext", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_conditional_rendering_features_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "conditional_rendering_begin_info_ext", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_CONDITIONAL_RENDERING_BEGIN_INFO_EXT); }
        else if (std::strncmp(nodeVal, "present_regions_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_w_scaling_state_create_info_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "surface_capabilities_2_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_EXT); }
        else if (std::strncmp(nodeVal, "display_power_info_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_POWER_INFO_EXT); }
        else if (std::strncmp(nodeVal, "device_event_info_ext", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_EVENT_INFO_EXT); }
        else if (std::strncmp(nodeVal, "display_event_info_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_EVENT_INFO_EXT); }
        else if (std::strncmp(nodeVal, "swapchain_counter_create_info_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "present_times_info_google", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE); }
        else if (std::strncmp(nodeVal, "physical_device_multiview_per_view_attributes_properties_nvx", 60) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_swizzle_state_create_info_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_discard_rectangle_properties_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_discard_rectangle_state_create_info_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_conservative_rasterization_properties_ext", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_conservative_state_create_info_ext", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_depth_clip_enable_features_ext", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_depth_clip_state_create_info_ext", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "hdr_metadata_ext", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_HDR_METADATA_EXT); }
        else if (std::strncmp(nodeVal, "shared_present_surface_capabilities_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR); }
        else if (std::strncmp(nodeVal, "import_fence_win32_handle_info_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_FENCE_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "export_fence_win32_handle_info_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "fence_get_win32_handle_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FENCE_GET_WIN32_HANDLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "import_fence_fd_info_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_FENCE_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "fence_get_fd_info_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FENCE_GET_FD_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_performance_query_features_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_performance_query_properties_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "query_pool_performance_create_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "performance_query_submit_info_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "acquire_profiling_lock_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACQUIRE_PROFILING_LOCK_INFO_KHR); }
        else if (std::strncmp(nodeVal, "performance_counter_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_KHR); }
        else if (std::strncmp(nodeVal, "performance_counter_description_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_COUNTER_DESCRIPTION_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_surface_info_2_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SURFACE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "surface_capabilities_2_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_2_KHR); }
        else if (std::strncmp(nodeVal, "surface_format_2_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_FORMAT_2_KHR); }
        else if (std::strncmp(nodeVal, "display_properties_2_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "display_plane_properties_2_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_PLANE_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "display_mode_properties_2_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_MODE_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "display_plane_info_2_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_PLANE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "display_plane_capabilities_2_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_PLANE_CAPABILITIES_2_KHR); }
        else if (std::strncmp(nodeVal, "ios_surface_create_info_mvk", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IOS_SURFACE_CREATE_INFO_MVK); }
        else if (std::strncmp(nodeVal, "macos_surface_create_info_mvk", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK); }
        else if (std::strncmp(nodeVal, "debug_utils_object_name_info_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_NAME_INFO_EXT); }
        else if (std::strncmp(nodeVal, "debug_utils_object_tag_info_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_UTILS_OBJECT_TAG_INFO_EXT); }
        else if (std::strncmp(nodeVal, "debug_utils_label_ext", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_UTILS_LABEL_EXT); }
        else if (std::strncmp(nodeVal, "debug_utils_messenger_callback_data_ext", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CALLBACK_DATA_EXT); }
        else if (std::strncmp(nodeVal, "debug_utils_messenger_create_info_ext", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "android_hardware_buffer_usage_android", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID); }
        else if (std::strncmp(nodeVal, "android_hardware_buffer_properties_android", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_PROPERTIES_ANDROID); }
        else if (std::strncmp(nodeVal, "android_hardware_buffer_format_properties_android", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID); }
        else if (std::strncmp(nodeVal, "import_android_hardware_buffer_info_android", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID); }
        else if (std::strncmp(nodeVal, "memory_get_android_hardware_buffer_info_android", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_GET_ANDROID_HARDWARE_BUFFER_INFO_ANDROID); }
        else if (std::strncmp(nodeVal, "external_format_android", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID); }
        else if (std::strncmp(nodeVal, "physical_device_inline_uniform_block_features_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_inline_uniform_block_properties_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "write_descriptor_set_inline_uniform_block_ext", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_pool_inline_uniform_block_create_info_ext", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "sample_locations_info_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT); }
        else if (std::strncmp(nodeVal, "render_pass_sample_locations_begin_info_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_sample_locations_state_create_info_ext", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_sample_locations_properties_ext", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "multisample_properties_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MULTISAMPLE_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_blend_operation_advanced_features_ext", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_blend_operation_advanced_properties_ext", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_color_blend_advanced_state_create_info_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_coverage_to_color_state_create_info_nv", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "write_descriptor_set_acceleration_structure_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_build_geometry_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_GEOMETRY_INFO_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_device_address_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_DEVICE_ADDRESS_INFO_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_geometry_aabbs_data_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_AABBS_DATA_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_geometry_instances_data_khr", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_INSTANCES_DATA_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_geometry_triangles_data_khr", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_TRIANGLES_DATA_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_geometry_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_version_info_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_VERSION_INFO_KHR); }
        else if (std::strncmp(nodeVal, "copy_acceleration_structure_info_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "copy_acceleration_structure_to_memory_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_ACCELERATION_STRUCTURE_TO_MEMORY_INFO_KHR); }
        else if (std::strncmp(nodeVal, "copy_memory_to_acceleration_structure_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_MEMORY_TO_ACCELERATION_STRUCTURE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_acceleration_structure_features_khr", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_acceleration_structure_properties_khr", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_create_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_build_sizes_info_khr", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_BUILD_SIZES_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_ray_tracing_pipeline_features_khr", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_ray_tracing_pipeline_properties_khr", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_pipeline_create_info_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_shader_group_create_info_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_pipeline_interface_create_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_INTERFACE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_ray_query_features_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_coverage_modulation_state_create_info_nv", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shader_sm_builtins_features_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shader_sm_builtins_properties_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "drm_format_modifier_properties_list_ext", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_image_drm_format_modifier_info_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT); }
        else if (std::strncmp(nodeVal, "image_drm_format_modifier_list_create_info_ext", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "image_drm_format_modifier_explicit_create_info_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "image_drm_format_modifier_properties_ext", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "validation_cache_create_info_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_VALIDATION_CACHE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "shader_module_validation_cache_create_info_ext", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_portability_subset_features_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_portability_subset_properties_khr", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_shading_rate_image_state_create_info_nv", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shading_rate_image_features_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shading_rate_image_properties_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_coarse_sample_order_state_create_info_nv", 58) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "ray_tracing_pipeline_create_info_nv", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RAY_TRACING_PIPELINE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_create_info_nv", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "geometry_nv", 11) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GEOMETRY_NV); }
        else if (std::strncmp(nodeVal, "geometry_triangles_nv", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GEOMETRY_TRIANGLES_NV); }
        else if (std::strncmp(nodeVal, "geometry_aabb_nv", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GEOMETRY_AABB_NV); }
        else if (std::strncmp(nodeVal, "bind_acceleration_structure_memory_info_nv", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_ACCELERATION_STRUCTURE_MEMORY_INFO_NV); }
        else if (std::strncmp(nodeVal, "write_descriptor_set_acceleration_structure_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_memory_requirements_info_nv", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_ray_tracing_properties_nv", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "ray_tracing_shader_group_create_info_nv", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RAY_TRACING_SHADER_GROUP_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_info_nv", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_representative_fragment_test_features_nv", 56) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "pipeline_representative_fragment_test_state_create_info_nv", 58) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_image_view_image_format_info_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT); }
        else if (std::strncmp(nodeVal, "filter_cubic_image_view_image_format_properties_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "device_queue_global_priority_create_info_ext", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "import_memory_host_pointer_info_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT); }
        else if (std::strncmp(nodeVal, "memory_host_pointer_properties_ext", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_HOST_POINTER_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_external_memory_host_properties_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_shader_clock_features_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_compiler_control_create_info_amd", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD); }
        else if (std::strncmp(nodeVal, "calibrated_timestamp_info_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_CALIBRATED_TIMESTAMP_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_shader_core_properties_amd", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD); }
        else if (std::strncmp(nodeVal, "device_memory_overallocation_create_info_amd", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD); }
        else if (std::strncmp(nodeVal, "physical_device_vertex_attribute_divisor_properties_ext", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_vertex_input_divisor_state_create_info_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_vertex_attribute_divisor_features_ext", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "present_frame_token_ggp", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP); }
        else if (std::strncmp(nodeVal, "pipeline_creation_feedback_create_info_ext", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_compute_shader_derivatives_features_nv", 54) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_mesh_shader_features_nv", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_mesh_shader_properties_nv", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shader_barycentric_features_nv", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shader_image_footprint_features_nv", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "pipeline_viewport_exclusive_scissor_state_create_info_nv", 56) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_exclusive_scissor_features_nv", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "checkpoint_data_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_CHECKPOINT_DATA_NV); }
        else if (std::strncmp(nodeVal, "queue_family_checkpoint_properties_nv", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_shader_integer_functions_2_features_intel", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL); }
        else if (std::strncmp(nodeVal, "query_pool_performance_query_create_info_intel", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "initialize_performance_api_info_intel", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_INITIALIZE_PERFORMANCE_API_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "performance_marker_info_intel", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_MARKER_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "performance_stream_marker_info_intel", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_STREAM_MARKER_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "performance_override_info_intel", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_OVERRIDE_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "performance_configuration_acquire_info_intel", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PERFORMANCE_CONFIGURATION_ACQUIRE_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "physical_device_pci_bus_info_properties_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "display_native_hdr_surface_capabilities_amd", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD); }
        else if (std::strncmp(nodeVal, "swapchain_display_native_hdr_create_info_amd", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD); }
        else if (std::strncmp(nodeVal, "imagepipe_surface_create_info_fuchsia", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGEPIPE_SURFACE_CREATE_INFO_FUCHSIA); }
        else if (std::strncmp(nodeVal, "physical_device_shader_terminate_invocation_features_khr", 56) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "metal_surface_create_info_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_METAL_SURFACE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_density_map_features_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_density_map_properties_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "render_pass_fragment_density_map_create_info_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_subgroup_size_control_properties_ext", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_shader_stage_required_subgroup_size_create_info_ext", 60) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_subgroup_size_control_features_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_info_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_fragment_shading_rate_state_create_info_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shading_rate_properties_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shading_rate_features_khr", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shading_rate_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_shader_core_properties_2_amd", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD); }
        else if (std::strncmp(nodeVal, "physical_device_coherent_memory_features_amd", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD); }
        else if (std::strncmp(nodeVal, "physical_device_shader_image_atomic_int64_features_ext", 54) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_memory_budget_properties_ext", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_memory_priority_features_ext", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "memory_priority_allocate_info_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "surface_protected_capabilities_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_dedicated_allocation_image_aliasing_features_nv", 63) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_buffer_device_address_features_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "buffer_device_address_create_info_ext", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_tool_properties_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TOOL_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "validation_features_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_cooperative_matrix_features_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "cooperative_matrix_properties_nv", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COOPERATIVE_MATRIX_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_cooperative_matrix_properties_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_coverage_reduction_mode_features_nv", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "pipeline_coverage_reduction_state_create_info_nv", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "framebuffer_mixed_samples_combination_nv", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_MIXED_SAMPLES_COMBINATION_NV); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shader_interlock_features_ext", 54) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_ycbcr_image_arrays_features_ext", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "surface_full_screen_exclusive_info_ext", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "surface_capabilities_full_screen_exclusive_ext", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT); }
        else if (std::strncmp(nodeVal, "surface_full_screen_exclusive_win32_info_ext", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT); }
        else if (std::strncmp(nodeVal, "headless_surface_create_info_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_HEADLESS_SURFACE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_line_rasterization_features_ext", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_rasterization_line_state_create_info_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_line_rasterization_properties_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_shader_atomic_float_features_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_index_type_uint8_features_ext", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_extended_dynamic_state_features_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_pipeline_executable_properties_features_khr", 59) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_info_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_executable_properties_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_executable_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_executable_statistic_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_STATISTIC_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_executable_internal_representation_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_EXECUTABLE_INTERNAL_REPRESENTATION_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_shader_demote_to_helper_invocation_features_ext", 63) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_device_generated_commands_properties_nv", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "graphics_shader_group_create_info_nv", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GRAPHICS_SHADER_GROUP_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "graphics_pipeline_shader_groups_create_info_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "indirect_commands_layout_token_nv", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_TOKEN_NV); }
        else if (std::strncmp(nodeVal, "indirect_commands_layout_create_info_nv", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_INDIRECT_COMMANDS_LAYOUT_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "generated_commands_info_nv", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GENERATED_COMMANDS_INFO_NV); }
        else if (std::strncmp(nodeVal, "generated_commands_memory_requirements_info_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_GENERATED_COMMANDS_MEMORY_REQUIREMENTS_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_device_generated_commands_features_nv", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_texel_buffer_alignment_features_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_texel_buffer_alignment_properties_ext", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "command_buffer_inheritance_render_pass_transform_info_qcom", 58) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM); }
        else if (std::strncmp(nodeVal, "render_pass_transform_begin_info_qcom", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM); }
        else if (std::strncmp(nodeVal, "physical_device_device_memory_report_features_ext", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "device_device_memory_report_create_info_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "device_memory_report_callback_data_ext", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_MEMORY_REPORT_CALLBACK_DATA_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_robustness_2_features_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_robustness_2_properties_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "sampler_custom_border_color_create_info_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_custom_border_color_properties_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_custom_border_color_features_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_library_create_info_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_LIBRARY_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_private_data_features_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "device_private_data_create_info_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "private_data_slot_create_info_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PRIVATE_DATA_SLOT_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_pipeline_creation_cache_control_features_ext", 60) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_diagnostics_config_features_nv", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "device_diagnostics_config_create_info_nv", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shading_rate_enums_properties_nv", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_shading_rate_enums_features_nv", 55) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV); }
        else if (std::strncmp(nodeVal, "pipeline_fragment_shading_rate_enum_state_create_info_nv", 56) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_density_map_2_features_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_fragment_density_map_2_properties_ext", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "copy_command_transform_info_qcom", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM); }
        else if (std::strncmp(nodeVal, "physical_device_image_robustness_features_ext", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "copy_buffer_info_2_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_BUFFER_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "copy_image_info_2_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_IMAGE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "copy_buffer_to_image_info_2_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_BUFFER_TO_IMAGE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "copy_image_to_buffer_info_2_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_COPY_IMAGE_TO_BUFFER_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "blit_image_info_2_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BLIT_IMAGE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "resolve_image_info_2_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RESOLVE_IMAGE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "buffer_copy_2_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_COPY_2_KHR); }
        else if (std::strncmp(nodeVal, "image_copy_2_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_COPY_2_KHR); }
        else if (std::strncmp(nodeVal, "image_blit_2_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_BLIT_2_KHR); }
        else if (std::strncmp(nodeVal, "buffer_image_copy_2_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_IMAGE_COPY_2_KHR); }
        else if (std::strncmp(nodeVal, "image_resolve_2_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_RESOLVE_2_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_4444_formats_features_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "directfb_surface_create_info_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DIRECTFB_SURFACE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_variable_pointer_features", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES); }
        else if (std::strncmp(nodeVal, "physical_device_shader_draw_parameter_features", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETER_FEATURES); }
        else if (std::strncmp(nodeVal, "debug_report_create_info_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "render_pass_multiview_create_info_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_multiview_features_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_multiview_properties_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_features_2_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_properties_2_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "format_properties_2_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "image_format_properties_2_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_FORMAT_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_image_format_info_2_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_FORMAT_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "queue_family_properties_2_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUEUE_FAMILY_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_memory_properties_2_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "sparse_image_format_properties_2_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SPARSE_IMAGE_FORMAT_PROPERTIES_2_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_sparse_image_format_info_2_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SPARSE_IMAGE_FORMAT_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "memory_allocate_flags_info_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_render_pass_begin_info_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_command_buffer_begin_info_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_submit_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_group_bind_sparse_info_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "bind_buffer_memory_device_group_info_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO_KHR); }
        else if (std::strncmp(nodeVal, "bind_image_memory_device_group_info_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_group_properties_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GROUP_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "device_group_device_create_info_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_external_image_format_info_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "external_image_format_properties_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_external_buffer_info_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_BUFFER_INFO_KHR); }
        else if (std::strncmp(nodeVal, "external_buffer_properties_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_BUFFER_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_id_properties_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "external_memory_buffer_create_info_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "external_memory_image_create_info_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "export_memory_allocate_info_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_external_semaphore_info_khr", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_SEMAPHORE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "external_semaphore_properties_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_SEMAPHORE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "export_semaphore_create_info_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_shader_float16_int8_features_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_float16_int8_features_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT16_INT8_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_16bit_storage_features_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "descriptor_update_template_create_info_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "surface_capabilities2_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES2_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_imageless_framebuffer_features_khr", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "framebuffer_attachments_create_info_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "framebuffer_attachment_image_info_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENT_IMAGE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "render_pass_attachment_begin_info_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO_KHR); }
        else if (std::strncmp(nodeVal, "attachment_description_2_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_2_KHR); }
        else if (std::strncmp(nodeVal, "attachment_reference_2_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_2_KHR); }
        else if (std::strncmp(nodeVal, "subpass_description_2_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_2_KHR); }
        else if (std::strncmp(nodeVal, "subpass_dependency_2_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DEPENDENCY_2_KHR); }
        else if (std::strncmp(nodeVal, "render_pass_create_info_2_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "subpass_begin_info_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_BEGIN_INFO_KHR); }
        else if (std::strncmp(nodeVal, "subpass_end_info_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_END_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_external_fence_info_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_FENCE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "external_fence_properties_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXTERNAL_FENCE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "export_fence_create_info_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_point_clipping_properties_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "render_pass_input_attachment_aspect_create_info_khr", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "image_view_usage_create_info_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "pipeline_tessellation_domain_origin_state_create_info_khr", 57) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_variable_pointers_features_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_variable_pointer_features_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTER_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "memory_dedicated_requirements_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS_KHR); }
        else if (std::strncmp(nodeVal, "memory_dedicated_allocate_info_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_sampler_filter_minmax_properties_ext", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "sampler_reduction_mode_create_info_ext", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "buffer_memory_requirements_info_2_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_MEMORY_REQUIREMENTS_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "image_memory_requirements_info_2_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_MEMORY_REQUIREMENTS_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "image_sparse_memory_requirements_info_2_khr", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_SPARSE_MEMORY_REQUIREMENTS_INFO_2_KHR); }
        else if (std::strncmp(nodeVal, "memory_requirements_2_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_REQUIREMENTS_2_KHR); }
        else if (std::strncmp(nodeVal, "sparse_image_memory_requirements_2_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SPARSE_IMAGE_MEMORY_REQUIREMENTS_2_KHR); }
        else if (std::strncmp(nodeVal, "image_format_list_create_info_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_create_info_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_info_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO_KHR); }
        else if (std::strncmp(nodeVal, "bind_image_plane_memory_info_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO_KHR); }
        else if (std::strncmp(nodeVal, "image_plane_memory_requirements_info_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_sampler_ycbcr_conversion_features_khr", 53) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_image_format_properties_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "bind_buffer_memory_info_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_INFO_KHR); }
        else if (std::strncmp(nodeVal, "bind_image_memory_info_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_INFO_KHR); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout_binding_flags_create_info_ext", 51) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_descriptor_indexing_features_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_descriptor_indexing_properties_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_set_variable_descriptor_count_allocate_info_ext", 58) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_set_variable_descriptor_count_layout_support_ext", 59) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_maintenance_3_properties_khr", 44) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout_support_khr", 33) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_SUPPORT_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_shader_subgroup_extended_types_features_khr", 59) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_8bit_storage_features_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_shader_atomic_int64_features_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_driver_properties_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_float_controls_properties_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_depth_stencil_resolve_properties_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "subpass_description_depth_stencil_resolve_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_timeline_semaphore_features_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_timeline_semaphore_properties_khr", 49) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES_KHR); }
        else if (std::strncmp(nodeVal, "semaphore_type_create_info_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "timeline_semaphore_submit_info_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "semaphore_wait_info_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_WAIT_INFO_KHR); }
        else if (std::strncmp(nodeVal, "semaphore_signal_info_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_SEMAPHORE_SIGNAL_INFO_KHR); }
        else if (std::strncmp(nodeVal, "query_pool_create_info_intel", 28) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_QUERY_POOL_CREATE_INFO_INTEL); }
        else if (std::strncmp(nodeVal, "physical_device_vulkan_memory_model_features_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_scalar_block_layout_features_ext", 48) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_separate_depth_stencil_layouts_features_khr", 59) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "attachment_reference_stencil_layout_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT_KHR); }
        else if (std::strncmp(nodeVal, "attachment_description_stencil_layout_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_buffer_address_features_ext", 43) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_ADDRESS_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "buffer_device_address_info_ext", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_EXT); }
        else if (std::strncmp(nodeVal, "image_stencil_usage_create_info_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO_EXT); }
        else if (std::strncmp(nodeVal, "physical_device_uniform_buffer_standard_layout_features_khr", 59) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_buffer_device_address_features_khr", 50) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_KHR); }
        else if (std::strncmp(nodeVal, "buffer_device_address_info_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_INFO_KHR); }
        else if (std::strncmp(nodeVal, "buffer_opaque_capture_address_create_info_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "memory_opaque_capture_address_allocate_info_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO_KHR); }
        else if (std::strncmp(nodeVal, "device_memory_opaque_capture_address_info_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_DEVICE_MEMORY_OPAQUE_CAPTURE_ADDRESS_INFO_KHR); }
        else if (std::strncmp(nodeVal, "physical_device_host_query_reset_features_ext", 45) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_STRUCTURE_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkStructureType>(e);
}


static inline ::VkImageLayout hu::val<::VkImageLayout>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageLayout>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "undefined", 9) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_UNDEFINED); }
        else if (std::strncmp(nodeVal, "general", 7) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_GENERAL); }
        else if (std::strncmp(nodeVal, "color_attachment_optimal", 24) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL); }
        else if (std::strncmp(nodeVal, "depth_stencil_attachment_optimal", 32) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL); }
        else if (std::strncmp(nodeVal, "depth_stencil_read_only_optimal", 31) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_STENCIL_READ_ONLY_OPTIMAL); }
        else if (std::strncmp(nodeVal, "shader_read_only_optimal", 24) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL); }
        else if (std::strncmp(nodeVal, "transfer_src_optimal", 20) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL); }
        else if (std::strncmp(nodeVal, "transfer_dst_optimal", 20) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL); }
        else if (std::strncmp(nodeVal, "preinitialized", 14) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_PREINITIALIZED); }
        else if (std::strncmp(nodeVal, "depth_read_only_stencil_attachment_optimal", 42) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL); }
        else if (std::strncmp(nodeVal, "depth_attachment_stencil_read_only_optimal", 42) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL); }
        else if (std::strncmp(nodeVal, "depth_attachment_optimal", 24) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL); }
        else if (std::strncmp(nodeVal, "depth_read_only_optimal", 23) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL); }
        else if (std::strncmp(nodeVal, "stencil_attachment_optimal", 26) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL); }
        else if (std::strncmp(nodeVal, "stencil_read_only_optimal", 25) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL); }
        else if (std::strncmp(nodeVal, "present_src_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_PRESENT_SRC_KHR); }
        else if (std::strncmp(nodeVal, "shared_present_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_SHARED_PRESENT_KHR); }
        else if (std::strncmp(nodeVal, "shading_rate_optimal_nv", 23) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_SHADING_RATE_OPTIMAL_NV); }
        else if (std::strncmp(nodeVal, "fragment_density_map_optimal_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_FRAGMENT_DENSITY_MAP_OPTIMAL_EXT); }
        else if (std::strncmp(nodeVal, "depth_read_only_stencil_attachment_optimal_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_STENCIL_ATTACHMENT_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "depth_attachment_stencil_read_only_optimal_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_STENCIL_READ_ONLY_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_optimal_khr", 44) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_FRAGMENT_SHADING_RATE_ATTACHMENT_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "depth_attachment_optimal_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_ATTACHMENT_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "depth_read_only_optimal_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_DEPTH_READ_ONLY_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "stencil_attachment_optimal_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_STENCIL_ATTACHMENT_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "stencil_read_only_optimal_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_STENCIL_READ_ONLY_OPTIMAL_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_LAYOUT_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageLayout>(e);
}


static inline ::VkObjectType hu::val<::VkObjectType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkObjectType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "unknown", 7) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_UNKNOWN); }
        else if (std::strncmp(nodeVal, "instance", 8) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_INSTANCE); }
        else if (std::strncmp(nodeVal, "physical_device", 15) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PHYSICAL_DEVICE); }
        else if (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DEVICE); }
        else if (std::strncmp(nodeVal, "queue", 5) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_QUEUE); }
        else if (std::strncmp(nodeVal, "semaphore", 9) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SEMAPHORE); }
        else if (std::strncmp(nodeVal, "command_buffer", 14) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_COMMAND_BUFFER); }
        else if (std::strncmp(nodeVal, "fence", 5) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_FENCE); }
        else if (std::strncmp(nodeVal, "device_memory", 13) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DEVICE_MEMORY); }
        else if (std::strncmp(nodeVal, "buffer", 6) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_BUFFER); }
        else if (std::strncmp(nodeVal, "image", 5) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_IMAGE); }
        else if (std::strncmp(nodeVal, "event", 5) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_EVENT); }
        else if (std::strncmp(nodeVal, "query_pool", 10) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_QUERY_POOL); }
        else if (std::strncmp(nodeVal, "buffer_view", 11) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_BUFFER_VIEW); }
        else if (std::strncmp(nodeVal, "image_view", 10) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_IMAGE_VIEW); }
        else if (std::strncmp(nodeVal, "shader_module", 13) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SHADER_MODULE); }
        else if (std::strncmp(nodeVal, "pipeline_cache", 14) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PIPELINE_CACHE); }
        else if (std::strncmp(nodeVal, "pipeline_layout", 15) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PIPELINE_LAYOUT); }
        else if (std::strncmp(nodeVal, "render_pass", 11) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_RENDER_PASS); }
        else if (std::strncmp(nodeVal, "pipeline", 8) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PIPELINE); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout", 21) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT); }
        else if (std::strncmp(nodeVal, "sampler", 7) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SAMPLER); }
        else if (std::strncmp(nodeVal, "descriptor_pool", 15) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DESCRIPTOR_POOL); }
        else if (std::strncmp(nodeVal, "descriptor_set", 14) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DESCRIPTOR_SET); }
        else if (std::strncmp(nodeVal, "framebuffer", 11) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_FRAMEBUFFER); }
        else if (std::strncmp(nodeVal, "command_pool", 12) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_COMMAND_POOL); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion", 24) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION); }
        else if (std::strncmp(nodeVal, "descriptor_update_template", 26) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE); }
        else if (std::strncmp(nodeVal, "surface_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SURFACE_KHR); }
        else if (std::strncmp(nodeVal, "swapchain_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SWAPCHAIN_KHR); }
        else if (std::strncmp(nodeVal, "display_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DISPLAY_KHR); }
        else if (std::strncmp(nodeVal, "display_mode_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DISPLAY_MODE_KHR); }
        else if (std::strncmp(nodeVal, "debug_report_callback_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT); }
        else if (std::strncmp(nodeVal, "debug_utils_messenger_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DEBUG_UTILS_MESSENGER_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR); }
        else if (std::strncmp(nodeVal, "validation_cache_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_VALIDATION_CACHE_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV); }
        else if (std::strncmp(nodeVal, "performance_configuration_intel", 31) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PERFORMANCE_CONFIGURATION_INTEL); }
        else if (std::strncmp(nodeVal, "deferred_operation_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DEFERRED_OPERATION_KHR); }
        else if (std::strncmp(nodeVal, "indirect_commands_layout_nv", 27) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_INDIRECT_COMMANDS_LAYOUT_NV); }
        else if (std::strncmp(nodeVal, "private_data_slot_ext", 21) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_PRIVATE_DATA_SLOT_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_update_template_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_OBJECT_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkObjectType>(e);
}


static inline ::VkVendorId hu::val<::VkVendorId>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkVendorId>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "viv", 3) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_VIV); }
        else if (std::strncmp(nodeVal, "vsi", 3) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_VSI); }
        else if (std::strncmp(nodeVal, "kazan", 5) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_KAZAN); }
        else if (std::strncmp(nodeVal, "codeplay", 8) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_CODEPLAY); }
        else if (std::strncmp(nodeVal, "mesa", 4) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_MESA); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VENDOR_ID_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkVendorId>(e);
}


static inline ::VkPipelineCacheHeaderVersion hu::val<::VkPipelineCacheHeaderVersion>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineCacheHeaderVersion>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "one", 3) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CACHE_HEADER_VERSION_ONE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CACHE_HEADER_VERSION_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineCacheHeaderVersion>(e);
}


static inline ::VkSystemAllocationScope hu::val<::VkSystemAllocationScope>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSystemAllocationScope>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "command", 7) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_COMMAND); }
        else if (std::strncmp(nodeVal, "object", 6) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_OBJECT); }
        else if (std::strncmp(nodeVal, "cache", 5) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_CACHE); }
        else if (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_DEVICE); }
        else if (std::strncmp(nodeVal, "instance", 8) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_INSTANCE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SYSTEM_ALLOCATION_SCOPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSystemAllocationScope>(e);
}


static inline ::VkInternalAllocationType hu::val<::VkInternalAllocationType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkInternalAllocationType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "executable", 10) == 0) { e |= static_cast<enumIntType>(VK_INTERNAL_ALLOCATION_TYPE_EXECUTABLE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_INTERNAL_ALLOCATION_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkInternalAllocationType>(e);
}


static inline ::VkFormat hu::val<::VkFormat>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFormat>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "undefined", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_UNDEFINED); }
        else if (std::strncmp(nodeVal, "r4g4_unorm_pack8", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R4G4_UNORM_PACK8); }
        else if (std::strncmp(nodeVal, "r4g4b4a4_unorm_pack16", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R4G4B4A4_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "b4g4r4a4_unorm_pack16", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B4G4R4A4_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "r5g6b5_unorm_pack16", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R5G6B5_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "b5g6r5_unorm_pack16", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B5G6R5_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "r5g5b5a1_unorm_pack16", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R5G5B5A1_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "b5g5r5a1_unorm_pack16", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B5G5R5A1_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "a1r5g5b5_unorm_pack16", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A1R5G5B5_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "r8_unorm", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_UNORM); }
        else if (std::strncmp(nodeVal, "r8_snorm", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_SNORM); }
        else if (std::strncmp(nodeVal, "r8_uscaled", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_USCALED); }
        else if (std::strncmp(nodeVal, "r8_sscaled", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_SSCALED); }
        else if (std::strncmp(nodeVal, "r8_uint", 7) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_UINT); }
        else if (std::strncmp(nodeVal, "r8_sint", 7) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_SINT); }
        else if (std::strncmp(nodeVal, "r8_srgb", 7) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8_SRGB); }
        else if (std::strncmp(nodeVal, "r8g8_unorm", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_UNORM); }
        else if (std::strncmp(nodeVal, "r8g8_snorm", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_SNORM); }
        else if (std::strncmp(nodeVal, "r8g8_uscaled", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_USCALED); }
        else if (std::strncmp(nodeVal, "r8g8_sscaled", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_SSCALED); }
        else if (std::strncmp(nodeVal, "r8g8_uint", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_UINT); }
        else if (std::strncmp(nodeVal, "r8g8_sint", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_SINT); }
        else if (std::strncmp(nodeVal, "r8g8_srgb", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8_SRGB); }
        else if (std::strncmp(nodeVal, "r8g8b8_unorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_UNORM); }
        else if (std::strncmp(nodeVal, "r8g8b8_snorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_SNORM); }
        else if (std::strncmp(nodeVal, "r8g8b8_uscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_USCALED); }
        else if (std::strncmp(nodeVal, "r8g8b8_sscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_SSCALED); }
        else if (std::strncmp(nodeVal, "r8g8b8_uint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_UINT); }
        else if (std::strncmp(nodeVal, "r8g8b8_sint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_SINT); }
        else if (std::strncmp(nodeVal, "r8g8b8_srgb", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8_SRGB); }
        else if (std::strncmp(nodeVal, "b8g8r8_unorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_UNORM); }
        else if (std::strncmp(nodeVal, "b8g8r8_snorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_SNORM); }
        else if (std::strncmp(nodeVal, "b8g8r8_uscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_USCALED); }
        else if (std::strncmp(nodeVal, "b8g8r8_sscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_SSCALED); }
        else if (std::strncmp(nodeVal, "b8g8r8_uint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_UINT); }
        else if (std::strncmp(nodeVal, "b8g8r8_sint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_SINT); }
        else if (std::strncmp(nodeVal, "b8g8r8_srgb", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8_SRGB); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_unorm", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_UNORM); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_snorm", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_SNORM); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_uscaled", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_USCALED); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_sscaled", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_SSCALED); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_uint", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_UINT); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_sint", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_SINT); }
        else if (std::strncmp(nodeVal, "r8g8b8a8_srgb", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R8G8B8A8_SRGB); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_unorm", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_UNORM); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_snorm", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_SNORM); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_uscaled", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_USCALED); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_sscaled", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_SSCALED); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_uint", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_UINT); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_sint", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_SINT); }
        else if (std::strncmp(nodeVal, "b8g8r8a8_srgb", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8A8_SRGB); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_unorm_pack32", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_UNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_snorm_pack32", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_SNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_uscaled_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_USCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_sscaled_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_SSCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_uint_pack32", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_UINT_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_sint_pack32", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_SINT_PACK32); }
        else if (std::strncmp(nodeVal, "a8b8g8r8_srgb_pack32", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A8B8G8R8_SRGB_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_unorm_pack32", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_UNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_snorm_pack32", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_SNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_uscaled_pack32", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_USCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_sscaled_pack32", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_SSCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_uint_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_UINT_PACK32); }
        else if (std::strncmp(nodeVal, "a2r10g10b10_sint_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2R10G10B10_SINT_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_unorm_pack32", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_UNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_snorm_pack32", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_SNORM_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_uscaled_pack32", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_USCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_sscaled_pack32", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_SSCALED_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_uint_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_UINT_PACK32); }
        else if (std::strncmp(nodeVal, "a2b10g10r10_sint_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A2B10G10R10_SINT_PACK32); }
        else if (std::strncmp(nodeVal, "r16_unorm", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_UNORM); }
        else if (std::strncmp(nodeVal, "r16_snorm", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_SNORM); }
        else if (std::strncmp(nodeVal, "r16_uscaled", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_USCALED); }
        else if (std::strncmp(nodeVal, "r16_sscaled", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_SSCALED); }
        else if (std::strncmp(nodeVal, "r16_uint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_UINT); }
        else if (std::strncmp(nodeVal, "r16_sint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_SINT); }
        else if (std::strncmp(nodeVal, "r16_sfloat", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16_SFLOAT); }
        else if (std::strncmp(nodeVal, "r16g16_unorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_UNORM); }
        else if (std::strncmp(nodeVal, "r16g16_snorm", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_SNORM); }
        else if (std::strncmp(nodeVal, "r16g16_uscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_USCALED); }
        else if (std::strncmp(nodeVal, "r16g16_sscaled", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_SSCALED); }
        else if (std::strncmp(nodeVal, "r16g16_uint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_UINT); }
        else if (std::strncmp(nodeVal, "r16g16_sint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_SINT); }
        else if (std::strncmp(nodeVal, "r16g16_sfloat", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16_SFLOAT); }
        else if (std::strncmp(nodeVal, "r16g16b16_unorm", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_UNORM); }
        else if (std::strncmp(nodeVal, "r16g16b16_snorm", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_SNORM); }
        else if (std::strncmp(nodeVal, "r16g16b16_uscaled", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_USCALED); }
        else if (std::strncmp(nodeVal, "r16g16b16_sscaled", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_SSCALED); }
        else if (std::strncmp(nodeVal, "r16g16b16_uint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_UINT); }
        else if (std::strncmp(nodeVal, "r16g16b16_sint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_SINT); }
        else if (std::strncmp(nodeVal, "r16g16b16_sfloat", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16_SFLOAT); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_unorm", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_UNORM); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_snorm", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_SNORM); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_uscaled", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_USCALED); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_sscaled", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_SSCALED); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_uint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_UINT); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_sint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_SINT); }
        else if (std::strncmp(nodeVal, "r16g16b16a16_sfloat", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R16G16B16A16_SFLOAT); }
        else if (std::strncmp(nodeVal, "r32_uint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32_UINT); }
        else if (std::strncmp(nodeVal, "r32_sint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32_SINT); }
        else if (std::strncmp(nodeVal, "r32_sfloat", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32_SFLOAT); }
        else if (std::strncmp(nodeVal, "r32g32_uint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32_UINT); }
        else if (std::strncmp(nodeVal, "r32g32_sint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32_SINT); }
        else if (std::strncmp(nodeVal, "r32g32_sfloat", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32_SFLOAT); }
        else if (std::strncmp(nodeVal, "r32g32b32_uint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32_UINT); }
        else if (std::strncmp(nodeVal, "r32g32b32_sint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32_SINT); }
        else if (std::strncmp(nodeVal, "r32g32b32_sfloat", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32_SFLOAT); }
        else if (std::strncmp(nodeVal, "r32g32b32a32_uint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32A32_UINT); }
        else if (std::strncmp(nodeVal, "r32g32b32a32_sint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32A32_SINT); }
        else if (std::strncmp(nodeVal, "r32g32b32a32_sfloat", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R32G32B32A32_SFLOAT); }
        else if (std::strncmp(nodeVal, "r64_uint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64_UINT); }
        else if (std::strncmp(nodeVal, "r64_sint", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64_SINT); }
        else if (std::strncmp(nodeVal, "r64_sfloat", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64_SFLOAT); }
        else if (std::strncmp(nodeVal, "r64g64_uint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64_UINT); }
        else if (std::strncmp(nodeVal, "r64g64_sint", 11) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64_SINT); }
        else if (std::strncmp(nodeVal, "r64g64_sfloat", 13) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64_SFLOAT); }
        else if (std::strncmp(nodeVal, "r64g64b64_uint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64_UINT); }
        else if (std::strncmp(nodeVal, "r64g64b64_sint", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64_SINT); }
        else if (std::strncmp(nodeVal, "r64g64b64_sfloat", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64_SFLOAT); }
        else if (std::strncmp(nodeVal, "r64g64b64a64_uint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64A64_UINT); }
        else if (std::strncmp(nodeVal, "r64g64b64a64_sint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64A64_SINT); }
        else if (std::strncmp(nodeVal, "r64g64b64a64_sfloat", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R64G64B64A64_SFLOAT); }
        else if (std::strncmp(nodeVal, "b10g11r11_ufloat_pack32", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B10G11R11_UFLOAT_PACK32); }
        else if (std::strncmp(nodeVal, "e5b9g9r9_ufloat_pack32", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_E5B9G9R9_UFLOAT_PACK32); }
        else if (std::strncmp(nodeVal, "d16_unorm", 9) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_D16_UNORM); }
        else if (std::strncmp(nodeVal, "x8_d24_unorm_pack32", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_X8_D24_UNORM_PACK32); }
        else if (std::strncmp(nodeVal, "d32_sfloat", 10) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_D32_SFLOAT); }
        else if (std::strncmp(nodeVal, "s8_uint", 7) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_S8_UINT); }
        else if (std::strncmp(nodeVal, "d16_unorm_s8_uint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_D16_UNORM_S8_UINT); }
        else if (std::strncmp(nodeVal, "d24_unorm_s8_uint", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_D24_UNORM_S8_UINT); }
        else if (std::strncmp(nodeVal, "d32_sfloat_s8_uint", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_D32_SFLOAT_S8_UINT); }
        else if (std::strncmp(nodeVal, "bc1_rgb_unorm_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC1_RGB_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc1_rgb_srgb_block", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC1_RGB_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "bc1_rgba_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC1_RGBA_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc1_rgba_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC1_RGBA_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "bc2_unorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC2_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc2_srgb_block", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC2_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "bc3_unorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC3_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc3_srgb_block", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC3_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "bc4_unorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC4_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc4_snorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC4_SNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc5_unorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC5_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc5_snorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC5_SNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc6h_ufloat_block", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC6H_UFLOAT_BLOCK); }
        else if (std::strncmp(nodeVal, "bc6h_sfloat_block", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC6H_SFLOAT_BLOCK); }
        else if (std::strncmp(nodeVal, "bc7_unorm_block", 15) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC7_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "bc7_srgb_block", 14) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_BC7_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8_unorm_block", 23) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8_srgb_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8a1_unorm_block", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8A1_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8a1_srgb_block", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8A1_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8a8_unorm_block", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8A8_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "etc2_r8g8b8a8_srgb_block", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ETC2_R8G8B8A8_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "eac_r11_unorm_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_EAC_R11_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "eac_r11_snorm_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_EAC_R11_SNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "eac_r11g11_unorm_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_EAC_R11G11_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "eac_r11g11_snorm_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_EAC_R11G11_SNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_4x4_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_4x4_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_4x4_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_4x4_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_5x4_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x4_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_5x4_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x4_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_5x5_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x5_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_5x5_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x5_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_6x5_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x5_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_6x5_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x5_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_6x6_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x6_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_6x6_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x6_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x5_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x5_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x5_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x5_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x6_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x6_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x6_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x6_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x8_unorm_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x8_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_8x8_srgb_block", 19) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x8_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x5_unorm_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x5_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x5_srgb_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x5_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x6_unorm_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x6_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x6_srgb_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x6_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x8_unorm_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x8_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x8_srgb_block", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x8_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x10_unorm_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x10_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_10x10_srgb_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x10_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_12x10_unorm_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x10_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_12x10_srgb_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x10_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_12x12_unorm_block", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x12_UNORM_BLOCK); }
        else if (std::strncmp(nodeVal, "astc_12x12_srgb_block", 21) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x12_SRGB_BLOCK); }
        else if (std::strncmp(nodeVal, "g8b8g8r8_422_unorm", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8B8G8R8_422_UNORM); }
        else if (std::strncmp(nodeVal, "b8g8r8g8_422_unorm", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8G8_422_UNORM); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_420_unorm", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM); }
        else if (std::strncmp(nodeVal, "g8_b8r8_2plane_420_unorm", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_422_unorm", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM); }
        else if (std::strncmp(nodeVal, "g8_b8r8_2plane_422_unorm", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_444_unorm", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM); }
        else if (std::strncmp(nodeVal, "r10x6_unorm_pack16", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "r10x6g10x6_unorm_2pack16", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6G10X6_UNORM_2PACK16); }
        else if (std::strncmp(nodeVal, "r10x6g10x6b10x6a10x6_unorm_4pack16", 34) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "g10x6b10x6g10x6r10x6_422_unorm_4pack16", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "b10x6g10x6r10x6g10x6_422_unorm_4pack16", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_420_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6r10x6_2plane_420_unorm_3pack16", 41) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_422_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6r10x6_2plane_422_unorm_3pack16", 41) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_444_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "r12x4_unorm_pack16", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4_UNORM_PACK16); }
        else if (std::strncmp(nodeVal, "r12x4g12x4_unorm_2pack16", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4G12X4_UNORM_2PACK16); }
        else if (std::strncmp(nodeVal, "r12x4g12x4b12x4a12x4_unorm_4pack16", 34) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "g12x4b12x4g12x4r12x4_422_unorm_4pack16", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "b12x4g12x4r12x4g12x4_422_unorm_4pack16", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_420_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4r12x4_2plane_420_unorm_3pack16", 41) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_422_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4r12x4_2plane_422_unorm_3pack16", 41) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_444_unorm_3pack16", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16); }
        else if (std::strncmp(nodeVal, "g16b16g16r16_422_unorm", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16B16G16R16_422_UNORM); }
        else if (std::strncmp(nodeVal, "b16g16r16g16_422_unorm", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B16G16R16G16_422_UNORM); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_420_unorm", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM); }
        else if (std::strncmp(nodeVal, "g16_b16r16_2plane_420_unorm", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_422_unorm", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM); }
        else if (std::strncmp(nodeVal, "g16_b16r16_2plane_422_unorm", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_444_unorm", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM); }
        else if (std::strncmp(nodeVal, "pvrtc1_2bpp_unorm_block_img", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC1_2BPP_UNORM_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc1_4bpp_unorm_block_img", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC1_4BPP_UNORM_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc2_2bpp_unorm_block_img", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC2_2BPP_UNORM_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc2_4bpp_unorm_block_img", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC2_4BPP_UNORM_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc1_2bpp_srgb_block_img", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC1_2BPP_SRGB_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc1_4bpp_srgb_block_img", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC1_4BPP_SRGB_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc2_2bpp_srgb_block_img", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC2_2BPP_SRGB_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "pvrtc2_4bpp_srgb_block_img", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_PVRTC2_4BPP_SRGB_BLOCK_IMG); }
        else if (std::strncmp(nodeVal, "astc_4x4_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_4x4_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_5x4_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x4_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_5x5_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_5x5_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_6x5_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x5_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_6x6_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_6x6_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_8x5_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x5_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_8x6_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x6_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_8x8_sfloat_block_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_8x8_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_10x5_sfloat_block_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x5_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_10x6_sfloat_block_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x6_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_10x8_sfloat_block_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x8_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_10x10_sfloat_block_ext", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_10x10_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_12x10_sfloat_block_ext", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x10_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "astc_12x12_sfloat_block_ext", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_ASTC_12x12_SFLOAT_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "a4r4g4b4_unorm_pack16_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A4R4G4B4_UNORM_PACK16_EXT); }
        else if (std::strncmp(nodeVal, "a4b4g4r4_unorm_pack16_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_A4B4G4R4_UNORM_PACK16_EXT); }
        else if (std::strncmp(nodeVal, "g8b8g8r8_422_unorm_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8B8G8R8_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "b8g8r8g8_422_unorm_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B8G8R8G8_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_420_unorm_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_420_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g8_b8r8_2plane_420_unorm_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8R8_2PLANE_420_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_422_unorm_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g8_b8r8_2plane_422_unorm_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8R8_2PLANE_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g8_b8_r8_3plane_444_unorm_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G8_B8_R8_3PLANE_444_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "r10x6_unorm_pack16_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6_UNORM_PACK16_KHR); }
        else if (std::strncmp(nodeVal, "r10x6g10x6_unorm_2pack16_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6G10X6_UNORM_2PACK16_KHR); }
        else if (std::strncmp(nodeVal, "r10x6g10x6b10x6a10x6_unorm_4pack16_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R10X6G10X6B10X6A10X6_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6b10x6g10x6r10x6_422_unorm_4pack16_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6B10X6G10X6R10X6_422_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "b10x6g10x6r10x6g10x6_422_unorm_4pack16_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B10X6G10X6R10X6G10X6_422_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_420_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_420_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6r10x6_2plane_420_unorm_3pack16_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_420_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_422_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_422_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6r10x6_2plane_422_unorm_3pack16_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6R10X6_2PLANE_422_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g10x6_b10x6_r10x6_3plane_444_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G10X6_B10X6_R10X6_3PLANE_444_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "r12x4_unorm_pack16_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4_UNORM_PACK16_KHR); }
        else if (std::strncmp(nodeVal, "r12x4g12x4_unorm_2pack16_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4G12X4_UNORM_2PACK16_KHR); }
        else if (std::strncmp(nodeVal, "r12x4g12x4b12x4a12x4_unorm_4pack16_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_R12X4G12X4B12X4A12X4_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4b12x4g12x4r12x4_422_unorm_4pack16_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4B12X4G12X4R12X4_422_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "b12x4g12x4r12x4g12x4_422_unorm_4pack16_khr", 42) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B12X4G12X4R12X4G12X4_422_UNORM_4PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_420_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_420_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4r12x4_2plane_420_unorm_3pack16_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_420_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_422_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_422_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4r12x4_2plane_422_unorm_3pack16_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4R12X4_2PLANE_422_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g12x4_b12x4_r12x4_3plane_444_unorm_3pack16_khr", 46) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G12X4_B12X4_R12X4_3PLANE_444_UNORM_3PACK16_KHR); }
        else if (std::strncmp(nodeVal, "g16b16g16r16_422_unorm_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16B16G16R16_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "b16g16r16g16_422_unorm_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_B16G16R16G16_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_420_unorm_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_420_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g16_b16r16_2plane_420_unorm_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16R16_2PLANE_420_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_422_unorm_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g16_b16r16_2plane_422_unorm_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16R16_2PLANE_422_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "g16_b16_r16_3plane_444_unorm_khr", 32) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_G16_B16_R16_3PLANE_444_UNORM_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFormat>(e);
}


static inline ::VkImageTiling hu::val<::VkImageTiling>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageTiling>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "optimal", 7) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TILING_OPTIMAL); }
        else if (std::strncmp(nodeVal, "linear", 6) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TILING_LINEAR); }
        else if (std::strncmp(nodeVal, "drm_format_modifier_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TILING_DRM_FORMAT_MODIFIER_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TILING_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageTiling>(e);
}


static inline ::VkImageType hu::val<::VkImageType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "1d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TYPE_1D); }
        else if (std::strncmp(nodeVal, "2d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TYPE_2D); }
        else if (std::strncmp(nodeVal, "3d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TYPE_3D); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageType>(e);
}


static inline ::VkPhysicalDeviceType hu::val<::VkPhysicalDeviceType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPhysicalDeviceType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "other", 5) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_OTHER); }
        else if (std::strncmp(nodeVal, "integrated_gpu", 14) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU); }
        else if (std::strncmp(nodeVal, "discrete_gpu", 12) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU); }
        else if (std::strncmp(nodeVal, "virtual_gpu", 11) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU); }
        else if (std::strncmp(nodeVal, "cpu", 3) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_CPU); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PHYSICAL_DEVICE_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPhysicalDeviceType>(e);
}


static inline ::VkQueryType hu::val<::VkQueryType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueryType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "occlusion", 9) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_OCCLUSION); }
        else if (std::strncmp(nodeVal, "pipeline_statistics", 19) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_PIPELINE_STATISTICS); }
        else if (std::strncmp(nodeVal, "timestamp", 9) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_TIMESTAMP); }
        else if (std::strncmp(nodeVal, "transform_feedback_stream_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_TRANSFORM_FEEDBACK_STREAM_EXT); }
        else if (std::strncmp(nodeVal, "performance_query_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_PERFORMANCE_QUERY_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_compacted_size_khr", 41) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_serialization_size_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_ACCELERATION_STRUCTURE_SERIALIZATION_SIZE_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_compacted_size_nv", 40) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_ACCELERATION_STRUCTURE_COMPACTED_SIZE_NV); }
        else if (std::strncmp(nodeVal, "performance_query_intel", 23) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_PERFORMANCE_QUERY_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_QUERY_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueryType>(e);
}


static inline ::VkSharingMode hu::val<::VkSharingMode>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSharingMode>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "exclusive", 9) == 0) { e |= static_cast<enumIntType>(VK_SHARING_MODE_EXCLUSIVE); }
        else if (std::strncmp(nodeVal, "concurrent", 10) == 0) { e |= static_cast<enumIntType>(VK_SHARING_MODE_CONCURRENT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SHARING_MODE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSharingMode>(e);
}


static inline ::VkComponentSwizzle hu::val<::VkComponentSwizzle>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkComponentSwizzle>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "identity", 8) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_IDENTITY); }
        else if (std::strncmp(nodeVal, "zero", 4) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_ZERO); }
        else if (std::strncmp(nodeVal, "one", 3) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_ONE); }
        else if (std::strncmp(nodeVal, "r", 1) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_R); }
        else if (std::strncmp(nodeVal, "g", 1) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_G); }
        else if (std::strncmp(nodeVal, "b", 1) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_B); }
        else if (std::strncmp(nodeVal, "a", 1) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_A); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_SWIZZLE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkComponentSwizzle>(e);
}


static inline ::VkImageViewType hu::val<::VkImageViewType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageViewType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "1d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_1D); }
        else if (std::strncmp(nodeVal, "2d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_2D); }
        else if (std::strncmp(nodeVal, "3d", 2) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_3D); }
        else if (std::strncmp(nodeVal, "cube", 4) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_CUBE); }
        else if (std::strncmp(nodeVal, "1d_array", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_1D_ARRAY); }
        else if (std::strncmp(nodeVal, "2d_array", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_2D_ARRAY); }
        else if (std::strncmp(nodeVal, "cube_array", 10) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_CUBE_ARRAY); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageViewType>(e);
}


static inline ::VkBlendFactor hu::val<::VkBlendFactor>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBlendFactor>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "zero", 4) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ZERO); }
        else if (std::strncmp(nodeVal, "one", 3) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE); }
        else if (std::strncmp(nodeVal, "src_color", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_SRC_COLOR); }
        else if (std::strncmp(nodeVal, "one_minus_src_color", 19) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_SRC_COLOR); }
        else if (std::strncmp(nodeVal, "dst_color", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_DST_COLOR); }
        else if (std::strncmp(nodeVal, "one_minus_dst_color", 19) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_DST_COLOR); }
        else if (std::strncmp(nodeVal, "src_alpha", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_SRC_ALPHA); }
        else if (std::strncmp(nodeVal, "one_minus_src_alpha", 19) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA); }
        else if (std::strncmp(nodeVal, "dst_alpha", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_DST_ALPHA); }
        else if (std::strncmp(nodeVal, "one_minus_dst_alpha", 19) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_DST_ALPHA); }
        else if (std::strncmp(nodeVal, "constant_color", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_CONSTANT_COLOR); }
        else if (std::strncmp(nodeVal, "one_minus_constant_color", 24) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_COLOR); }
        else if (std::strncmp(nodeVal, "constant_alpha", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_CONSTANT_ALPHA); }
        else if (std::strncmp(nodeVal, "one_minus_constant_alpha", 24) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_CONSTANT_ALPHA); }
        else if (std::strncmp(nodeVal, "src_alpha_saturate", 18) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_SRC_ALPHA_SATURATE); }
        else if (std::strncmp(nodeVal, "src1_color", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_SRC1_COLOR); }
        else if (std::strncmp(nodeVal, "one_minus_src1_color", 20) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_SRC1_COLOR); }
        else if (std::strncmp(nodeVal, "src1_alpha", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_SRC1_ALPHA); }
        else if (std::strncmp(nodeVal, "one_minus_src1_alpha", 20) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_ONE_MINUS_SRC1_ALPHA); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_FACTOR_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBlendFactor>(e);
}


static inline ::VkBlendOp hu::val<::VkBlendOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBlendOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "add", 3) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_ADD); }
        else if (std::strncmp(nodeVal, "subtract", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SUBTRACT); }
        else if (std::strncmp(nodeVal, "reverse_subtract", 16) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_REVERSE_SUBTRACT); }
        else if (std::strncmp(nodeVal, "min", 3) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MIN); }
        else if (std::strncmp(nodeVal, "max", 3) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MAX); }
        else if (std::strncmp(nodeVal, "zero_ext", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_ZERO_EXT); }
        else if (std::strncmp(nodeVal, "src_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SRC_EXT); }
        else if (std::strncmp(nodeVal, "dst_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DST_EXT); }
        else if (std::strncmp(nodeVal, "src_over_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SRC_OVER_EXT); }
        else if (std::strncmp(nodeVal, "dst_over_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DST_OVER_EXT); }
        else if (std::strncmp(nodeVal, "src_in_ext", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SRC_IN_EXT); }
        else if (std::strncmp(nodeVal, "dst_in_ext", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DST_IN_EXT); }
        else if (std::strncmp(nodeVal, "src_out_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SRC_OUT_EXT); }
        else if (std::strncmp(nodeVal, "dst_out_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DST_OUT_EXT); }
        else if (std::strncmp(nodeVal, "src_atop_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SRC_ATOP_EXT); }
        else if (std::strncmp(nodeVal, "dst_atop_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DST_ATOP_EXT); }
        else if (std::strncmp(nodeVal, "xor_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_XOR_EXT); }
        else if (std::strncmp(nodeVal, "multiply_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MULTIPLY_EXT); }
        else if (std::strncmp(nodeVal, "screen_ext", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SCREEN_EXT); }
        else if (std::strncmp(nodeVal, "overlay_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_OVERLAY_EXT); }
        else if (std::strncmp(nodeVal, "darken_ext", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DARKEN_EXT); }
        else if (std::strncmp(nodeVal, "lighten_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_LIGHTEN_EXT); }
        else if (std::strncmp(nodeVal, "colordodge_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_COLORDODGE_EXT); }
        else if (std::strncmp(nodeVal, "colorburn_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_COLORBURN_EXT); }
        else if (std::strncmp(nodeVal, "hardlight_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HARDLIGHT_EXT); }
        else if (std::strncmp(nodeVal, "softlight_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_SOFTLIGHT_EXT); }
        else if (std::strncmp(nodeVal, "difference_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_DIFFERENCE_EXT); }
        else if (std::strncmp(nodeVal, "exclusion_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_EXCLUSION_EXT); }
        else if (std::strncmp(nodeVal, "invert_ext", 10) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_INVERT_EXT); }
        else if (std::strncmp(nodeVal, "invert_rgb_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_INVERT_RGB_EXT); }
        else if (std::strncmp(nodeVal, "lineardodge_ext", 15) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_LINEARDODGE_EXT); }
        else if (std::strncmp(nodeVal, "linearburn_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_LINEARBURN_EXT); }
        else if (std::strncmp(nodeVal, "vividlight_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_VIVIDLIGHT_EXT); }
        else if (std::strncmp(nodeVal, "linearlight_ext", 15) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_LINEARLIGHT_EXT); }
        else if (std::strncmp(nodeVal, "pinlight_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_PINLIGHT_EXT); }
        else if (std::strncmp(nodeVal, "hardmix_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HARDMIX_EXT); }
        else if (std::strncmp(nodeVal, "hsl_hue_ext", 11) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HSL_HUE_EXT); }
        else if (std::strncmp(nodeVal, "hsl_saturation_ext", 18) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HSL_SATURATION_EXT); }
        else if (std::strncmp(nodeVal, "hsl_color_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HSL_COLOR_EXT); }
        else if (std::strncmp(nodeVal, "hsl_luminosity_ext", 18) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_HSL_LUMINOSITY_EXT); }
        else if (std::strncmp(nodeVal, "plus_ext", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_PLUS_EXT); }
        else if (std::strncmp(nodeVal, "plus_clamped_ext", 16) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_PLUS_CLAMPED_EXT); }
        else if (std::strncmp(nodeVal, "plus_clamped_alpha_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_PLUS_CLAMPED_ALPHA_EXT); }
        else if (std::strncmp(nodeVal, "plus_darker_ext", 15) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_PLUS_DARKER_EXT); }
        else if (std::strncmp(nodeVal, "minus_ext", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MINUS_EXT); }
        else if (std::strncmp(nodeVal, "minus_clamped_ext", 17) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MINUS_CLAMPED_EXT); }
        else if (std::strncmp(nodeVal, "contrast_ext", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_CONTRAST_EXT); }
        else if (std::strncmp(nodeVal, "invert_ovg_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_INVERT_OVG_EXT); }
        else if (std::strncmp(nodeVal, "red_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_RED_EXT); }
        else if (std::strncmp(nodeVal, "green_ext", 9) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_GREEN_EXT); }
        else if (std::strncmp(nodeVal, "blue_ext", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_BLUE_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBlendOp>(e);
}


static inline ::VkCompareOp hu::val<::VkCompareOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCompareOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "never", 5) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_NEVER); }
        else if (std::strncmp(nodeVal, "less", 4) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_LESS); }
        else if (std::strncmp(nodeVal, "equal", 5) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_EQUAL); }
        else if (std::strncmp(nodeVal, "less_or_equal", 13) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_LESS_OR_EQUAL); }
        else if (std::strncmp(nodeVal, "greater", 7) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_GREATER); }
        else if (std::strncmp(nodeVal, "not_equal", 9) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_NOT_EQUAL); }
        else if (std::strncmp(nodeVal, "greater_or_equal", 16) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_GREATER_OR_EQUAL); }
        else if (std::strncmp(nodeVal, "always", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_ALWAYS); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COMPARE_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCompareOp>(e);
}


static inline ::VkDynamicState hu::val<::VkDynamicState>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDynamicState>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "viewport", 8) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VIEWPORT); }
        else if (std::strncmp(nodeVal, "scissor", 7) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_SCISSOR); }
        else if (std::strncmp(nodeVal, "line_width", 10) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_LINE_WIDTH); }
        else if (std::strncmp(nodeVal, "depth_bias", 10) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_BIAS); }
        else if (std::strncmp(nodeVal, "blend_constants", 15) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_BLEND_CONSTANTS); }
        else if (std::strncmp(nodeVal, "depth_bounds", 12) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_BOUNDS); }
        else if (std::strncmp(nodeVal, "stencil_compare_mask", 20) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_STENCIL_COMPARE_MASK); }
        else if (std::strncmp(nodeVal, "stencil_write_mask", 18) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_STENCIL_WRITE_MASK); }
        else if (std::strncmp(nodeVal, "stencil_reference", 17) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_STENCIL_REFERENCE); }
        else if (std::strncmp(nodeVal, "viewport_w_scaling_nv", 21) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VIEWPORT_W_SCALING_NV); }
        else if (std::strncmp(nodeVal, "discard_rectangle_ext", 21) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DISCARD_RECTANGLE_EXT); }
        else if (std::strncmp(nodeVal, "sample_locations_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_SAMPLE_LOCATIONS_EXT); }
        else if (std::strncmp(nodeVal, "ray_tracing_pipeline_stack_size_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_RAY_TRACING_PIPELINE_STACK_SIZE_KHR); }
        else if (std::strncmp(nodeVal, "viewport_shading_rate_palette_nv", 32) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VIEWPORT_SHADING_RATE_PALETTE_NV); }
        else if (std::strncmp(nodeVal, "viewport_coarse_sample_order_nv", 31) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VIEWPORT_COARSE_SAMPLE_ORDER_NV); }
        else if (std::strncmp(nodeVal, "exclusive_scissor_nv", 20) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_EXCLUSIVE_SCISSOR_NV); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_FRAGMENT_SHADING_RATE_KHR); }
        else if (std::strncmp(nodeVal, "line_stipple_ext", 16) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_LINE_STIPPLE_EXT); }
        else if (std::strncmp(nodeVal, "cull_mode_ext", 13) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_CULL_MODE_EXT); }
        else if (std::strncmp(nodeVal, "front_face_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_FRONT_FACE_EXT); }
        else if (std::strncmp(nodeVal, "primitive_topology_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_PRIMITIVE_TOPOLOGY_EXT); }
        else if (std::strncmp(nodeVal, "viewport_with_count_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VIEWPORT_WITH_COUNT_EXT); }
        else if (std::strncmp(nodeVal, "scissor_with_count_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_SCISSOR_WITH_COUNT_EXT); }
        else if (std::strncmp(nodeVal, "vertex_input_binding_stride_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_VERTEX_INPUT_BINDING_STRIDE_EXT); }
        else if (std::strncmp(nodeVal, "depth_test_enable_ext", 21) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_TEST_ENABLE_EXT); }
        else if (std::strncmp(nodeVal, "depth_write_enable_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_WRITE_ENABLE_EXT); }
        else if (std::strncmp(nodeVal, "depth_compare_op_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_COMPARE_OP_EXT); }
        else if (std::strncmp(nodeVal, "depth_bounds_test_enable_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_DEPTH_BOUNDS_TEST_ENABLE_EXT); }
        else if (std::strncmp(nodeVal, "stencil_test_enable_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_STENCIL_TEST_ENABLE_EXT); }
        else if (std::strncmp(nodeVal, "stencil_op_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_STENCIL_OP_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DYNAMIC_STATE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDynamicState>(e);
}


static inline ::VkFrontFace hu::val<::VkFrontFace>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFrontFace>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "counter_clockwise", 17) == 0) { e |= static_cast<enumIntType>(VK_FRONT_FACE_COUNTER_CLOCKWISE); }
        else if (std::strncmp(nodeVal, "clockwise", 9) == 0) { e |= static_cast<enumIntType>(VK_FRONT_FACE_CLOCKWISE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FRONT_FACE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFrontFace>(e);
}


static inline ::VkVertexInputRate hu::val<::VkVertexInputRate>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkVertexInputRate>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vertex", 6) == 0) { e |= static_cast<enumIntType>(VK_VERTEX_INPUT_RATE_VERTEX); }
        else if (std::strncmp(nodeVal, "instance", 8) == 0) { e |= static_cast<enumIntType>(VK_VERTEX_INPUT_RATE_INSTANCE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VERTEX_INPUT_RATE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkVertexInputRate>(e);
}


static inline ::VkPrimitiveTopology hu::val<::VkPrimitiveTopology>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPrimitiveTopology>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "point_list", 10) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_POINT_LIST); }
        else if (std::strncmp(nodeVal, "line_list", 9) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_LINE_LIST); }
        else if (std::strncmp(nodeVal, "line_strip", 10) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_LINE_STRIP); }
        else if (std::strncmp(nodeVal, "triangle_list", 13) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST); }
        else if (std::strncmp(nodeVal, "triangle_strip", 14) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP); }
        else if (std::strncmp(nodeVal, "triangle_fan", 12) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_FAN); }
        else if (std::strncmp(nodeVal, "line_list_with_adjacency", 24) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_LINE_LIST_WITH_ADJACENCY); }
        else if (std::strncmp(nodeVal, "line_strip_with_adjacency", 25) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_LINE_STRIP_WITH_ADJACENCY); }
        else if (std::strncmp(nodeVal, "triangle_list_with_adjacency", 28) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST_WITH_ADJACENCY); }
        else if (std::strncmp(nodeVal, "triangle_strip_with_adjacency", 29) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP_WITH_ADJACENCY); }
        else if (std::strncmp(nodeVal, "patch_list", 10) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_PATCH_LIST); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PRIMITIVE_TOPOLOGY_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPrimitiveTopology>(e);
}


static inline ::VkPolygonMode hu::val<::VkPolygonMode>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPolygonMode>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "fill", 4) == 0) { e |= static_cast<enumIntType>(VK_POLYGON_MODE_FILL); }
        else if (std::strncmp(nodeVal, "line", 4) == 0) { e |= static_cast<enumIntType>(VK_POLYGON_MODE_LINE); }
        else if (std::strncmp(nodeVal, "point", 5) == 0) { e |= static_cast<enumIntType>(VK_POLYGON_MODE_POINT); }
        else if (std::strncmp(nodeVal, "fill_rectangle_nv", 17) == 0) { e |= static_cast<enumIntType>(VK_POLYGON_MODE_FILL_RECTANGLE_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_POLYGON_MODE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPolygonMode>(e);
}


static inline ::VkStencilOp hu::val<::VkStencilOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkStencilOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "keep", 4) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_KEEP); }
        else if (std::strncmp(nodeVal, "zero", 4) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_ZERO); }
        else if (std::strncmp(nodeVal, "replace", 7) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_REPLACE); }
        else if (std::strncmp(nodeVal, "increment_and_clamp", 19) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_INCREMENT_AND_CLAMP); }
        else if (std::strncmp(nodeVal, "decrement_and_clamp", 19) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_DECREMENT_AND_CLAMP); }
        else if (std::strncmp(nodeVal, "invert", 6) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_INVERT); }
        else if (std::strncmp(nodeVal, "increment_and_wrap", 18) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_INCREMENT_AND_WRAP); }
        else if (std::strncmp(nodeVal, "decrement_and_wrap", 18) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_DECREMENT_AND_WRAP); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkStencilOp>(e);
}


static inline ::VkLogicOp hu::val<::VkLogicOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkLogicOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "clear", 5) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_CLEAR); }
        else if (std::strncmp(nodeVal, "and", 3) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_AND); }
        else if (std::strncmp(nodeVal, "and_reverse", 11) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_AND_REVERSE); }
        else if (std::strncmp(nodeVal, "copy", 4) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_COPY); }
        else if (std::strncmp(nodeVal, "and_inverted", 12) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_AND_INVERTED); }
        else if (std::strncmp(nodeVal, "no_op", 5) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_NO_OP); }
        else if (std::strncmp(nodeVal, "xor", 3) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_XOR); }
        else if (std::strncmp(nodeVal, "or", 2) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_OR); }
        else if (std::strncmp(nodeVal, "nor", 3) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_NOR); }
        else if (std::strncmp(nodeVal, "equivalent", 10) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_EQUIVALENT); }
        else if (std::strncmp(nodeVal, "invert", 6) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_INVERT); }
        else if (std::strncmp(nodeVal, "or_reverse", 10) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_OR_REVERSE); }
        else if (std::strncmp(nodeVal, "copy_inverted", 13) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_COPY_INVERTED); }
        else if (std::strncmp(nodeVal, "or_inverted", 11) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_OR_INVERTED); }
        else if (std::strncmp(nodeVal, "nand", 4) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_NAND); }
        else if (std::strncmp(nodeVal, "set", 3) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_SET); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_LOGIC_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkLogicOp>(e);
}


static inline ::VkBorderColor hu::val<::VkBorderColor>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBorderColor>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "float_transparent_black", 23) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_FLOAT_TRANSPARENT_BLACK); }
        else if (std::strncmp(nodeVal, "int_transparent_black", 21) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_INT_TRANSPARENT_BLACK); }
        else if (std::strncmp(nodeVal, "float_opaque_black", 18) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_FLOAT_OPAQUE_BLACK); }
        else if (std::strncmp(nodeVal, "int_opaque_black", 16) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_INT_OPAQUE_BLACK); }
        else if (std::strncmp(nodeVal, "float_opaque_white", 18) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE); }
        else if (std::strncmp(nodeVal, "int_opaque_white", 16) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_INT_OPAQUE_WHITE); }
        else if (std::strncmp(nodeVal, "float_custom_ext", 16) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_FLOAT_CUSTOM_EXT); }
        else if (std::strncmp(nodeVal, "int_custom_ext", 14) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_INT_CUSTOM_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_BORDER_COLOR_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBorderColor>(e);
}


static inline ::VkFilter hu::val<::VkFilter>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFilter>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "nearest", 7) == 0) { e |= static_cast<enumIntType>(VK_FILTER_NEAREST); }
        else if (std::strncmp(nodeVal, "linear", 6) == 0) { e |= static_cast<enumIntType>(VK_FILTER_LINEAR); }
        else if (std::strncmp(nodeVal, "cubic_img", 9) == 0) { e |= static_cast<enumIntType>(VK_FILTER_CUBIC_IMG); }
        else if (std::strncmp(nodeVal, "cubic_ext", 9) == 0) { e |= static_cast<enumIntType>(VK_FILTER_CUBIC_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FILTER_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFilter>(e);
}


static inline ::VkSamplerAddressMode hu::val<::VkSamplerAddressMode>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerAddressMode>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "repeat", 6) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_REPEAT); }
        else if (std::strncmp(nodeVal, "mirrored_repeat", 15) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_MIRRORED_REPEAT); }
        else if (std::strncmp(nodeVal, "clamp_to_edge", 13) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_EDGE); }
        else if (std::strncmp(nodeVal, "clamp_to_border", 15) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER); }
        else if (std::strncmp(nodeVal, "mirror_clamp_to_edge", 20) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE); }
        else if (std::strncmp(nodeVal, "mirror_clamp_to_edge_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_MIRROR_CLAMP_TO_EDGE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_ADDRESS_MODE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerAddressMode>(e);
}


static inline ::VkSamplerMipmapMode hu::val<::VkSamplerMipmapMode>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerMipmapMode>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "nearest", 7) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_MIPMAP_MODE_NEAREST); }
        else if (std::strncmp(nodeVal, "linear", 6) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_MIPMAP_MODE_LINEAR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_MIPMAP_MODE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerMipmapMode>(e);
}


static inline ::VkDescriptorType hu::val<::VkDescriptorType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDescriptorType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "sampler", 7) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_SAMPLER); }
        else if (std::strncmp(nodeVal, "combined_image_sampler", 22) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER); }
        else if (std::strncmp(nodeVal, "sampled_image", 13) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE); }
        else if (std::strncmp(nodeVal, "storage_image", 13) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_STORAGE_IMAGE); }
        else if (std::strncmp(nodeVal, "uniform_texel_buffer", 20) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER); }
        else if (std::strncmp(nodeVal, "storage_texel_buffer", 20) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER); }
        else if (std::strncmp(nodeVal, "uniform_buffer", 14) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER); }
        else if (std::strncmp(nodeVal, "storage_buffer", 14) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER); }
        else if (std::strncmp(nodeVal, "uniform_buffer_dynamic", 22) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC); }
        else if (std::strncmp(nodeVal, "storage_buffer_dynamic", 22) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC); }
        else if (std::strncmp(nodeVal, "input_attachment", 16) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT); }
        else if (std::strncmp(nodeVal, "inline_uniform_block_ext", 24) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_INLINE_UNIFORM_BLOCK_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_ACCELERATION_STRUCTURE_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDescriptorType>(e);
}


static inline ::VkAttachmentLoadOp hu::val<::VkAttachmentLoadOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAttachmentLoadOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "load", 4) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_LOAD_OP_LOAD); }
        else if (std::strncmp(nodeVal, "clear", 5) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_LOAD_OP_CLEAR); }
        else if (std::strncmp(nodeVal, "dont_care", 9) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_LOAD_OP_DONT_CARE); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_LOAD_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAttachmentLoadOp>(e);
}


static inline ::VkAttachmentStoreOp hu::val<::VkAttachmentStoreOp>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAttachmentStoreOp>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "store", 5) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_STORE_OP_STORE); }
        else if (std::strncmp(nodeVal, "dont_care", 9) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_STORE_OP_DONT_CARE); }
        else if (std::strncmp(nodeVal, "none_qcom", 9) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_STORE_OP_NONE_QCOM); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_STORE_OP_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAttachmentStoreOp>(e);
}


static inline ::VkPipelineBindPoint hu::val<::VkPipelineBindPoint>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineBindPoint>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "graphics", 8) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_BIND_POINT_GRAPHICS); }
        else if (std::strncmp(nodeVal, "compute", 7) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_BIND_POINT_COMPUTE); }
        else if (std::strncmp(nodeVal, "ray_tracing_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_BIND_POINT_RAY_TRACING_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_nv", 14) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_BIND_POINT_RAY_TRACING_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_BIND_POINT_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineBindPoint>(e);
}


static inline ::VkCommandBufferLevel hu::val<::VkCommandBufferLevel>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCommandBufferLevel>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "primary", 7) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_LEVEL_PRIMARY); }
        else if (std::strncmp(nodeVal, "secondary", 9) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_LEVEL_SECONDARY); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_LEVEL_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCommandBufferLevel>(e);
}


static inline ::VkIndexType hu::val<::VkIndexType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkIndexType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "uint16", 6) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_UINT16); }
        else if (std::strncmp(nodeVal, "uint32", 6) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_UINT32); }
        else if (std::strncmp(nodeVal, "none_khr", 8) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_NONE_KHR); }
        else if (std::strncmp(nodeVal, "uint8_ext", 9) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_UINT8_EXT); }
        else if (std::strncmp(nodeVal, "none_nv", 7) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_NONE_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_INDEX_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkIndexType>(e);
}


static inline ::VkSubpassContents hu::val<::VkSubpassContents>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSubpassContents>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "inline", 6) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_CONTENTS_INLINE); }
        else if (std::strncmp(nodeVal, "secondary_command_buffers", 25) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_CONTENTS_SECONDARY_COMMAND_BUFFERS); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_CONTENTS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSubpassContents>(e);
}


static inline ::VkAccessFlagBits hu::val<::VkAccessFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccessFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "indirect_command_read_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_INDIRECT_COMMAND_READ_BIT); }
        else if (std::strncmp(nodeVal, "index_read_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_INDEX_READ_BIT); }
        else if (std::strncmp(nodeVal, "vertex_attribute_read_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_VERTEX_ATTRIBUTE_READ_BIT); }
        else if (std::strncmp(nodeVal, "uniform_read_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_UNIFORM_READ_BIT); }
        else if (std::strncmp(nodeVal, "input_attachment_read_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_INPUT_ATTACHMENT_READ_BIT); }
        else if (std::strncmp(nodeVal, "shader_read_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_SHADER_READ_BIT); }
        else if (std::strncmp(nodeVal, "shader_write_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_SHADER_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_read_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_COLOR_ATTACHMENT_READ_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_write_bit", 26) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "depth_stencil_attachment_read_bit", 33) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_READ_BIT); }
        else if (std::strncmp(nodeVal, "depth_stencil_attachment_write_bit", 34) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_DEPTH_STENCIL_ATTACHMENT_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "transfer_read_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_TRANSFER_READ_BIT); }
        else if (std::strncmp(nodeVal, "transfer_write_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_TRANSFER_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "host_read_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_HOST_READ_BIT); }
        else if (std::strncmp(nodeVal, "host_write_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_HOST_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "memory_read_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_MEMORY_READ_BIT); }
        else if (std::strncmp(nodeVal, "memory_write_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_MEMORY_WRITE_BIT); }
        else if (std::strncmp(nodeVal, "transform_feedback_write_bit_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_TRANSFORM_FEEDBACK_WRITE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "transform_feedback_counter_read_bit_ext", 39) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_READ_BIT_EXT); }
        else if (std::strncmp(nodeVal, "transform_feedback_counter_write_bit_ext", 40) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_TRANSFORM_FEEDBACK_COUNTER_WRITE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "conditional_rendering_read_bit_ext", 34) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_CONDITIONAL_RENDERING_READ_BIT_EXT); }
        else if (std::strncmp(nodeVal, "color_attachment_read_noncoherent_bit_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_COLOR_ATTACHMENT_READ_NONCOHERENT_BIT_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_read_bit_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_write_bit_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "shading_rate_image_read_bit_nv", 30) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_SHADING_RATE_IMAGE_READ_BIT_NV); }
        else if (std::strncmp(nodeVal, "fragment_density_map_read_bit_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_FRAGMENT_DENSITY_MAP_READ_BIT_EXT); }
        else if (std::strncmp(nodeVal, "command_preprocess_read_bit_nv", 30) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_COMMAND_PREPROCESS_READ_BIT_NV); }
        else if (std::strncmp(nodeVal, "command_preprocess_write_bit_nv", 31) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_COMMAND_PREPROCESS_WRITE_BIT_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_read_bit_nv", 34) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_ACCELERATION_STRUCTURE_READ_BIT_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_write_bit_nv", 35) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_ACCELERATION_STRUCTURE_WRITE_BIT_NV); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_read_bit_khr", 45) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_FRAGMENT_SHADING_RATE_ATTACHMENT_READ_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_ACCESS_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccessFlagBits>(e);
}


static inline ::VkImageAspectFlagBits hu::val<::VkImageAspectFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageAspectFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "color_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_COLOR_BIT); }
        else if (std::strncmp(nodeVal, "depth_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_DEPTH_BIT); }
        else if (std::strncmp(nodeVal, "stencil_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_STENCIL_BIT); }
        else if (std::strncmp(nodeVal, "metadata_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_METADATA_BIT); }
        else if (std::strncmp(nodeVal, "plane_0_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_0_BIT); }
        else if (std::strncmp(nodeVal, "plane_1_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_1_BIT); }
        else if (std::strncmp(nodeVal, "plane_2_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_2_BIT); }
        else if (std::strncmp(nodeVal, "memory_plane_0_bit_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_MEMORY_PLANE_0_BIT_EXT); }
        else if (std::strncmp(nodeVal, "memory_plane_1_bit_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_MEMORY_PLANE_1_BIT_EXT); }
        else if (std::strncmp(nodeVal, "memory_plane_2_bit_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_MEMORY_PLANE_2_BIT_EXT); }
        else if (std::strncmp(nodeVal, "memory_plane_3_bit_ext", 22) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_MEMORY_PLANE_3_BIT_EXT); }
        else if (std::strncmp(nodeVal, "plane_0_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_0_BIT_KHR); }
        else if (std::strncmp(nodeVal, "plane_1_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_1_BIT_KHR); }
        else if (std::strncmp(nodeVal, "plane_2_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_PLANE_2_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_ASPECT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageAspectFlagBits>(e);
}


static inline ::VkFormatFeatureFlagBits hu::val<::VkFormatFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFormatFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "sampled_image_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_BIT); }
        else if (std::strncmp(nodeVal, "storage_image_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_STORAGE_IMAGE_BIT); }
        else if (std::strncmp(nodeVal, "storage_image_atomic_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_STORAGE_IMAGE_ATOMIC_BIT); }
        else if (std::strncmp(nodeVal, "uniform_texel_buffer_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_UNIFORM_TEXEL_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "storage_texel_buffer_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "storage_texel_buffer_atomic_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_STORAGE_TEXEL_BUFFER_ATOMIC_BIT); }
        else if (std::strncmp(nodeVal, "vertex_buffer_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_VERTEX_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_blend_bit", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_COLOR_ATTACHMENT_BLEND_BIT); }
        else if (std::strncmp(nodeVal, "depth_stencil_attachment_bit", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "blit_src_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_BLIT_SRC_BIT); }
        else if (std::strncmp(nodeVal, "blit_dst_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_BLIT_DST_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_filter_linear_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_LINEAR_BIT); }
        else if (std::strncmp(nodeVal, "transfer_src_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_TRANSFER_SRC_BIT); }
        else if (std::strncmp(nodeVal, "transfer_dst_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_TRANSFER_DST_BIT); }
        else if (std::strncmp(nodeVal, "midpoint_chroma_samples_bit", 27) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_linear_filter_bit", 48) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_separate_reconstruction_filter_bit", 65) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_bit", 65) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_forceable_bit", 75) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT); }
        else if (std::strncmp(nodeVal, "disjoint_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_DISJOINT_BIT); }
        else if (std::strncmp(nodeVal, "cosited_chroma_samples_bit", 26) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_filter_minmax_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT); }
        else if (std::strncmp(nodeVal, "sampled_image_filter_cubic_bit_img", 34) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_IMG); }
        else if (std::strncmp(nodeVal, "acceleration_structure_vertex_buffer_bit_khr", 44) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_ACCELERATION_STRUCTURE_VERTEX_BUFFER_BIT_KHR); }
        else if (std::strncmp(nodeVal, "fragment_density_map_bit_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_FRAGMENT_DENSITY_MAP_BIT_EXT); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_bit_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "transfer_src_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_TRANSFER_SRC_BIT_KHR); }
        else if (std::strncmp(nodeVal, "transfer_dst_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_TRANSFER_DST_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_filter_minmax_bit_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_MINMAX_BIT_EXT); }
        else if (std::strncmp(nodeVal, "midpoint_chroma_samples_bit_khr", 31) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_MIDPOINT_CHROMA_SAMPLES_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_linear_filter_bit_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_LINEAR_FILTER_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_separate_reconstruction_filter_bit_khr", 69) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_SEPARATE_RECONSTRUCTION_FILTER_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_bit_khr", 69) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_ycbcr_conversion_chroma_reconstruction_explicit_forceable_bit_khr", 79) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_YCBCR_CONVERSION_CHROMA_RECONSTRUCTION_EXPLICIT_FORCEABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "disjoint_bit_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_DISJOINT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "cosited_chroma_samples_bit_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_COSITED_CHROMA_SAMPLES_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sampled_image_filter_cubic_bit_ext", 34) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_SAMPLED_IMAGE_FILTER_CUBIC_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_FORMAT_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFormatFeatureFlagBits>(e);
}


static inline ::VkImageCreateFlagBits hu::val<::VkImageCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "sparse_binding_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SPARSE_BINDING_BIT); }
        else if (std::strncmp(nodeVal, "sparse_residency_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SPARSE_RESIDENCY_BIT); }
        else if (std::strncmp(nodeVal, "sparse_aliased_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SPARSE_ALIASED_BIT); }
        else if (std::strncmp(nodeVal, "mutable_format_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_MUTABLE_FORMAT_BIT); }
        else if (std::strncmp(nodeVal, "cube_compatible_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_CUBE_COMPATIBLE_BIT); }
        else if (std::strncmp(nodeVal, "alias_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_ALIAS_BIT); }
        else if (std::strncmp(nodeVal, "split_instance_bind_regions_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT); }
        else if (std::strncmp(nodeVal, "2d_array_compatible_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT); }
        else if (std::strncmp(nodeVal, "block_texel_view_compatible_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT); }
        else if (std::strncmp(nodeVal, "extended_usage_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_EXTENDED_USAGE_BIT); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "disjoint_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_DISJOINT_BIT); }
        else if (std::strncmp(nodeVal, "corner_sampled_bit_nv", 21) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_CORNER_SAMPLED_BIT_NV); }
        else if (std::strncmp(nodeVal, "sample_locations_compatible_depth_bit_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SAMPLE_LOCATIONS_COMPATIBLE_DEPTH_BIT_EXT); }
        else if (std::strncmp(nodeVal, "subsampled_bit_ext", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SUBSAMPLED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "split_instance_bind_regions_bit_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "2d_array_compatible_bit_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_2D_ARRAY_COMPATIBLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "block_texel_view_compatible_bit_khr", 35) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_BLOCK_TEXEL_VIEW_COMPATIBLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "extended_usage_bit_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_EXTENDED_USAGE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "disjoint_bit_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_DISJOINT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "alias_bit_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_ALIAS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageCreateFlagBits>(e);
}


static inline ::VkSampleCountFlagBits hu::val<::VkSampleCountFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSampleCountFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "1_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_1_BIT); }
        else if (std::strncmp(nodeVal, "2_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_2_BIT); }
        else if (std::strncmp(nodeVal, "4_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_4_BIT); }
        else if (std::strncmp(nodeVal, "8_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_8_BIT); }
        else if (std::strncmp(nodeVal, "16_bit", 6) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_16_BIT); }
        else if (std::strncmp(nodeVal, "32_bit", 6) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_32_BIT); }
        else if (std::strncmp(nodeVal, "64_bit", 6) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_64_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SAMPLE_COUNT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSampleCountFlagBits>(e);
}


static inline ::VkImageUsageFlagBits hu::val<::VkImageUsageFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageUsageFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "transfer_src_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_TRANSFER_SRC_BIT); }
        else if (std::strncmp(nodeVal, "transfer_dst_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_TRANSFER_DST_BIT); }
        else if (std::strncmp(nodeVal, "sampled_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_SAMPLED_BIT); }
        else if (std::strncmp(nodeVal, "storage_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_STORAGE_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "depth_stencil_attachment_bit", 28) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "transient_attachment_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "input_attachment_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT); }
        else if (std::strncmp(nodeVal, "shading_rate_image_bit_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_SHADING_RATE_IMAGE_BIT_NV); }
        else if (std::strncmp(nodeVal, "fragment_density_map_bit_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_FRAGMENT_DENSITY_MAP_BIT_EXT); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_bit_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_USAGE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageUsageFlagBits>(e);
}


static inline ::VkMemoryHeapFlagBits hu::val<::VkMemoryHeapFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkMemoryHeapFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device_local_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_HEAP_DEVICE_LOCAL_BIT); }
        else if (std::strncmp(nodeVal, "multi_instance_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_HEAP_MULTI_INSTANCE_BIT); }
        else if (std::strncmp(nodeVal, "multi_instance_bit_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_HEAP_MULTI_INSTANCE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_HEAP_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkMemoryHeapFlagBits>(e);
}


static inline ::VkMemoryPropertyFlagBits hu::val<::VkMemoryPropertyFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkMemoryPropertyFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device_local_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT); }
        else if (std::strncmp(nodeVal, "host_visible_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT); }
        else if (std::strncmp(nodeVal, "host_coherent_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_HOST_COHERENT_BIT); }
        else if (std::strncmp(nodeVal, "host_cached_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_HOST_CACHED_BIT); }
        else if (std::strncmp(nodeVal, "lazily_allocated_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_LAZILY_ALLOCATED_BIT); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "device_coherent_bit_amd", 23) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_DEVICE_COHERENT_BIT_AMD); }
        else if (std::strncmp(nodeVal, "device_uncached_bit_amd", 23) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_DEVICE_UNCACHED_BIT_AMD); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_PROPERTY_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkMemoryPropertyFlagBits>(e);
}


static inline ::VkQueueFlagBits hu::val<::VkQueueFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueueFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "graphics_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GRAPHICS_BIT); }
        else if (std::strncmp(nodeVal, "compute_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_COMPUTE_BIT); }
        else if (std::strncmp(nodeVal, "transfer_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_TRANSFER_BIT); }
        else if (std::strncmp(nodeVal, "sparse_binding_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_SPARSE_BINDING_BIT); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueueFlagBits>(e);
}


static inline ::VkDeviceQueueCreateFlagBits hu::val<::VkDeviceQueueCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDeviceQueueCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_QUEUE_CREATE_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_QUEUE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDeviceQueueCreateFlagBits>(e);
}


static inline ::VkPipelineStageFlagBits hu::val<::VkPipelineStageFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineStageFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "top_of_pipe_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT); }
        else if (std::strncmp(nodeVal, "draw_indirect_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_DRAW_INDIRECT_BIT); }
        else if (std::strncmp(nodeVal, "vertex_input_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_VERTEX_INPUT_BIT); }
        else if (std::strncmp(nodeVal, "vertex_shader_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_VERTEX_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_control_shader_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TESSELLATION_CONTROL_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_evaluation_shader_bit", 34) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TESSELLATION_EVALUATION_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "geometry_shader_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_GEOMETRY_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "fragment_shader_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "early_fragment_tests_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_EARLY_FRAGMENT_TESTS_BIT); }
        else if (std::strncmp(nodeVal, "late_fragment_tests_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_LATE_FRAGMENT_TESTS_BIT); }
        else if (std::strncmp(nodeVal, "color_attachment_output_bit", 27) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT); }
        else if (std::strncmp(nodeVal, "compute_shader_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_COMPUTE_SHADER_BIT); }
        else if (std::strncmp(nodeVal, "transfer_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TRANSFER_BIT); }
        else if (std::strncmp(nodeVal, "bottom_of_pipe_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT); }
        else if (std::strncmp(nodeVal, "host_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_HOST_BIT); }
        else if (std::strncmp(nodeVal, "all_graphics_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_ALL_GRAPHICS_BIT); }
        else if (std::strncmp(nodeVal, "all_commands_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_ALL_COMMANDS_BIT); }
        else if (std::strncmp(nodeVal, "transform_feedback_bit_ext", 26) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TRANSFORM_FEEDBACK_BIT_EXT); }
        else if (std::strncmp(nodeVal, "conditional_rendering_bit_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_CONDITIONAL_RENDERING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_build_bit_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_shader_bit_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_KHR); }
        else if (std::strncmp(nodeVal, "shading_rate_image_bit_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_SHADING_RATE_IMAGE_BIT_NV); }
        else if (std::strncmp(nodeVal, "task_shader_bit_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_TASK_SHADER_BIT_NV); }
        else if (std::strncmp(nodeVal, "mesh_shader_bit_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_MESH_SHADER_BIT_NV); }
        else if (std::strncmp(nodeVal, "fragment_density_process_bit_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_FRAGMENT_DENSITY_PROCESS_BIT_EXT); }
        else if (std::strncmp(nodeVal, "command_preprocess_bit_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_COMMAND_PREPROCESS_BIT_NV); }
        else if (std::strncmp(nodeVal, "ray_tracing_shader_bit_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_RAY_TRACING_SHADER_BIT_NV); }
        else if (std::strncmp(nodeVal, "acceleration_structure_build_bit_nv", 35) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_ACCELERATION_STRUCTURE_BUILD_BIT_NV); }
        else if (std::strncmp(nodeVal, "fragment_shading_rate_attachment_bit_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_FRAGMENT_SHADING_RATE_ATTACHMENT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_STAGE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineStageFlagBits>(e);
}


static inline ::VkSparseMemoryBindFlagBits hu::val<::VkSparseMemoryBindFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSparseMemoryBindFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "metadata_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_MEMORY_BIND_METADATA_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_MEMORY_BIND_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSparseMemoryBindFlagBits>(e);
}


static inline ::VkSparseImageFormatFlagBits hu::val<::VkSparseImageFormatFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSparseImageFormatFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "single_miptail_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_IMAGE_FORMAT_SINGLE_MIPTAIL_BIT); }
        else if (std::strncmp(nodeVal, "aligned_mip_size_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_IMAGE_FORMAT_ALIGNED_MIP_SIZE_BIT); }
        else if (std::strncmp(nodeVal, "nonstandard_block_size_bit", 26) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_IMAGE_FORMAT_NONSTANDARD_BLOCK_SIZE_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SPARSE_IMAGE_FORMAT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSparseImageFormatFlagBits>(e);
}


static inline ::VkFenceCreateFlagBits hu::val<::VkFenceCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFenceCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "signaled_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_FENCE_CREATE_SIGNALED_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_FENCE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFenceCreateFlagBits>(e);
}


static inline ::VkQueryPipelineStatisticFlagBits hu::val<::VkQueryPipelineStatisticFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueryPipelineStatisticFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "input_assembly_vertices_bit", 27) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_VERTICES_BIT); }
        else if (std::strncmp(nodeVal, "input_assembly_primitives_bit", 29) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_INPUT_ASSEMBLY_PRIMITIVES_BIT); }
        else if (std::strncmp(nodeVal, "vertex_shader_invocations_bit", 29) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_VERTEX_SHADER_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "geometry_shader_invocations_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "geometry_shader_primitives_bit", 30) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_GEOMETRY_SHADER_PRIMITIVES_BIT); }
        else if (std::strncmp(nodeVal, "clipping_invocations_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_CLIPPING_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "clipping_primitives_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_CLIPPING_PRIMITIVES_BIT); }
        else if (std::strncmp(nodeVal, "fragment_shader_invocations_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_FRAGMENT_SHADER_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_control_shader_patches_bit", 39) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_CONTROL_SHADER_PATCHES_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_evaluation_shader_invocations_bit", 46) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_TESSELLATION_EVALUATION_SHADER_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "compute_shader_invocations_bit", 30) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_COMPUTE_SHADER_INVOCATIONS_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_QUERY_PIPELINE_STATISTIC_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueryPipelineStatisticFlagBits>(e);
}


static inline ::VkQueryResultFlagBits hu::val<::VkQueryResultFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueryResultFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "64_bit", 6) == 0) { e |= static_cast<enumIntType>(VK_QUERY_RESULT_64_BIT); }
        else if (std::strncmp(nodeVal, "wait_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_QUERY_RESULT_WAIT_BIT); }
        else if (std::strncmp(nodeVal, "with_availability_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_QUERY_RESULT_WITH_AVAILABILITY_BIT); }
        else if (std::strncmp(nodeVal, "partial_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_QUERY_RESULT_PARTIAL_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_QUERY_RESULT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueryResultFlagBits>(e);
}


static inline ::VkBufferCreateFlagBits hu::val<::VkBufferCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBufferCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "sparse_binding_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_SPARSE_BINDING_BIT); }
        else if (std::strncmp(nodeVal, "sparse_residency_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_SPARSE_RESIDENCY_BIT); }
        else if (std::strncmp(nodeVal, "sparse_aliased_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_SPARSE_ALIASED_BIT); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "device_address_capture_replay_bit", 33) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT); }
        else if (std::strncmp(nodeVal, "device_address_capture_replay_bit_ext", 37) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_EXT); }
        else if (std::strncmp(nodeVal, "device_address_capture_replay_bit_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBufferCreateFlagBits>(e);
}


static inline ::VkBufferUsageFlagBits hu::val<::VkBufferUsageFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBufferUsageFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "transfer_src_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_TRANSFER_SRC_BIT); }
        else if (std::strncmp(nodeVal, "transfer_dst_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_TRANSFER_DST_BIT); }
        else if (std::strncmp(nodeVal, "uniform_texel_buffer_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_UNIFORM_TEXEL_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "storage_texel_buffer_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_STORAGE_TEXEL_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "uniform_buffer_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "storage_buffer_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_STORAGE_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "index_buffer_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_INDEX_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "vertex_buffer_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_VERTEX_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "indirect_buffer_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_INDIRECT_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "shader_device_address_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT); }
        else if (std::strncmp(nodeVal, "transform_feedback_buffer_bit_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_BUFFER_BIT_EXT); }
        else if (std::strncmp(nodeVal, "transform_feedback_counter_buffer_bit_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_TRANSFORM_FEEDBACK_COUNTER_BUFFER_BIT_EXT); }
        else if (std::strncmp(nodeVal, "conditional_rendering_bit_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_CONDITIONAL_RENDERING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_build_input_read_only_bit_khr", 52) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_BUILD_INPUT_READ_ONLY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "acceleration_structure_storage_bit_khr", 38) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_ACCELERATION_STRUCTURE_STORAGE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "shader_binding_table_bit_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_SHADER_BINDING_TABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_bit_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_RAY_TRACING_BIT_NV); }
        else if (std::strncmp(nodeVal, "shader_device_address_bit_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_EXT); }
        else if (std::strncmp(nodeVal, "shader_device_address_bit_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_SHADER_DEVICE_ADDRESS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_BUFFER_USAGE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBufferUsageFlagBits>(e);
}


static inline ::VkImageViewCreateFlagBits hu::val<::VkImageViewCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkImageViewCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "fragment_density_map_dynamic_bit_ext", 36) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DYNAMIC_BIT_EXT); }
        else if (std::strncmp(nodeVal, "fragment_density_map_deferred_bit_ext", 37) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_CREATE_FRAGMENT_DENSITY_MAP_DEFERRED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_IMAGE_VIEW_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkImageViewCreateFlagBits>(e);
}


static inline ::VkShaderModuleCreateFlagBits hu::val<::VkShaderModuleCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderModuleCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vk_shader_module_create_flag_bits_max_enum", 42) == 0) { e |= static_cast<enumIntType>(VK_SHADER_MODULE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderModuleCreateFlagBits>(e);
}


static inline ::VkPipelineCacheCreateFlagBits hu::val<::VkPipelineCacheCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineCacheCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "externally_synchronized_bit_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CACHE_CREATE_EXTERNALLY_SYNCHRONIZED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CACHE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineCacheCreateFlagBits>(e);
}


static inline ::VkColorComponentFlagBits hu::val<::VkColorComponentFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkColorComponentFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "r_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_COLOR_COMPONENT_R_BIT); }
        else if (std::strncmp(nodeVal, "g_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_COLOR_COMPONENT_G_BIT); }
        else if (std::strncmp(nodeVal, "b_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_COLOR_COMPONENT_B_BIT); }
        else if (std::strncmp(nodeVal, "a_bit", 5) == 0) { e |= static_cast<enumIntType>(VK_COLOR_COMPONENT_A_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COLOR_COMPONENT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkColorComponentFlagBits>(e);
}


static inline ::VkPipelineCreateFlagBits hu::val<::VkPipelineCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "disable_optimization_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DISABLE_OPTIMIZATION_BIT); }
        else if (std::strncmp(nodeVal, "allow_derivatives_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_ALLOW_DERIVATIVES_BIT); }
        else if (std::strncmp(nodeVal, "derivative_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DERIVATIVE_BIT); }
        else if (std::strncmp(nodeVal, "view_index_from_device_index_bit", 32) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT); }
        else if (std::strncmp(nodeVal, "dispatch_base_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DISPATCH_BASE_BIT); }
        else if (std::strncmp(nodeVal, "ray_tracing_no_null_any_hit_shaders_bit_khr", 43) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_ANY_HIT_SHADERS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_no_null_closest_hit_shaders_bit_khr", 47) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_CLOSEST_HIT_SHADERS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_no_null_miss_shaders_bit_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_MISS_SHADERS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_no_null_intersection_shaders_bit_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_NO_NULL_INTERSECTION_SHADERS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_skip_triangles_bit_khr", 34) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_SKIP_TRIANGLES_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_skip_aabbs_bit_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_SKIP_AABBS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "ray_tracing_shader_group_handle_capture_replay_bit_khr", 54) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_RAY_TRACING_SHADER_GROUP_HANDLE_CAPTURE_REPLAY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "defer_compile_bit_nv", 20) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DEFER_COMPILE_BIT_NV); }
        else if (std::strncmp(nodeVal, "capture_statistics_bit_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_CAPTURE_STATISTICS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "capture_internal_representations_bit_khr", 40) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_CAPTURE_INTERNAL_REPRESENTATIONS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "indirect_bindable_bit_nv", 24) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_INDIRECT_BINDABLE_BIT_NV); }
        else if (std::strncmp(nodeVal, "library_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_LIBRARY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "fail_on_pipeline_compile_required_bit_ext", 41) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_FAIL_ON_PIPELINE_COMPILE_REQUIRED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "early_return_on_failure_bit_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_EARLY_RETURN_ON_FAILURE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "dispatch_base", 13) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DISPATCH_BASE); }
        else if (std::strncmp(nodeVal, "view_index_from_device_index_bit_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_VIEW_INDEX_FROM_DEVICE_INDEX_BIT_KHR); }
        else if (std::strncmp(nodeVal, "dispatch_base_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_DISPATCH_BASE_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineCreateFlagBits>(e);
}


static inline ::VkPipelineShaderStageCreateFlagBits hu::val<::VkPipelineShaderStageCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineShaderStageCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "allow_varying_subgroup_size_bit_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_SHADER_STAGE_CREATE_ALLOW_VARYING_SUBGROUP_SIZE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "require_full_subgroups_bit_ext", 30) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_SHADER_STAGE_CREATE_REQUIRE_FULL_SUBGROUPS_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_SHADER_STAGE_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineShaderStageCreateFlagBits>(e);
}


static inline ::VkShaderStageFlagBits hu::val<::VkShaderStageFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderStageFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vertex_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_VERTEX_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_control_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_TESSELLATION_CONTROL_BIT); }
        else if (std::strncmp(nodeVal, "tessellation_evaluation_bit", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_TESSELLATION_EVALUATION_BIT); }
        else if (std::strncmp(nodeVal, "geometry_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_GEOMETRY_BIT); }
        else if (std::strncmp(nodeVal, "fragment_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_FRAGMENT_BIT); }
        else if (std::strncmp(nodeVal, "compute_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_COMPUTE_BIT); }
        else if (std::strncmp(nodeVal, "all_graphics", 12) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_ALL_GRAPHICS); }
        else if (std::strncmp(nodeVal, "all", 3) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_ALL); }
        else if (std::strncmp(nodeVal, "raygen_bit_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_RAYGEN_BIT_KHR); }
        else if (std::strncmp(nodeVal, "any_hit_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_ANY_HIT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "closest_hit_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_CLOSEST_HIT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "miss_bit_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_MISS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "intersection_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_INTERSECTION_BIT_KHR); }
        else if (std::strncmp(nodeVal, "callable_bit_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_CALLABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "task_bit_nv", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_TASK_BIT_NV); }
        else if (std::strncmp(nodeVal, "mesh_bit_nv", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_MESH_BIT_NV); }
        else if (std::strncmp(nodeVal, "raygen_bit_nv", 13) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_RAYGEN_BIT_NV); }
        else if (std::strncmp(nodeVal, "any_hit_bit_nv", 14) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_ANY_HIT_BIT_NV); }
        else if (std::strncmp(nodeVal, "closest_hit_bit_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_CLOSEST_HIT_BIT_NV); }
        else if (std::strncmp(nodeVal, "miss_bit_nv", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_MISS_BIT_NV); }
        else if (std::strncmp(nodeVal, "intersection_bit_nv", 19) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_INTERSECTION_BIT_NV); }
        else if (std::strncmp(nodeVal, "callable_bit_nv", 15) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_CALLABLE_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SHADER_STAGE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderStageFlagBits>(e);
}


static inline ::VkCullModeFlagBits hu::val<::VkCullModeFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCullModeFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "none", 4) == 0) { e |= static_cast<enumIntType>(VK_CULL_MODE_NONE); }
        else if (std::strncmp(nodeVal, "front_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_CULL_MODE_FRONT_BIT); }
        else if (std::strncmp(nodeVal, "back_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_CULL_MODE_BACK_BIT); }
        else if (std::strncmp(nodeVal, "front_and_back", 14) == 0) { e |= static_cast<enumIntType>(VK_CULL_MODE_FRONT_AND_BACK); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_CULL_MODE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCullModeFlagBits>(e);
}


static inline ::VkSamplerCreateFlagBits hu::val<::VkSamplerCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "subsampled_bit_ext", 18) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_CREATE_SUBSAMPLED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "subsampled_coarse_reconstruction_bit_ext", 40) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_CREATE_SUBSAMPLED_COARSE_RECONSTRUCTION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerCreateFlagBits>(e);
}


static inline ::VkDescriptorPoolCreateFlagBits hu::val<::VkDescriptorPoolCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDescriptorPoolCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "free_descriptor_set_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT); }
        else if (std::strncmp(nodeVal, "update_after_bind_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT); }
        else if (std::strncmp(nodeVal, "update_after_bind_bit_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_POOL_CREATE_UPDATE_AFTER_BIND_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_POOL_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDescriptorPoolCreateFlagBits>(e);
}


static inline ::VkDescriptorSetLayoutCreateFlagBits hu::val<::VkDescriptorSetLayoutCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDescriptorSetLayoutCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "update_after_bind_pool_bit", 26) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT); }
        else if (std::strncmp(nodeVal, "push_descriptor_bit_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_SET_LAYOUT_CREATE_PUSH_DESCRIPTOR_BIT_KHR); }
        else if (std::strncmp(nodeVal, "update_after_bind_pool_bit_ext", 30) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_SET_LAYOUT_CREATE_UPDATE_AFTER_BIND_POOL_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_SET_LAYOUT_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDescriptorSetLayoutCreateFlagBits>(e);
}


static inline ::VkAttachmentDescriptionFlagBits hu::val<::VkAttachmentDescriptionFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAttachmentDescriptionFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "may_alias_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_DESCRIPTION_MAY_ALIAS_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_ATTACHMENT_DESCRIPTION_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAttachmentDescriptionFlagBits>(e);
}


static inline ::VkDependencyFlagBits hu::val<::VkDependencyFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDependencyFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "by_region_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_BY_REGION_BIT); }
        else if (std::strncmp(nodeVal, "device_group_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_DEVICE_GROUP_BIT); }
        else if (std::strncmp(nodeVal, "view_local_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_VIEW_LOCAL_BIT); }
        else if (std::strncmp(nodeVal, "view_local_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_VIEW_LOCAL_BIT_KHR); }
        else if (std::strncmp(nodeVal, "device_group_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_DEVICE_GROUP_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEPENDENCY_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDependencyFlagBits>(e);
}


static inline ::VkFramebufferCreateFlagBits hu::val<::VkFramebufferCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFramebufferCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "imageless_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT); }
        else if (std::strncmp(nodeVal, "imageless_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_FRAMEBUFFER_CREATE_IMAGELESS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_FRAMEBUFFER_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFramebufferCreateFlagBits>(e);
}


static inline ::VkRenderPassCreateFlagBits hu::val<::VkRenderPassCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkRenderPassCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "transform_bit_qcom", 18) == 0) { e |= static_cast<enumIntType>(VK_RENDER_PASS_CREATE_TRANSFORM_BIT_QCOM); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_RENDER_PASS_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkRenderPassCreateFlagBits>(e);
}


static inline ::VkSubpassDescriptionFlagBits hu::val<::VkSubpassDescriptionFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSubpassDescriptionFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "per_view_attributes_bit_nvx", 27) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_DESCRIPTION_PER_VIEW_ATTRIBUTES_BIT_NVX); }
        else if (std::strncmp(nodeVal, "per_view_position_x_only_bit_nvx", 32) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_DESCRIPTION_PER_VIEW_POSITION_X_ONLY_BIT_NVX); }
        else if (std::strncmp(nodeVal, "fragment_region_bit_qcom", 24) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_DESCRIPTION_FRAGMENT_REGION_BIT_QCOM); }
        else if (std::strncmp(nodeVal, "shader_resolve_bit_qcom", 23) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_DESCRIPTION_SHADER_RESOLVE_BIT_QCOM); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SUBPASS_DESCRIPTION_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSubpassDescriptionFlagBits>(e);
}


static inline ::VkCommandPoolCreateFlagBits hu::val<::VkCommandPoolCreateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCommandPoolCreateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "transient_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_CREATE_TRANSIENT_BIT); }
        else if (std::strncmp(nodeVal, "reset_command_buffer_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_CREATE_PROTECTED_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_CREATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCommandPoolCreateFlagBits>(e);
}


static inline ::VkCommandPoolResetFlagBits hu::val<::VkCommandPoolResetFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCommandPoolResetFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "release_resources_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_RESET_RELEASE_RESOURCES_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_POOL_RESET_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCommandPoolResetFlagBits>(e);
}


static inline ::VkCommandBufferUsageFlagBits hu::val<::VkCommandBufferUsageFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCommandBufferUsageFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "one_time_submit_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT); }
        else if (std::strncmp(nodeVal, "render_pass_continue_bit", 24) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_USAGE_RENDER_PASS_CONTINUE_BIT); }
        else if (std::strncmp(nodeVal, "simultaneous_use_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_USAGE_SIMULTANEOUS_USE_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_USAGE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCommandBufferUsageFlagBits>(e);
}


static inline ::VkQueryControlFlagBits hu::val<::VkQueryControlFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueryControlFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "precise_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_QUERY_CONTROL_PRECISE_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_QUERY_CONTROL_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueryControlFlagBits>(e);
}


static inline ::VkCommandBufferResetFlagBits hu::val<::VkCommandBufferResetFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCommandBufferResetFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "release_resources_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_RESET_RELEASE_RESOURCES_BIT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COMMAND_BUFFER_RESET_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCommandBufferResetFlagBits>(e);
}


static inline ::VkStencilFaceFlagBits hu::val<::VkStencilFaceFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkStencilFaceFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "face_front_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_FACE_FRONT_BIT); }
        else if (std::strncmp(nodeVal, "face_back_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_FACE_BACK_BIT); }
        else if (std::strncmp(nodeVal, "face_front_and_back", 19) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_FACE_FRONT_AND_BACK); }
        else if (std::strncmp(nodeVal, "front_and_back", 14) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_FRONT_AND_BACK); }
        else if (std::strncmp(nodeVal, "face_flag_bits_max_enum", 23) == 0) { e |= static_cast<enumIntType>(VK_STENCIL_FACE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkStencilFaceFlagBits>(e);
}


static inline ::VkPointClippingBehavior hu::val<::VkPointClippingBehavior>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPointClippingBehavior>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "all_clip_planes", 15) == 0) { e |= static_cast<enumIntType>(VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES); }
        else if (std::strncmp(nodeVal, "user_clip_planes_only", 21) == 0) { e |= static_cast<enumIntType>(VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY); }
        else if (std::strncmp(nodeVal, "all_clip_planes_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_POINT_CLIPPING_BEHAVIOR_ALL_CLIP_PLANES_KHR); }
        else if (std::strncmp(nodeVal, "user_clip_planes_only_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_POINT_CLIPPING_BEHAVIOR_USER_CLIP_PLANES_ONLY_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_POINT_CLIPPING_BEHAVIOR_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPointClippingBehavior>(e);
}


static inline ::VkTessellationDomainOrigin hu::val<::VkTessellationDomainOrigin>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkTessellationDomainOrigin>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "upper_left", 10) == 0) { e |= static_cast<enumIntType>(VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT); }
        else if (std::strncmp(nodeVal, "lower_left", 10) == 0) { e |= static_cast<enumIntType>(VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT); }
        else if (std::strncmp(nodeVal, "upper_left_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_TESSELLATION_DOMAIN_ORIGIN_UPPER_LEFT_KHR); }
        else if (std::strncmp(nodeVal, "lower_left_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_TESSELLATION_DOMAIN_ORIGIN_LOWER_LEFT_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_TESSELLATION_DOMAIN_ORIGIN_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkTessellationDomainOrigin>(e);
}


static inline ::VkSamplerYcbcrModelConversion hu::val<::VkSamplerYcbcrModelConversion>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerYcbcrModelConversion>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "rgb_identity", 12) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY); }
        else if (std::strncmp(nodeVal, "ycbcr_identity", 14) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY); }
        else if (std::strncmp(nodeVal, "ycbcr_709", 9) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709); }
        else if (std::strncmp(nodeVal, "ycbcr_601", 9) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601); }
        else if (std::strncmp(nodeVal, "ycbcr_2020", 10) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020); }
        else if (std::strncmp(nodeVal, "rgb_identity_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_RGB_IDENTITY_KHR); }
        else if (std::strncmp(nodeVal, "ycbcr_identity_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_IDENTITY_KHR); }
        else if (std::strncmp(nodeVal, "ycbcr_709_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_709_KHR); }
        else if (std::strncmp(nodeVal, "ycbcr_601_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_601_KHR); }
        else if (std::strncmp(nodeVal, "ycbcr_2020_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_YCBCR_2020_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_MODEL_CONVERSION_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerYcbcrModelConversion>(e);
}


static inline ::VkSamplerYcbcrRange hu::val<::VkSamplerYcbcrRange>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerYcbcrRange>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "itu_full", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_RANGE_ITU_FULL); }
        else if (std::strncmp(nodeVal, "itu_narrow", 10) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_RANGE_ITU_NARROW); }
        else if (std::strncmp(nodeVal, "itu_full_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_RANGE_ITU_FULL_KHR); }
        else if (std::strncmp(nodeVal, "itu_narrow_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_RANGE_ITU_NARROW_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_YCBCR_RANGE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerYcbcrRange>(e);
}


static inline ::VkChromaLocation hu::val<::VkChromaLocation>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkChromaLocation>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "cosited_even", 12) == 0) { e |= static_cast<enumIntType>(VK_CHROMA_LOCATION_COSITED_EVEN); }
        else if (std::strncmp(nodeVal, "midpoint", 8) == 0) { e |= static_cast<enumIntType>(VK_CHROMA_LOCATION_MIDPOINT); }
        else if (std::strncmp(nodeVal, "cosited_even_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_CHROMA_LOCATION_COSITED_EVEN_KHR); }
        else if (std::strncmp(nodeVal, "midpoint_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_CHROMA_LOCATION_MIDPOINT_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_CHROMA_LOCATION_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkChromaLocation>(e);
}


static inline ::VkDescriptorUpdateTemplateType hu::val<::VkDescriptorUpdateTemplateType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDescriptorUpdateTemplateType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "descriptor_set", 14) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET); }
        else if (std::strncmp(nodeVal, "push_descriptors_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_PUSH_DESCRIPTORS_KHR); }
        else if (std::strncmp(nodeVal, "descriptor_set_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_DESCRIPTOR_SET_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_UPDATE_TEMPLATE_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDescriptorUpdateTemplateType>(e);
}


static inline ::VkSubgroupFeatureFlagBits hu::val<::VkSubgroupFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSubgroupFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "basic_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_BASIC_BIT); }
        else if (std::strncmp(nodeVal, "vote_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_VOTE_BIT); }
        else if (std::strncmp(nodeVal, "arithmetic_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_ARITHMETIC_BIT); }
        else if (std::strncmp(nodeVal, "ballot_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_BALLOT_BIT); }
        else if (std::strncmp(nodeVal, "shuffle_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_SHUFFLE_BIT); }
        else if (std::strncmp(nodeVal, "shuffle_relative_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_SHUFFLE_RELATIVE_BIT); }
        else if (std::strncmp(nodeVal, "clustered_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_CLUSTERED_BIT); }
        else if (std::strncmp(nodeVal, "quad_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_QUAD_BIT); }
        else if (std::strncmp(nodeVal, "partitioned_bit_nv", 18) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_PARTITIONED_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SUBGROUP_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSubgroupFeatureFlagBits>(e);
}


static inline ::VkPeerMemoryFeatureFlagBits hu::val<::VkPeerMemoryFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPeerMemoryFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "copy_src_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT); }
        else if (std::strncmp(nodeVal, "copy_dst_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_COPY_DST_BIT); }
        else if (std::strncmp(nodeVal, "generic_src_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT); }
        else if (std::strncmp(nodeVal, "generic_dst_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT); }
        else if (std::strncmp(nodeVal, "copy_src_bit_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_COPY_SRC_BIT_KHR); }
        else if (std::strncmp(nodeVal, "copy_dst_bit_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_COPY_DST_BIT_KHR); }
        else if (std::strncmp(nodeVal, "generic_src_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_GENERIC_SRC_BIT_KHR); }
        else if (std::strncmp(nodeVal, "generic_dst_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_GENERIC_DST_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PEER_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPeerMemoryFeatureFlagBits>(e);
}


static inline ::VkMemoryAllocateFlagBits hu::val<::VkMemoryAllocateFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkMemoryAllocateFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device_mask_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT); }
        else if (std::strncmp(nodeVal, "device_address_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT); }
        else if (std::strncmp(nodeVal, "device_address_capture_replay_bit", 33) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT); }
        else if (std::strncmp(nodeVal, "device_mask_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_MASK_BIT_KHR); }
        else if (std::strncmp(nodeVal, "device_address_bit_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "device_address_capture_replay_bit_khr", 37) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_ALLOCATE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkMemoryAllocateFlagBits>(e);
}


static inline ::VkExternalMemoryHandleTypeFlagBits hu::val<::VkExternalMemoryHandleTypeFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalMemoryHandleTypeFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_fd_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT); }
        else if (std::strncmp(nodeVal, "d3d11_texture_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT); }
        else if (std::strncmp(nodeVal, "d3d11_texture_kmt_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT); }
        else if (std::strncmp(nodeVal, "d3d12_heap_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT); }
        else if (std::strncmp(nodeVal, "d3d12_resource_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT); }
        else if (std::strncmp(nodeVal, "dma_buf_bit_ext", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_DMA_BUF_BIT_EXT); }
        else if (std::strncmp(nodeVal, "android_hardware_buffer_bit_android", 35) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_ANDROID_HARDWARE_BUFFER_BIT_ANDROID); }
        else if (std::strncmp(nodeVal, "host_allocation_bit_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "host_mapped_foreign_memory_bit_ext", 34) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_MAPPED_FOREIGN_MEMORY_BIT_EXT); }
        else if (std::strncmp(nodeVal, "opaque_fd_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_FD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "d3d11_texture_bit_khr", 21) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "d3d11_texture_kmt_bit_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_TEXTURE_KMT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "d3d12_heap_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_HEAP_BIT_KHR); }
        else if (std::strncmp(nodeVal, "d3d12_resource_bit_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D12_RESOURCE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalMemoryHandleTypeFlagBits>(e);
}


static inline ::VkExternalMemoryFeatureFlagBits hu::val<::VkExternalMemoryFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalMemoryFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "dedicated_only_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT); }
        else if (std::strncmp(nodeVal, "exportable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "importable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "dedicated_only_bit_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "exportable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "importable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalMemoryFeatureFlagBits>(e);
}


static inline ::VkExternalFenceHandleTypeFlagBits hu::val<::VkExternalFenceHandleTypeFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalFenceHandleTypeFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_fd_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT); }
        else if (std::strncmp(nodeVal, "sync_fd_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT); }
        else if (std::strncmp(nodeVal, "opaque_fd_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sync_fd_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_SYNC_FD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalFenceHandleTypeFlagBits>(e);
}


static inline ::VkExternalFenceFeatureFlagBits hu::val<::VkExternalFenceFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalFenceFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "exportable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "importable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "exportable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_FEATURE_EXPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "importable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_FEATURE_IMPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_FENCE_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalFenceFeatureFlagBits>(e);
}


static inline ::VkFenceImportFlagBits hu::val<::VkFenceImportFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFenceImportFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "temporary_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_FENCE_IMPORT_TEMPORARY_BIT); }
        else if (std::strncmp(nodeVal, "temporary_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_FENCE_IMPORT_TEMPORARY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_FENCE_IMPORT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFenceImportFlagBits>(e);
}


static inline ::VkSemaphoreImportFlagBits hu::val<::VkSemaphoreImportFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSemaphoreImportFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "temporary_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_IMPORT_TEMPORARY_BIT); }
        else if (std::strncmp(nodeVal, "temporary_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_IMPORT_TEMPORARY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_IMPORT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSemaphoreImportFlagBits>(e);
}


static inline ::VkExternalSemaphoreHandleTypeFlagBits hu::val<::VkExternalSemaphoreHandleTypeFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalSemaphoreHandleTypeFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_fd_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT); }
        else if (std::strncmp(nodeVal, "d3d12_fence_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT); }
        else if (std::strncmp(nodeVal, "sync_fd_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT); }
        else if (std::strncmp(nodeVal, "d3d11_fence_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D11_FENCE_BIT); }
        else if (std::strncmp(nodeVal, "opaque_fd_bit_khr", 17) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_FD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "d3d12_fence_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_D3D12_FENCE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sync_fd_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_SYNC_FD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_HANDLE_TYPE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalSemaphoreHandleTypeFlagBits>(e);
}


static inline ::VkExternalSemaphoreFeatureFlagBits hu::val<::VkExternalSemaphoreFeatureFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalSemaphoreFeatureFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "exportable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "importable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT); }
        else if (std::strncmp(nodeVal, "exportable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_FEATURE_EXPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "importable_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_FEATURE_IMPORTABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_SEMAPHORE_FEATURE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalSemaphoreFeatureFlagBits>(e);
}


static inline ::VkDriverId hu::val<::VkDriverId>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDriverId>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "amd_proprietary", 15) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_AMD_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "amd_open_source", 15) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_AMD_OPEN_SOURCE); }
        else if (std::strncmp(nodeVal, "mesa_radv", 9) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_MESA_RADV); }
        else if (std::strncmp(nodeVal, "nvidia_proprietary", 18) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_NVIDIA_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "intel_proprietary_windows", 25) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS); }
        else if (std::strncmp(nodeVal, "intel_open_source_mesa", 22) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA); }
        else if (std::strncmp(nodeVal, "imagination_proprietary", 23) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_IMAGINATION_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "qualcomm_proprietary", 20) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_QUALCOMM_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "arm_proprietary", 15) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_ARM_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "google_swiftshader", 18) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_GOOGLE_SWIFTSHADER); }
        else if (std::strncmp(nodeVal, "ggp_proprietary", 15) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_GGP_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "broadcom_proprietary", 20) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_BROADCOM_PROPRIETARY); }
        else if (std::strncmp(nodeVal, "mesa_llvmpipe", 13) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_MESA_LLVMPIPE); }
        else if (std::strncmp(nodeVal, "moltenvk", 8) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_MOLTENVK); }
        else if (std::strncmp(nodeVal, "amd_proprietary_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_AMD_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "amd_open_source_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_AMD_OPEN_SOURCE_KHR); }
        else if (std::strncmp(nodeVal, "mesa_radv_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_MESA_RADV_KHR); }
        else if (std::strncmp(nodeVal, "nvidia_proprietary_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_NVIDIA_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "intel_proprietary_windows_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_INTEL_PROPRIETARY_WINDOWS_KHR); }
        else if (std::strncmp(nodeVal, "intel_open_source_mesa_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_INTEL_OPEN_SOURCE_MESA_KHR); }
        else if (std::strncmp(nodeVal, "imagination_proprietary_khr", 27) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_IMAGINATION_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "qualcomm_proprietary_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_QUALCOMM_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "arm_proprietary_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_ARM_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "google_swiftshader_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_GOOGLE_SWIFTSHADER_KHR); }
        else if (std::strncmp(nodeVal, "ggp_proprietary_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_GGP_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "broadcom_proprietary_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_BROADCOM_PROPRIETARY_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DRIVER_ID_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDriverId>(e);
}


static inline ::VkShaderFloatControlsIndependence hu::val<::VkShaderFloatControlsIndependence>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderFloatControlsIndependence>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "32_bit_only", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY); }
        else if (std::strncmp(nodeVal, "all", 3) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL); }
        else if (std::strncmp(nodeVal, "none", 4) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE); }
        else if (std::strncmp(nodeVal, "32_bit_only_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_32_BIT_ONLY_KHR); }
        else if (std::strncmp(nodeVal, "all_khr", 7) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_ALL_KHR); }
        else if (std::strncmp(nodeVal, "none_khr", 8) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_NONE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SHADER_FLOAT_CONTROLS_INDEPENDENCE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderFloatControlsIndependence>(e);
}


static inline ::VkSamplerReductionMode hu::val<::VkSamplerReductionMode>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSamplerReductionMode>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "weighted_average", 16) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE); }
        else if (std::strncmp(nodeVal, "min", 3) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_MIN); }
        else if (std::strncmp(nodeVal, "max", 3) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_MAX); }
        else if (std::strncmp(nodeVal, "weighted_average_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_WEIGHTED_AVERAGE_EXT); }
        else if (std::strncmp(nodeVal, "min_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_MIN_EXT); }
        else if (std::strncmp(nodeVal, "max_ext", 7) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_MAX_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SAMPLER_REDUCTION_MODE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSamplerReductionMode>(e);
}


static inline ::VkSemaphoreType hu::val<::VkSemaphoreType>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSemaphoreType>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "binary", 6) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_TYPE_BINARY); }
        else if (std::strncmp(nodeVal, "timeline", 8) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_TYPE_TIMELINE); }
        else if (std::strncmp(nodeVal, "binary_khr", 10) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_TYPE_BINARY_KHR); }
        else if (std::strncmp(nodeVal, "timeline_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_TYPE_TIMELINE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_TYPE_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSemaphoreType>(e);
}


static inline ::VkResolveModeFlagBits hu::val<::VkResolveModeFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkResolveModeFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "none", 4) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_NONE); }
        else if (std::strncmp(nodeVal, "sample_zero_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_SAMPLE_ZERO_BIT); }
        else if (std::strncmp(nodeVal, "average_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_AVERAGE_BIT); }
        else if (std::strncmp(nodeVal, "min_bit", 7) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_MIN_BIT); }
        else if (std::strncmp(nodeVal, "max_bit", 7) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_MAX_BIT); }
        else if (std::strncmp(nodeVal, "none_khr", 8) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_NONE_KHR); }
        else if (std::strncmp(nodeVal, "sample_zero_bit_khr", 19) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_SAMPLE_ZERO_BIT_KHR); }
        else if (std::strncmp(nodeVal, "average_bit_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_AVERAGE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "min_bit_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_MIN_BIT_KHR); }
        else if (std::strncmp(nodeVal, "max_bit_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_MAX_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_RESOLVE_MODE_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkResolveModeFlagBits>(e);
}


static inline ::VkDescriptorBindingFlagBits hu::val<::VkDescriptorBindingFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDescriptorBindingFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "update_after_bind_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT); }
        else if (std::strncmp(nodeVal, "update_unused_while_pending_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT); }
        else if (std::strncmp(nodeVal, "partially_bound_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT); }
        else if (std::strncmp(nodeVal, "variable_descriptor_count_bit", 29) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT); }
        else if (std::strncmp(nodeVal, "update_after_bind_bit_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_UPDATE_AFTER_BIND_BIT_EXT); }
        else if (std::strncmp(nodeVal, "update_unused_while_pending_bit_ext", 35) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_UPDATE_UNUSED_WHILE_PENDING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "partially_bound_bit_ext", 23) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_PARTIALLY_BOUND_BIT_EXT); }
        else if (std::strncmp(nodeVal, "variable_descriptor_count_bit_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_VARIABLE_DESCRIPTOR_COUNT_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DESCRIPTOR_BINDING_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDescriptorBindingFlagBits>(e);
}


static inline ::VkSemaphoreWaitFlagBits hu::val<::VkSemaphoreWaitFlagBits>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSemaphoreWaitFlagBits>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "any_bit", 7) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_WAIT_ANY_BIT); }
        else if (std::strncmp(nodeVal, "any_bit_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_WAIT_ANY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SEMAPHORE_WAIT_FLAG_BITS_MAX_ENUM); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSemaphoreWaitFlagBits>(e);
}


static inline ::VkPresentModeKHR hu::val<::VkPresentModeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPresentModeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "immediate", 9) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_IMMEDIATE_KHR); }
        else if (std::strncmp(nodeVal, "mailbox", 7) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_MAILBOX_KHR); }
        else if (std::strncmp(nodeVal, "fifo", 4) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_FIFO_KHR); }
        else if (std::strncmp(nodeVal, "fifo_relaxed", 12) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_FIFO_RELAXED_KHR); }
        else if (std::strncmp(nodeVal, "shared_demand_refresh", 21) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_SHARED_DEMAND_REFRESH_KHR); }
        else if (std::strncmp(nodeVal, "shared_continuous_refresh", 25) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_SHARED_CONTINUOUS_REFRESH_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PRESENT_MODE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPresentModeKHR>(e);
}


static inline ::VkColorSpaceKHR hu::val<::VkColorSpaceKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkColorSpaceKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "color_space_srgb_nonlinear_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_SRGB_NONLINEAR_KHR); }
        else if (std::strncmp(nodeVal, "color_space_display_p3_nonlinear_ext", 36) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DISPLAY_P3_NONLINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_extended_srgb_linear_ext", 36) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_EXTENDED_SRGB_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_display_p3_linear_ext", 33) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DISPLAY_P3_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_dci_p3_nonlinear_ext", 32) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DCI_P3_NONLINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_bt709_linear_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_BT709_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_bt709_nonlinear_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_BT709_NONLINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_bt2020_linear_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_BT2020_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_hdr10_st2084_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_HDR10_ST2084_EXT); }
        else if (std::strncmp(nodeVal, "color_space_dolbyvision_ext", 27) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DOLBYVISION_EXT); }
        else if (std::strncmp(nodeVal, "color_space_hdr10_hlg_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_HDR10_HLG_EXT); }
        else if (std::strncmp(nodeVal, "color_space_adobergb_linear_ext", 31) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_ADOBERGB_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_adobergb_nonlinear_ext", 34) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_ADOBERGB_NONLINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_pass_through_ext", 28) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_PASS_THROUGH_EXT); }
        else if (std::strncmp(nodeVal, "color_space_extended_srgb_nonlinear_ext", 39) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_EXTENDED_SRGB_NONLINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_display_native_amd", 30) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DISPLAY_NATIVE_AMD); }
        else if (std::strncmp(nodeVal, "colorspace_srgb_nonlinear_khr", 29) == 0) { e |= static_cast<enumIntType>(VK_COLORSPACE_SRGB_NONLINEAR_KHR); }
        else if (std::strncmp(nodeVal, "color_space_dci_p3_linear_ext", 29) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_DCI_P3_LINEAR_EXT); }
        else if (std::strncmp(nodeVal, "color_space_max_enum_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_COLOR_SPACE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkColorSpaceKHR>(e);
}


static inline ::VkSurfaceTransformFlagBitsKHR hu::val<::VkSurfaceTransformFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSurfaceTransformFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "identity_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "rotate_90_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_ROTATE_90_BIT_KHR); }
        else if (std::strncmp(nodeVal, "rotate_180_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_ROTATE_180_BIT_KHR); }
        else if (std::strncmp(nodeVal, "rotate_270_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_ROTATE_270_BIT_KHR); }
        else if (std::strncmp(nodeVal, "horizontal_mirror_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_BIT_KHR); }
        else if (std::strncmp(nodeVal, "horizontal_mirror_rotate_90_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_90_BIT_KHR); }
        else if (std::strncmp(nodeVal, "horizontal_mirror_rotate_180_bit", 32) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_180_BIT_KHR); }
        else if (std::strncmp(nodeVal, "horizontal_mirror_rotate_270_bit", 32) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_HORIZONTAL_MIRROR_ROTATE_270_BIT_KHR); }
        else if (std::strncmp(nodeVal, "inherit_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_INHERIT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_TRANSFORM_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSurfaceTransformFlagBitsKHR>(e);
}


static inline ::VkCompositeAlphaFlagBitsKHR hu::val<::VkCompositeAlphaFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCompositeAlphaFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "pre_multiplied_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR); }
        else if (std::strncmp(nodeVal, "post_multiplied_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR); }
        else if (std::strncmp(nodeVal, "inherit_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_COMPOSITE_ALPHA_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCompositeAlphaFlagBitsKHR>(e);
}


static inline ::VkSwapchainCreateFlagBitsKHR hu::val<::VkSwapchainCreateFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSwapchainCreateFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "split_instance_bind_regions_bit", 31) == 0) { e |= static_cast<enumIntType>(VK_SWAPCHAIN_CREATE_SPLIT_INSTANCE_BIND_REGIONS_BIT_KHR); }
        else if (std::strncmp(nodeVal, "protected_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_SWAPCHAIN_CREATE_PROTECTED_BIT_KHR); }
        else if (std::strncmp(nodeVal, "mutable_format_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_SWAPCHAIN_CREATE_MUTABLE_FORMAT_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SWAPCHAIN_CREATE_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSwapchainCreateFlagBitsKHR>(e);
}


static inline ::VkDeviceGroupPresentModeFlagBitsKHR hu::val<::VkDeviceGroupPresentModeFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDeviceGroupPresentModeFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "local_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_BIT_KHR); }
        else if (std::strncmp(nodeVal, "remote_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_GROUP_PRESENT_MODE_REMOTE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "sum_bit", 7) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_GROUP_PRESENT_MODE_SUM_BIT_KHR); }
        else if (std::strncmp(nodeVal, "local_multi_device_bit", 22) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_GROUP_PRESENT_MODE_LOCAL_MULTI_DEVICE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_GROUP_PRESENT_MODE_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDeviceGroupPresentModeFlagBitsKHR>(e);
}


static inline ::VkDisplayPlaneAlphaFlagBitsKHR hu::val<::VkDisplayPlaneAlphaFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDisplayPlaneAlphaFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_PLANE_ALPHA_OPAQUE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "global_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_PLANE_ALPHA_GLOBAL_BIT_KHR); }
        else if (std::strncmp(nodeVal, "per_pixel_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_BIT_KHR); }
        else if (std::strncmp(nodeVal, "per_pixel_premultiplied_bit", 27) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_PLANE_ALPHA_PER_PIXEL_PREMULTIPLIED_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_PLANE_ALPHA_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDisplayPlaneAlphaFlagBitsKHR>(e);
}


static inline ::VkPerformanceCounterUnitKHR hu::val<::VkPerformanceCounterUnitKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceCounterUnitKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "generic", 7) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_GENERIC_KHR); }
        else if (std::strncmp(nodeVal, "percentage", 10) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_PERCENTAGE_KHR); }
        else if (std::strncmp(nodeVal, "nanoseconds", 11) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_NANOSECONDS_KHR); }
        else if (std::strncmp(nodeVal, "bytes", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_BYTES_KHR); }
        else if (std::strncmp(nodeVal, "bytes_per_second", 16) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_BYTES_PER_SECOND_KHR); }
        else if (std::strncmp(nodeVal, "kelvin", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_KELVIN_KHR); }
        else if (std::strncmp(nodeVal, "watts", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_WATTS_KHR); }
        else if (std::strncmp(nodeVal, "volts", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_VOLTS_KHR); }
        else if (std::strncmp(nodeVal, "amps", 4) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_AMPS_KHR); }
        else if (std::strncmp(nodeVal, "hertz", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_HERTZ_KHR); }
        else if (std::strncmp(nodeVal, "cycles", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_CYCLES_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_UNIT_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceCounterUnitKHR>(e);
}


static inline ::VkPerformanceCounterScopeKHR hu::val<::VkPerformanceCounterScopeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceCounterScopeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "performance_counter_scope_command_buffer", 40) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_BUFFER_KHR); }
        else if (std::strncmp(nodeVal, "performance_counter_scope_render_pass", 37) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_SCOPE_RENDER_PASS_KHR); }
        else if (std::strncmp(nodeVal, "performance_counter_scope_command", 33) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_SCOPE_COMMAND_KHR); }
        else if (std::strncmp(nodeVal, "query_scope_command_buffer", 26) == 0) { e |= static_cast<enumIntType>(VK_QUERY_SCOPE_COMMAND_BUFFER_KHR); }
        else if (std::strncmp(nodeVal, "query_scope_render_pass", 23) == 0) { e |= static_cast<enumIntType>(VK_QUERY_SCOPE_RENDER_PASS_KHR); }
        else if (std::strncmp(nodeVal, "query_scope_command", 19) == 0) { e |= static_cast<enumIntType>(VK_QUERY_SCOPE_COMMAND_KHR); }
        else if (std::strncmp(nodeVal, "performance_counter_scope_max_enum", 34) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_SCOPE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceCounterScopeKHR>(e);
}


static inline ::VkPerformanceCounterStorageKHR hu::val<::VkPerformanceCounterStorageKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceCounterStorageKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "int32", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_INT32_KHR); }
        else if (std::strncmp(nodeVal, "int64", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_INT64_KHR); }
        else if (std::strncmp(nodeVal, "uint32", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_UINT32_KHR); }
        else if (std::strncmp(nodeVal, "uint64", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_UINT64_KHR); }
        else if (std::strncmp(nodeVal, "float32", 7) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_FLOAT32_KHR); }
        else if (std::strncmp(nodeVal, "float64", 7) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_FLOAT64_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_STORAGE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceCounterStorageKHR>(e);
}


static inline ::VkPerformanceCounterDescriptionFlagBitsKHR hu::val<::VkPerformanceCounterDescriptionFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceCounterDescriptionFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "performance_impacting_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_BIT_KHR); }
        else if (std::strncmp(nodeVal, "concurrently_impacted_bit", 25) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_BIT_KHR); }
        else if (std::strncmp(nodeVal, "performance_impacting", 21) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_DESCRIPTION_PERFORMANCE_IMPACTING_KHR); }
        else if (std::strncmp(nodeVal, "concurrently_impacted", 21) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_DESCRIPTION_CONCURRENTLY_IMPACTED_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_COUNTER_DESCRIPTION_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceCounterDescriptionFlagBitsKHR>(e);
}


static inline ::VkAcquireProfilingLockFlagBitsKHR hu::val<::VkAcquireProfilingLockFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAcquireProfilingLockFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vk_acquire_profiling_lock_flag_bits_max_enum_khr", 48) == 0) { e |= static_cast<enumIntType>(VK_ACQUIRE_PROFILING_LOCK_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAcquireProfilingLockFlagBitsKHR>(e);
}


static inline ::VkFragmentShadingRateCombinerOpKHR hu::val<::VkFragmentShadingRateCombinerOpKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFragmentShadingRateCombinerOpKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "keep", 4) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_KEEP_KHR); }
        else if (std::strncmp(nodeVal, "replace", 7) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_REPLACE_KHR); }
        else if (std::strncmp(nodeVal, "min", 3) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MIN_KHR); }
        else if (std::strncmp(nodeVal, "max", 3) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_KHR); }
        else if (std::strncmp(nodeVal, "mul", 3) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MUL_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_COMBINER_OP_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFragmentShadingRateCombinerOpKHR>(e);
}


static inline ::VkPipelineExecutableStatisticFormatKHR hu::val<::VkPipelineExecutableStatisticFormatKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineExecutableStatisticFormatKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "bool32", 6) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_BOOL32_KHR); }
        else if (std::strncmp(nodeVal, "int64", 5) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_INT64_KHR); }
        else if (std::strncmp(nodeVal, "uint64", 6) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_UINT64_KHR); }
        else if (std::strncmp(nodeVal, "float64", 7) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_FLOAT64_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_EXECUTABLE_STATISTIC_FORMAT_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineExecutableStatisticFormatKHR>(e);
}


static inline ::VkDebugReportObjectTypeEXT hu::val<::VkDebugReportObjectTypeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDebugReportObjectTypeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "unknown", 7) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_UNKNOWN_EXT); }
        else if (std::strncmp(nodeVal, "instance", 8) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_INSTANCE_EXT); }
        else if (std::strncmp(nodeVal, "physical_device", 15) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_PHYSICAL_DEVICE_EXT); }
        else if (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_EXT); }
        else if (std::strncmp(nodeVal, "queue", 5) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_QUEUE_EXT); }
        else if (std::strncmp(nodeVal, "semaphore", 9) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SEMAPHORE_EXT); }
        else if (std::strncmp(nodeVal, "command_buffer", 14) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_BUFFER_EXT); }
        else if (std::strncmp(nodeVal, "fence", 5) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_FENCE_EXT); }
        else if (std::strncmp(nodeVal, "device_memory", 13) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DEVICE_MEMORY_EXT); }
        else if (std::strncmp(nodeVal, "buffer", 6) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_EXT); }
        else if (std::strncmp(nodeVal, "image", 5) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_EXT); }
        else if (std::strncmp(nodeVal, "event", 5) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_EVENT_EXT); }
        else if (std::strncmp(nodeVal, "query_pool", 10) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_QUERY_POOL_EXT); }
        else if (std::strncmp(nodeVal, "buffer_view", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_BUFFER_VIEW_EXT); }
        else if (std::strncmp(nodeVal, "image_view", 10) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_IMAGE_VIEW_EXT); }
        else if (std::strncmp(nodeVal, "shader_module", 13) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SHADER_MODULE_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_cache", 14) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_CACHE_EXT); }
        else if (std::strncmp(nodeVal, "pipeline_layout", 15) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_LAYOUT_EXT); }
        else if (std::strncmp(nodeVal, "render_pass", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_RENDER_PASS_EXT); }
        else if (std::strncmp(nodeVal, "pipeline", 8) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_PIPELINE_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_set_layout", 21) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_LAYOUT_EXT); }
        else if (std::strncmp(nodeVal, "sampler", 7) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_pool", 15) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_POOL_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_set", 14) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_SET_EXT); }
        else if (std::strncmp(nodeVal, "framebuffer", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_FRAMEBUFFER_EXT); }
        else if (std::strncmp(nodeVal, "command_pool", 12) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_COMMAND_POOL_EXT); }
        else if (std::strncmp(nodeVal, "surface_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SURFACE_KHR_EXT); }
        else if (std::strncmp(nodeVal, "swapchain_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SWAPCHAIN_KHR_EXT); }
        else if (std::strncmp(nodeVal, "debug_report_callback_ext", 25) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_CALLBACK_EXT_EXT); }
        else if (std::strncmp(nodeVal, "display_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_KHR_EXT); }
        else if (std::strncmp(nodeVal, "display_mode_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DISPLAY_MODE_KHR_EXT); }
        else if (std::strncmp(nodeVal, "validation_cache_ext", 20) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT_EXT); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion", 24) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_update_template", 26) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_khr", 26) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_KHR_EXT); }
        else if (std::strncmp(nodeVal, "acceleration_structure_nv", 25) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_ACCELERATION_STRUCTURE_NV_EXT); }
        else if (std::strncmp(nodeVal, "debug_report", 12) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DEBUG_REPORT_EXT); }
        else if (std::strncmp(nodeVal, "validation_cache", 16) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_VALIDATION_CACHE_EXT); }
        else if (std::strncmp(nodeVal, "descriptor_update_template_khr", 30) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_DESCRIPTOR_UPDATE_TEMPLATE_KHR_EXT); }
        else if (std::strncmp(nodeVal, "sampler_ycbcr_conversion_khr", 28) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_SAMPLER_YCBCR_CONVERSION_KHR_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_OBJECT_TYPE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDebugReportObjectTypeEXT>(e);
}


static inline ::VkDebugReportFlagBitsEXT hu::val<::VkDebugReportFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDebugReportFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "information_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_INFORMATION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "warning_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_WARNING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "performance_warning_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "error_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_ERROR_BIT_EXT); }
        else if (std::strncmp(nodeVal, "debug_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_DEBUG_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_REPORT_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDebugReportFlagBitsEXT>(e);
}


static inline ::VkRasterizationOrderAMD hu::val<::VkRasterizationOrderAMD>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkRasterizationOrderAMD>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "strict", 6) == 0) { e |= static_cast<enumIntType>(VK_RASTERIZATION_ORDER_STRICT_AMD); }
        else if (std::strncmp(nodeVal, "relaxed", 7) == 0) { e |= static_cast<enumIntType>(VK_RASTERIZATION_ORDER_RELAXED_AMD); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_RASTERIZATION_ORDER_MAX_ENUM_AMD); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkRasterizationOrderAMD>(e);
}


static inline ::VkShaderInfoTypeAMD hu::val<::VkShaderInfoTypeAMD>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderInfoTypeAMD>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "statistics", 10) == 0) { e |= static_cast<enumIntType>(VK_SHADER_INFO_TYPE_STATISTICS_AMD); }
        else if (std::strncmp(nodeVal, "binary", 6) == 0) { e |= static_cast<enumIntType>(VK_SHADER_INFO_TYPE_BINARY_AMD); }
        else if (std::strncmp(nodeVal, "disassembly", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_INFO_TYPE_DISASSEMBLY_AMD); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SHADER_INFO_TYPE_MAX_ENUM_AMD); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderInfoTypeAMD>(e);
}


static inline ::VkExternalMemoryHandleTypeFlagBitsNV hu::val<::VkExternalMemoryHandleTypeFlagBitsNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalMemoryHandleTypeFlagBitsNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_win32_bit", 16) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_BIT_NV); }
        else if (std::strncmp(nodeVal, "opaque_win32_kmt_bit", 20) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_OPAQUE_WIN32_KMT_BIT_NV); }
        else if (std::strncmp(nodeVal, "d3d11_image_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_BIT_NV); }
        else if (std::strncmp(nodeVal, "d3d11_image_kmt_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_D3D11_IMAGE_KMT_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_HANDLE_TYPE_FLAG_BITS_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalMemoryHandleTypeFlagBitsNV>(e);
}


static inline ::VkExternalMemoryFeatureFlagBitsNV hu::val<::VkExternalMemoryFeatureFlagBitsNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkExternalMemoryFeatureFlagBitsNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "dedicated_only_bit", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_DEDICATED_ONLY_BIT_NV); }
        else if (std::strncmp(nodeVal, "exportable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_EXPORTABLE_BIT_NV); }
        else if (std::strncmp(nodeVal, "importable_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_IMPORTABLE_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_EXTERNAL_MEMORY_FEATURE_FLAG_BITS_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkExternalMemoryFeatureFlagBitsNV>(e);
}


static inline ::VkValidationCheckEXT hu::val<::VkValidationCheckEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkValidationCheckEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "all", 3) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_CHECK_ALL_EXT); }
        else if (std::strncmp(nodeVal, "shaders", 7) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_CHECK_SHADERS_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_CHECK_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkValidationCheckEXT>(e);
}


static inline ::VkConditionalRenderingFlagBitsEXT hu::val<::VkConditionalRenderingFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkConditionalRenderingFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "inverted_bit", 12) == 0) { e |= static_cast<enumIntType>(VK_CONDITIONAL_RENDERING_INVERTED_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_CONDITIONAL_RENDERING_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkConditionalRenderingFlagBitsEXT>(e);
}


static inline ::VkSurfaceCounterFlagBitsEXT hu::val<::VkSurfaceCounterFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkSurfaceCounterFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vblank_bit", 10) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_COUNTER_VBLANK_BIT_EXT); }
        else if (std::strncmp(nodeVal, "vblank", 6) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_COUNTER_VBLANK_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_SURFACE_COUNTER_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkSurfaceCounterFlagBitsEXT>(e);
}


static inline ::VkDisplayPowerStateEXT hu::val<::VkDisplayPowerStateEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDisplayPowerStateEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "off", 3) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_POWER_STATE_OFF_EXT); }
        else if (std::strncmp(nodeVal, "suspend", 7) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_POWER_STATE_SUSPEND_EXT); }
        else if (std::strncmp(nodeVal, "on", 2) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_POWER_STATE_ON_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_POWER_STATE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDisplayPowerStateEXT>(e);
}


static inline ::VkDeviceEventTypeEXT hu::val<::VkDeviceEventTypeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDeviceEventTypeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "display_hotplug", 15) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_EVENT_TYPE_DISPLAY_HOTPLUG_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_EVENT_TYPE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDeviceEventTypeEXT>(e);
}


static inline ::VkDisplayEventTypeEXT hu::val<::VkDisplayEventTypeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDisplayEventTypeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "first_pixel_out", 15) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_EVENT_TYPE_FIRST_PIXEL_OUT_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DISPLAY_EVENT_TYPE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDisplayEventTypeEXT>(e);
}


static inline ::VkViewportCoordinateSwizzleNV hu::val<::VkViewportCoordinateSwizzleNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkViewportCoordinateSwizzleNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "positive_x", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_X_NV); }
        else if (std::strncmp(nodeVal, "negative_x", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_X_NV); }
        else if (std::strncmp(nodeVal, "positive_y", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Y_NV); }
        else if (std::strncmp(nodeVal, "negative_y", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Y_NV); }
        else if (std::strncmp(nodeVal, "positive_z", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_Z_NV); }
        else if (std::strncmp(nodeVal, "negative_z", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_Z_NV); }
        else if (std::strncmp(nodeVal, "positive_w", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_POSITIVE_W_NV); }
        else if (std::strncmp(nodeVal, "negative_w", 10) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_NEGATIVE_W_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VIEWPORT_COORDINATE_SWIZZLE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkViewportCoordinateSwizzleNV>(e);
}


static inline ::VkDiscardRectangleModeEXT hu::val<::VkDiscardRectangleModeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDiscardRectangleModeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "inclusive", 9) == 0) { e |= static_cast<enumIntType>(VK_DISCARD_RECTANGLE_MODE_INCLUSIVE_EXT); }
        else if (std::strncmp(nodeVal, "exclusive", 9) == 0) { e |= static_cast<enumIntType>(VK_DISCARD_RECTANGLE_MODE_EXCLUSIVE_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DISCARD_RECTANGLE_MODE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDiscardRectangleModeEXT>(e);
}


static inline ::VkConservativeRasterizationModeEXT hu::val<::VkConservativeRasterizationModeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkConservativeRasterizationModeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "disabled", 8) == 0) { e |= static_cast<enumIntType>(VK_CONSERVATIVE_RASTERIZATION_MODE_DISABLED_EXT); }
        else if (std::strncmp(nodeVal, "overestimate", 12) == 0) { e |= static_cast<enumIntType>(VK_CONSERVATIVE_RASTERIZATION_MODE_OVERESTIMATE_EXT); }
        else if (std::strncmp(nodeVal, "underestimate", 13) == 0) { e |= static_cast<enumIntType>(VK_CONSERVATIVE_RASTERIZATION_MODE_UNDERESTIMATE_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_CONSERVATIVE_RASTERIZATION_MODE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkConservativeRasterizationModeEXT>(e);
}


static inline ::VkDebugUtilsMessageSeverityFlagBitsEXT hu::val<::VkDebugUtilsMessageSeverityFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDebugUtilsMessageSeverityFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "verbose_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "info_bit", 8) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT); }
        else if (std::strncmp(nodeVal, "warning_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "error_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_SEVERITY_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDebugUtilsMessageSeverityFlagBitsEXT>(e);
}


static inline ::VkDebugUtilsMessageTypeFlagBitsEXT hu::val<::VkDebugUtilsMessageTypeFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDebugUtilsMessageTypeFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "general_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT); }
        else if (std::strncmp(nodeVal, "validation_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "performance_bit", 15) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEBUG_UTILS_MESSAGE_TYPE_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDebugUtilsMessageTypeFlagBitsEXT>(e);
}


static inline ::VkBlendOverlapEXT hu::val<::VkBlendOverlapEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBlendOverlapEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "uncorrelated", 12) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OVERLAP_UNCORRELATED_EXT); }
        else if (std::strncmp(nodeVal, "disjoint", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OVERLAP_DISJOINT_EXT); }
        else if (std::strncmp(nodeVal, "conjoint", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OVERLAP_CONJOINT_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_BLEND_OVERLAP_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBlendOverlapEXT>(e);
}


static inline ::VkCoverageModulationModeNV hu::val<::VkCoverageModulationModeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCoverageModulationModeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "none", 4) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_MODULATION_MODE_NONE_NV); }
        else if (std::strncmp(nodeVal, "rgb", 3) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_MODULATION_MODE_RGB_NV); }
        else if (std::strncmp(nodeVal, "alpha", 5) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_MODULATION_MODE_ALPHA_NV); }
        else if (std::strncmp(nodeVal, "rgba", 4) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_MODULATION_MODE_RGBA_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_MODULATION_MODE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCoverageModulationModeNV>(e);
}


static inline ::VkValidationCacheHeaderVersionEXT hu::val<::VkValidationCacheHeaderVersionEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkValidationCacheHeaderVersionEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "one", 3) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_CACHE_HEADER_VERSION_ONE_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_CACHE_HEADER_VERSION_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkValidationCacheHeaderVersionEXT>(e);
}


static inline ::VkShadingRatePaletteEntryNV hu::val<::VkShadingRatePaletteEntryNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShadingRatePaletteEntryNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "no_invocations", 14) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_NO_INVOCATIONS_NV); }
        else if (std::strncmp(nodeVal, "16_invocations_per_pixel", 24) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_16_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "8_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_8_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "4_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_4_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "2_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_2_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_pixel", 22) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x1_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X1_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_1x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_1X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_4x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x4_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_2X4_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_4x4_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_1_INVOCATION_PER_4X4_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SHADING_RATE_PALETTE_ENTRY_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShadingRatePaletteEntryNV>(e);
}


static inline ::VkCoarseSampleOrderTypeNV hu::val<::VkCoarseSampleOrderTypeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCoarseSampleOrderTypeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "default", 7) == 0) { e |= static_cast<enumIntType>(VK_COARSE_SAMPLE_ORDER_TYPE_DEFAULT_NV); }
        else if (std::strncmp(nodeVal, "custom", 6) == 0) { e |= static_cast<enumIntType>(VK_COARSE_SAMPLE_ORDER_TYPE_CUSTOM_NV); }
        else if (std::strncmp(nodeVal, "pixel_major", 11) == 0) { e |= static_cast<enumIntType>(VK_COARSE_SAMPLE_ORDER_TYPE_PIXEL_MAJOR_NV); }
        else if (std::strncmp(nodeVal, "sample_major", 12) == 0) { e |= static_cast<enumIntType>(VK_COARSE_SAMPLE_ORDER_TYPE_SAMPLE_MAJOR_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COARSE_SAMPLE_ORDER_TYPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCoarseSampleOrderTypeNV>(e);
}


static inline ::VkRayTracingShaderGroupTypeKHR hu::val<::VkRayTracingShaderGroupTypeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkRayTracingShaderGroupTypeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "general_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_KHR); }
        else if (std::strncmp(nodeVal, "triangles_hit_group_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_KHR); }
        else if (std::strncmp(nodeVal, "procedural_hit_group_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_KHR); }
        else if (std::strncmp(nodeVal, "general_nv", 10) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_GENERAL_NV); }
        else if (std::strncmp(nodeVal, "triangles_hit_group_nv", 22) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_TRIANGLES_HIT_GROUP_NV); }
        else if (std::strncmp(nodeVal, "procedural_hit_group_nv", 23) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_PROCEDURAL_HIT_GROUP_NV); }
        else if (std::strncmp(nodeVal, "max_enum_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_RAY_TRACING_SHADER_GROUP_TYPE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkRayTracingShaderGroupTypeKHR>(e);
}


static inline ::VkGeometryTypeKHR hu::val<::VkGeometryTypeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkGeometryTypeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "triangles_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_TRIANGLES_KHR); }
        else if (std::strncmp(nodeVal, "aabbs_khr", 9) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_AABBS_KHR); }
        else if (std::strncmp(nodeVal, "instances_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_INSTANCES_KHR); }
        else if (std::strncmp(nodeVal, "triangles_nv", 12) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_TRIANGLES_NV); }
        else if (std::strncmp(nodeVal, "aabbs_nv", 8) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_AABBS_NV); }
        else if (std::strncmp(nodeVal, "max_enum_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_TYPE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkGeometryTypeKHR>(e);
}


static inline ::VkAccelerationStructureTypeKHR hu::val<::VkAccelerationStructureTypeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccelerationStructureTypeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "top_level_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_KHR); }
        else if (std::strncmp(nodeVal, "bottom_level_khr", 16) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_KHR); }
        else if (std::strncmp(nodeVal, "generic_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_GENERIC_KHR); }
        else if (std::strncmp(nodeVal, "top_level_nv", 12) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL_NV); }
        else if (std::strncmp(nodeVal, "bottom_level_nv", 15) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL_NV); }
        else if (std::strncmp(nodeVal, "max_enum_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_TYPE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccelerationStructureTypeKHR>(e);
}


static inline ::VkCopyAccelerationStructureModeKHR hu::val<::VkCopyAccelerationStructureModeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCopyAccelerationStructureModeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "clone_khr", 9) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_KHR); }
        else if (std::strncmp(nodeVal, "compact_khr", 11) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_KHR); }
        else if (std::strncmp(nodeVal, "serialize_khr", 13) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_SERIALIZE_KHR); }
        else if (std::strncmp(nodeVal, "deserialize_khr", 15) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_DESERIALIZE_KHR); }
        else if (std::strncmp(nodeVal, "clone_nv", 8) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_CLONE_NV); }
        else if (std::strncmp(nodeVal, "compact_nv", 10) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_COMPACT_NV); }
        else if (std::strncmp(nodeVal, "max_enum_khr", 12) == 0) { e |= static_cast<enumIntType>(VK_COPY_ACCELERATION_STRUCTURE_MODE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCopyAccelerationStructureModeKHR>(e);
}


static inline ::VkAccelerationStructureMemoryRequirementsTypeNV hu::val<::VkAccelerationStructureMemoryRequirementsTypeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccelerationStructureMemoryRequirementsTypeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "object", 6) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_OBJECT_NV); }
        else if (std::strncmp(nodeVal, "build_scratch", 13) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_BUILD_SCRATCH_NV); }
        else if (std::strncmp(nodeVal, "update_scratch", 14) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_UPDATE_SCRATCH_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_MEMORY_REQUIREMENTS_TYPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccelerationStructureMemoryRequirementsTypeNV>(e);
}


static inline ::VkGeometryFlagBitsKHR hu::val<::VkGeometryFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkGeometryFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "opaque_bit_khr", 14) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_OPAQUE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "no_duplicate_any_hit_invocation_bit_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_KHR); }
        else if (std::strncmp(nodeVal, "opaque_bit_nv", 13) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_OPAQUE_BIT_NV); }
        else if (std::strncmp(nodeVal, "no_duplicate_any_hit_invocation_bit_nv", 38) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_NO_DUPLICATE_ANY_HIT_INVOCATION_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkGeometryFlagBitsKHR>(e);
}


static inline ::VkGeometryInstanceFlagBitsKHR hu::val<::VkGeometryInstanceFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkGeometryInstanceFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "triangle_facing_cull_disable_bit_khr", 36) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_TRIANGLE_FACING_CULL_DISABLE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "triangle_front_counterclockwise_bit_khr", 39) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "force_opaque_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "force_no_opaque_bit_khr", 23) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "triangle_cull_disable_bit_nv", 28) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_TRIANGLE_CULL_DISABLE_BIT_NV); }
        else if (std::strncmp(nodeVal, "triangle_front_counterclockwise_bit_nv", 38) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_TRIANGLE_FRONT_COUNTERCLOCKWISE_BIT_NV); }
        else if (std::strncmp(nodeVal, "force_opaque_bit_nv", 19) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_FORCE_OPAQUE_BIT_NV); }
        else if (std::strncmp(nodeVal, "force_no_opaque_bit_nv", 22) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_FORCE_NO_OPAQUE_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_GEOMETRY_INSTANCE_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkGeometryInstanceFlagBitsKHR>(e);
}


static inline ::VkBuildAccelerationStructureFlagBitsKHR hu::val<::VkBuildAccelerationStructureFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBuildAccelerationStructureFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "allow_update_bit_khr", 20) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "allow_compaction_bit_khr", 24) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_KHR); }
        else if (std::strncmp(nodeVal, "prefer_fast_trace_bit_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_KHR); }
        else if (std::strncmp(nodeVal, "prefer_fast_build_bit_khr", 25) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_KHR); }
        else if (std::strncmp(nodeVal, "low_memory_bit_khr", 18) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "allow_update_bit_nv", 19) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_UPDATE_BIT_NV); }
        else if (std::strncmp(nodeVal, "allow_compaction_bit_nv", 23) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_ALLOW_COMPACTION_BIT_NV); }
        else if (std::strncmp(nodeVal, "prefer_fast_trace_bit_nv", 24) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_TRACE_BIT_NV); }
        else if (std::strncmp(nodeVal, "prefer_fast_build_bit_nv", 24) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_PREFER_FAST_BUILD_BIT_NV); }
        else if (std::strncmp(nodeVal, "low_memory_bit_nv", 17) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_LOW_MEMORY_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum_khr", 22) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBuildAccelerationStructureFlagBitsKHR>(e);
}


static inline ::VkQueueGlobalPriorityEXT hu::val<::VkQueueGlobalPriorityEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueueGlobalPriorityEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "low", 3) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GLOBAL_PRIORITY_LOW_EXT); }
        else if (std::strncmp(nodeVal, "medium", 6) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GLOBAL_PRIORITY_MEDIUM_EXT); }
        else if (std::strncmp(nodeVal, "high", 4) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GLOBAL_PRIORITY_HIGH_EXT); }
        else if (std::strncmp(nodeVal, "realtime", 8) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GLOBAL_PRIORITY_REALTIME_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_QUEUE_GLOBAL_PRIORITY_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueueGlobalPriorityEXT>(e);
}


static inline ::VkPipelineCompilerControlFlagBitsAMD hu::val<::VkPipelineCompilerControlFlagBitsAMD>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineCompilerControlFlagBitsAMD>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vk_pipeline_compiler_control_flag_bits_max_enum_amd", 51) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_COMPILER_CONTROL_FLAG_BITS_MAX_ENUM_AMD); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineCompilerControlFlagBitsAMD>(e);
}


static inline ::VkTimeDomainEXT hu::val<::VkTimeDomainEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkTimeDomainEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_TIME_DOMAIN_DEVICE_EXT); }
        else if (std::strncmp(nodeVal, "clock_monotonic", 15) == 0) { e |= static_cast<enumIntType>(VK_TIME_DOMAIN_CLOCK_MONOTONIC_EXT); }
        else if (std::strncmp(nodeVal, "clock_monotonic_raw", 19) == 0) { e |= static_cast<enumIntType>(VK_TIME_DOMAIN_CLOCK_MONOTONIC_RAW_EXT); }
        else if (std::strncmp(nodeVal, "query_performance_counter", 25) == 0) { e |= static_cast<enumIntType>(VK_TIME_DOMAIN_QUERY_PERFORMANCE_COUNTER_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_TIME_DOMAIN_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkTimeDomainEXT>(e);
}


static inline ::VkMemoryOverallocationBehaviorAMD hu::val<::VkMemoryOverallocationBehaviorAMD>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkMemoryOverallocationBehaviorAMD>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "default", 7) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_OVERALLOCATION_BEHAVIOR_DEFAULT_AMD); }
        else if (std::strncmp(nodeVal, "allowed", 7) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_OVERALLOCATION_BEHAVIOR_ALLOWED_AMD); }
        else if (std::strncmp(nodeVal, "disallowed", 10) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_OVERALLOCATION_BEHAVIOR_DISALLOWED_AMD); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_MEMORY_OVERALLOCATION_BEHAVIOR_MAX_ENUM_AMD); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkMemoryOverallocationBehaviorAMD>(e);
}


static inline ::VkPipelineCreationFeedbackFlagBitsEXT hu::val<::VkPipelineCreationFeedbackFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPipelineCreationFeedbackFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "valid_bit", 9) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATION_FEEDBACK_VALID_BIT_EXT); }
        else if (std::strncmp(nodeVal, "application_pipeline_cache_hit_bit", 34) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATION_FEEDBACK_APPLICATION_PIPELINE_CACHE_HIT_BIT_EXT); }
        else if (std::strncmp(nodeVal, "base_pipeline_acceleration_bit", 30) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATION_FEEDBACK_BASE_PIPELINE_ACCELERATION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_PIPELINE_CREATION_FEEDBACK_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPipelineCreationFeedbackFlagBitsEXT>(e);
}


static inline ::VkPerformanceConfigurationTypeINTEL hu::val<::VkPerformanceConfigurationTypeINTEL>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceConfigurationTypeINTEL>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "command_queue_metrics_discovery_activated", 41) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_CONFIGURATION_TYPE_COMMAND_QUEUE_METRICS_DISCOVERY_ACTIVATED_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_CONFIGURATION_TYPE_MAX_ENUM_INTEL); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceConfigurationTypeINTEL>(e);
}


static inline ::VkQueryPoolSamplingModeINTEL hu::val<::VkQueryPoolSamplingModeINTEL>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkQueryPoolSamplingModeINTEL>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "manual", 6) == 0) { e |= static_cast<enumIntType>(VK_QUERY_POOL_SAMPLING_MODE_MANUAL_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_QUERY_POOL_SAMPLING_MODE_MAX_ENUM_INTEL); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkQueryPoolSamplingModeINTEL>(e);
}


static inline ::VkPerformanceOverrideTypeINTEL hu::val<::VkPerformanceOverrideTypeINTEL>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceOverrideTypeINTEL>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "null_hardware", 13) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_OVERRIDE_TYPE_NULL_HARDWARE_INTEL); }
        else if (std::strncmp(nodeVal, "flush_gpu_caches", 16) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_OVERRIDE_TYPE_FLUSH_GPU_CACHES_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_OVERRIDE_TYPE_MAX_ENUM_INTEL); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceOverrideTypeINTEL>(e);
}


static inline ::VkPerformanceParameterTypeINTEL hu::val<::VkPerformanceParameterTypeINTEL>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceParameterTypeINTEL>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "hw_counters_supported", 21) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_PARAMETER_TYPE_HW_COUNTERS_SUPPORTED_INTEL); }
        else if (std::strncmp(nodeVal, "stream_marker_valid_bits", 24) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_PARAMETER_TYPE_STREAM_MARKER_VALID_BITS_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_PARAMETER_TYPE_MAX_ENUM_INTEL); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceParameterTypeINTEL>(e);
}


static inline ::VkPerformanceValueTypeINTEL hu::val<::VkPerformanceValueTypeINTEL>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPerformanceValueTypeINTEL>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "uint32", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_UINT32_INTEL); }
        else if (std::strncmp(nodeVal, "uint64", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_UINT64_INTEL); }
        else if (std::strncmp(nodeVal, "float", 5) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_FLOAT_INTEL); }
        else if (std::strncmp(nodeVal, "bool", 4) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_BOOL_INTEL); }
        else if (std::strncmp(nodeVal, "string", 6) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_STRING_INTEL); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_PERFORMANCE_VALUE_TYPE_MAX_ENUM_INTEL); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPerformanceValueTypeINTEL>(e);
}


static inline ::VkShaderCorePropertiesFlagBitsAMD hu::val<::VkShaderCorePropertiesFlagBitsAMD>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderCorePropertiesFlagBitsAMD>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vk_shader_core_properties_flag_bits_max_enum_amd", 48) == 0) { e |= static_cast<enumIntType>(VK_SHADER_CORE_PROPERTIES_FLAG_BITS_MAX_ENUM_AMD); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderCorePropertiesFlagBitsAMD>(e);
}


static inline ::VkToolPurposeFlagBitsEXT hu::val<::VkToolPurposeFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkToolPurposeFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "validation_bit", 14) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_VALIDATION_BIT_EXT); }
        else if (std::strncmp(nodeVal, "profiling_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_PROFILING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "tracing_bit", 11) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_TRACING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "additional_features_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_ADDITIONAL_FEATURES_BIT_EXT); }
        else if (std::strncmp(nodeVal, "modifying_features_bit", 22) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_MODIFYING_FEATURES_BIT_EXT); }
        else if (std::strncmp(nodeVal, "debug_reporting_bit", 19) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_DEBUG_REPORTING_BIT_EXT); }
        else if (std::strncmp(nodeVal, "debug_markers_bit", 17) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_DEBUG_MARKERS_BIT_EXT); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_TOOL_PURPOSE_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkToolPurposeFlagBitsEXT>(e);
}


static inline ::VkValidationFeatureEnableEXT hu::val<::VkValidationFeatureEnableEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkValidationFeatureEnableEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "gpu_assisted", 12) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_EXT); }
        else if (std::strncmp(nodeVal, "gpu_assisted_reserve_binding_slot", 33) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_GPU_ASSISTED_RESERVE_BINDING_SLOT_EXT); }
        else if (std::strncmp(nodeVal, "best_practices", 14) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_BEST_PRACTICES_EXT); }
        else if (std::strncmp(nodeVal, "debug_printf", 12) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_DEBUG_PRINTF_EXT); }
        else if (std::strncmp(nodeVal, "synchronization_validation", 26) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_SYNCHRONIZATION_VALIDATION_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_ENABLE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkValidationFeatureEnableEXT>(e);
}


static inline ::VkValidationFeatureDisableEXT hu::val<::VkValidationFeatureDisableEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkValidationFeatureDisableEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "all", 3) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_ALL_EXT); }
        else if (std::strncmp(nodeVal, "shaders", 7) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_SHADERS_EXT); }
        else if (std::strncmp(nodeVal, "thread_safety", 13) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_THREAD_SAFETY_EXT); }
        else if (std::strncmp(nodeVal, "api_parameters", 14) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_API_PARAMETERS_EXT); }
        else if (std::strncmp(nodeVal, "object_lifetimes", 16) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_OBJECT_LIFETIMES_EXT); }
        else if (std::strncmp(nodeVal, "core_checks", 11) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_CORE_CHECKS_EXT); }
        else if (std::strncmp(nodeVal, "unique_handles", 14) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_UNIQUE_HANDLES_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_VALIDATION_FEATURE_DISABLE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkValidationFeatureDisableEXT>(e);
}


static inline ::VkComponentTypeNV hu::val<::VkComponentTypeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkComponentTypeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "float16", 7) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_FLOAT16_NV); }
        else if (std::strncmp(nodeVal, "float32", 7) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_FLOAT32_NV); }
        else if (std::strncmp(nodeVal, "float64", 7) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_FLOAT64_NV); }
        else if (std::strncmp(nodeVal, "sint8", 5) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_SINT8_NV); }
        else if (std::strncmp(nodeVal, "sint16", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_SINT16_NV); }
        else if (std::strncmp(nodeVal, "sint32", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_SINT32_NV); }
        else if (std::strncmp(nodeVal, "sint64", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_SINT64_NV); }
        else if (std::strncmp(nodeVal, "uint8", 5) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_UINT8_NV); }
        else if (std::strncmp(nodeVal, "uint16", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_UINT16_NV); }
        else if (std::strncmp(nodeVal, "uint32", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_UINT32_NV); }
        else if (std::strncmp(nodeVal, "uint64", 6) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_UINT64_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COMPONENT_TYPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkComponentTypeNV>(e);
}


static inline ::VkScopeNV hu::val<::VkScopeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkScopeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_SCOPE_DEVICE_NV); }
        else if (std::strncmp(nodeVal, "workgroup", 9) == 0) { e |= static_cast<enumIntType>(VK_SCOPE_WORKGROUP_NV); }
        else if (std::strncmp(nodeVal, "subgroup", 8) == 0) { e |= static_cast<enumIntType>(VK_SCOPE_SUBGROUP_NV); }
        else if (std::strncmp(nodeVal, "queue_family", 12) == 0) { e |= static_cast<enumIntType>(VK_SCOPE_QUEUE_FAMILY_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SCOPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkScopeNV>(e);
}


static inline ::VkCoverageReductionModeNV hu::val<::VkCoverageReductionModeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkCoverageReductionModeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "merge", 5) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_REDUCTION_MODE_MERGE_NV); }
        else if (std::strncmp(nodeVal, "truncate", 8) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_REDUCTION_MODE_TRUNCATE_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_COVERAGE_REDUCTION_MODE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkCoverageReductionModeNV>(e);
}


static inline ::VkLineRasterizationModeEXT hu::val<::VkLineRasterizationModeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkLineRasterizationModeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "default", 7) == 0) { e |= static_cast<enumIntType>(VK_LINE_RASTERIZATION_MODE_DEFAULT_EXT); }
        else if (std::strncmp(nodeVal, "rectangular", 11) == 0) { e |= static_cast<enumIntType>(VK_LINE_RASTERIZATION_MODE_RECTANGULAR_EXT); }
        else if (std::strncmp(nodeVal, "bresenham", 9) == 0) { e |= static_cast<enumIntType>(VK_LINE_RASTERIZATION_MODE_BRESENHAM_EXT); }
        else if (std::strncmp(nodeVal, "rectangular_smooth", 18) == 0) { e |= static_cast<enumIntType>(VK_LINE_RASTERIZATION_MODE_RECTANGULAR_SMOOTH_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_LINE_RASTERIZATION_MODE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkLineRasterizationModeEXT>(e);
}


static inline ::VkIndirectCommandsTokenTypeNV hu::val<::VkIndirectCommandsTokenTypeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkIndirectCommandsTokenTypeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "shader_group", 12) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_SHADER_GROUP_NV); }
        else if (std::strncmp(nodeVal, "state_flags", 11) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_STATE_FLAGS_NV); }
        else if (std::strncmp(nodeVal, "index_buffer", 12) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_INDEX_BUFFER_NV); }
        else if (std::strncmp(nodeVal, "vertex_buffer", 13) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_VERTEX_BUFFER_NV); }
        else if (std::strncmp(nodeVal, "push_constant", 13) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_PUSH_CONSTANT_NV); }
        else if (std::strncmp(nodeVal, "draw_indexed", 12) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_INDEXED_NV); }
        else if (std::strncmp(nodeVal, "draw", 4) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_NV); }
        else if (std::strncmp(nodeVal, "draw_tasks", 10) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_DRAW_TASKS_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_TOKEN_TYPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkIndirectCommandsTokenTypeNV>(e);
}


static inline ::VkIndirectStateFlagBitsNV hu::val<::VkIndirectStateFlagBitsNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkIndirectStateFlagBitsNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "frontface_bit", 13) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_STATE_FLAG_FRONTFACE_BIT_NV); }
        else if (std::strncmp(nodeVal, "bits_max_enum", 13) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_STATE_FLAG_BITS_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkIndirectStateFlagBitsNV>(e);
}


static inline ::VkIndirectCommandsLayoutUsageFlagBitsNV hu::val<::VkIndirectCommandsLayoutUsageFlagBitsNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkIndirectCommandsLayoutUsageFlagBitsNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "explicit_preprocess_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_LAYOUT_USAGE_EXPLICIT_PREPROCESS_BIT_NV); }
        else if (std::strncmp(nodeVal, "indexed_sequences_bit", 21) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_LAYOUT_USAGE_INDEXED_SEQUENCES_BIT_NV); }
        else if (std::strncmp(nodeVal, "unordered_sequences_bit", 23) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_LAYOUT_USAGE_UNORDERED_SEQUENCES_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_INDIRECT_COMMANDS_LAYOUT_USAGE_FLAG_BITS_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkIndirectCommandsLayoutUsageFlagBitsNV>(e);
}


static inline ::VkDeviceMemoryReportEventTypeEXT hu::val<::VkDeviceMemoryReportEventTypeEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDeviceMemoryReportEventTypeEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "allocate", 8) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATE_EXT); }
        else if (std::strncmp(nodeVal, "free", 4) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_FREE_EXT); }
        else if (std::strncmp(nodeVal, "import", 6) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_IMPORT_EXT); }
        else if (std::strncmp(nodeVal, "unimport", 8) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_UNIMPORT_EXT); }
        else if (std::strncmp(nodeVal, "allocation_failed", 17) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_ALLOCATION_FAILED_EXT); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_MEMORY_REPORT_EVENT_TYPE_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDeviceMemoryReportEventTypeEXT>(e);
}


static inline ::VkPrivateDataSlotCreateFlagBitsEXT hu::val<::VkPrivateDataSlotCreateFlagBitsEXT>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkPrivateDataSlotCreateFlagBitsEXT>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "vk_private_data_slot_create_flag_bits_max_enum_ext", 50) == 0) { e |= static_cast<enumIntType>(VK_PRIVATE_DATA_SLOT_CREATE_FLAG_BITS_MAX_ENUM_EXT); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkPrivateDataSlotCreateFlagBitsEXT>(e);
}


static inline ::VkDeviceDiagnosticsConfigFlagBitsNV hu::val<::VkDeviceDiagnosticsConfigFlagBitsNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkDeviceDiagnosticsConfigFlagBitsNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "enable_shader_debug_info_bit", 28) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_SHADER_DEBUG_INFO_BIT_NV); }
        else if (std::strncmp(nodeVal, "enable_resource_tracking_bit", 28) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_RESOURCE_TRACKING_BIT_NV); }
        else if (std::strncmp(nodeVal, "enable_automatic_checkpoints_bit", 32) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_DIAGNOSTICS_CONFIG_ENABLE_AUTOMATIC_CHECKPOINTS_BIT_NV); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_DEVICE_DIAGNOSTICS_CONFIG_FLAG_BITS_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkDeviceDiagnosticsConfigFlagBitsNV>(e);
}


static inline ::VkFragmentShadingRateTypeNV hu::val<::VkFragmentShadingRateTypeNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFragmentShadingRateTypeNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "fragment_size", 13) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_TYPE_FRAGMENT_SIZE_NV); }
        else if (std::strncmp(nodeVal, "enums", 5) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_TYPE_ENUMS_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_TYPE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFragmentShadingRateTypeNV>(e);
}


static inline ::VkFragmentShadingRateNV hu::val<::VkFragmentShadingRateNV>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkFragmentShadingRateNV>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "1_invocation_per_pixel", 22) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_1x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_1X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x1_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X1_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_2x4_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_2X4_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_4x2_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X2_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "1_invocation_per_4x4_pixels", 27) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_1_INVOCATION_PER_4X4_PIXELS_NV); }
        else if (std::strncmp(nodeVal, "2_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_2_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "4_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_4_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "8_invocations_per_pixel", 23) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_8_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "16_invocations_per_pixel", 24) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_16_INVOCATIONS_PER_PIXEL_NV); }
        else if (std::strncmp(nodeVal, "no_invocations", 14) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_NO_INVOCATIONS_NV); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_FRAGMENT_SHADING_RATE_MAX_ENUM_NV); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkFragmentShadingRateNV>(e);
}


static inline ::VkBuildAccelerationStructureModeKHR hu::val<::VkBuildAccelerationStructureModeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkBuildAccelerationStructureModeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "build", 5) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_MODE_BUILD_KHR); }
        else if (std::strncmp(nodeVal, "update", 6) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_MODE_UPDATE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_BUILD_ACCELERATION_STRUCTURE_MODE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkBuildAccelerationStructureModeKHR>(e);
}


static inline ::VkAccelerationStructureBuildTypeKHR hu::val<::VkAccelerationStructureBuildTypeKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccelerationStructureBuildTypeKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "host", 4) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_KHR); }
        else if (std::strncmp(nodeVal, "device", 6) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_BUILD_TYPE_DEVICE_KHR); }
        else if (std::strncmp(nodeVal, "host_or_device", 14) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_BUILD_TYPE_HOST_OR_DEVICE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_BUILD_TYPE_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccelerationStructureBuildTypeKHR>(e);
}


static inline ::VkAccelerationStructureCompatibilityKHR hu::val<::VkAccelerationStructureCompatibilityKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccelerationStructureCompatibilityKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "compatible", 10) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_COMPATIBILITY_COMPATIBLE_KHR); }
        else if (std::strncmp(nodeVal, "incompatible", 12) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_COMPATIBILITY_INCOMPATIBLE_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_COMPATIBILITY_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccelerationStructureCompatibilityKHR>(e);
}


static inline ::VkAccelerationStructureCreateFlagBitsKHR hu::val<::VkAccelerationStructureCreateFlagBitsKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkAccelerationStructureCreateFlagBitsKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "device_address_capture_replay_bit", 33) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_CREATE_DEVICE_ADDRESS_CAPTURE_REPLAY_BIT_KHR); }
        else if (std::strncmp(nodeVal, "flag_bits_max_enum", 18) == 0) { e |= static_cast<enumIntType>(VK_ACCELERATION_STRUCTURE_CREATE_FLAG_BITS_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkAccelerationStructureCreateFlagBitsKHR>(e);
}


static inline ::VkShaderGroupShaderKHR hu::val<::VkShaderGroupShaderKHR>::extract(hu::Node node) noexcet
{
    auto nodeVal = node.value().str().data();
    using enumIntType = std::underlying_type<::VkShaderGroupShaderKHR>::type;
    enumIntType e = 0;
    bool fromList = node.kind() == hu::NodeKind::list;
    if (fromList)
        { node = node.firstChild(); }
    while(node)
    {
        if      (std::strncmp(nodeVal, "general", 7) == 0) { e |= static_cast<enumIntType>(VK_SHADER_GROUP_SHADER_GENERAL_KHR); }
        else if (std::strncmp(nodeVal, "closest_hit", 11) == 0) { e |= static_cast<enumIntType>(VK_SHADER_GROUP_SHADER_CLOSEST_HIT_KHR); }
        else if (std::strncmp(nodeVal, "any_hit", 7) == 0) { e |= static_cast<enumIntType>(VK_SHADER_GROUP_SHADER_ANY_HIT_KHR); }
        else if (std::strncmp(nodeVal, "intersection", 12) == 0) { e |= static_cast<enumIntType>(VK_SHADER_GROUP_SHADER_INTERSECTION_KHR); }
        else if (std::strncmp(nodeVal, "max_enum", 8) == 0) { e |= static_cast<enumIntType>(VK_SHADER_GROUP_SHADER_MAX_ENUM_KHR); }
        if (fromList)
            { node = node.nextSibling(); }
        else
            { break; }
    }
    return static_cast<::VkShaderGroupShaderKHR>(e);
}