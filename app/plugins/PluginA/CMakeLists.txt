add_compile_definitions(API_EXPORTS)

add_library(pluginA SHARED PluginA.cpp)

target_include_directories(pluginA
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/app/include"
)
