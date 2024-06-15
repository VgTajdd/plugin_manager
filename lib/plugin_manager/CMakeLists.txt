add_compile_definitions(API_EXPORTS)

add_library(plugin_manager SHARED src/PluginManager.cpp)

target_include_directories(plugin_manager
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/src"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
