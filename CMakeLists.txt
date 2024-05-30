cmake_minimum_required(VERSION 3.16.0)
project(PM VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

# Same output directory for all targets.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src)
add_subdirectory(lib/plugin_manager)

target_link_libraries(app PRIVATE PluginManager)

if(UNIX)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
    target_link_libraries(PluginManager ${CMAKE_DL_LIBS})
endif(UNIX)

# Plugins.
add_subdirectory(PluginA)
add_subdirectory(PluginB)

# Tests.
enable_testing()
add_subdirectory(tests EXCLUDE_FROM_ALL)
