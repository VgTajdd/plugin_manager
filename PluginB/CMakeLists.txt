add_compile_definitions(API_EXPORTS)

add_library(pluginB SHARED PluginB.cpp)

target_include_directories(pluginB
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
