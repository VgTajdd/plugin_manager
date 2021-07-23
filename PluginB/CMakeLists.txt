add_compile_definitions(API_EXPORTS)

add_library(pluginB SHARED PluginB.cpp)

target_include_directories(pluginB
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)

if(UNIX)
    set_target_properties(pluginB
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif(UNIX)
