add_compile_definitions(API_EXPORTS)

add_library(PluginA SHARED PluginA.cpp)

target_include_directories(PluginA
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
