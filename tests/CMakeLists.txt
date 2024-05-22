# GoogleTest requires at least C++14
# set(CMAKE_CXX_STANDARD 14) # Uncomment this line if you are using an older version of C++.

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG f8d7d77 # release-1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(test_plugin_manager test.cpp)
target_link_libraries(test_plugin_manager gtest_main PluginManager)
target_include_directories(test_plugin_manager
  PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
  PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
)

include(GoogleTest)
gtest_discover_tests(test_plugin_manager WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
