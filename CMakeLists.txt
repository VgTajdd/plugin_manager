cmake_minimum_required(VERSION 3.16.0)
project(PM VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)

# Set output directory for executable targets.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")

# Set output directory for library targets.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_subdirectory(src)
add_subdirectory(lib/plugin_manager)

target_link_libraries(app PRIVATE plugin_manager)

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
