add_compile_definitions(API_EXPORTS)

add_library(PluginManager SHARED src/PluginManager.cpp)

target_include_directories(PluginManager
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/src"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
