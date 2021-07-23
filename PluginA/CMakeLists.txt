add_compile_definitions(API_EXPORTS)

add_library(pluginA SHARED PluginA.cpp)

target_include_directories(pluginA
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)

if(UNIX)
    set_target_properties(pluginA
        PROPERTIES
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    )
endif(UNIX)
