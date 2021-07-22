add_compile_definitions(API_EXPORTS)

add_library(PluginB SHARED PluginB.cpp)

target_include_directories(PluginB
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
