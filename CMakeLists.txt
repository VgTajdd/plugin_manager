cmake_minimum_required(VERSION 3.20.0)
project(plugin_manager_project VERSION 1.1)

set(CMAKE_CXX_STANDARD 20)

option(PM_BUILD_EXAMPLES "Generate examples target" ON)
option(PM_BUILD_TESTS "Generate tests target" ON)

# Set output directory for executable targets.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin")

# Set output directory for library targets.
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if(UNIX)
    SET(CMAKE_SHARED_LIBRARY_SUFFIX ".so")
endif(UNIX)

add_subdirectory(lib/plugin_manager)

if(PM_BUILD_EXAMPLES)
    add_subdirectory(app)
    target_link_libraries(app PRIVATE plugin_manager)
endif()

# Tests.
if(PM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
