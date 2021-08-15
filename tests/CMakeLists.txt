# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
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
gtest_discover_tests(test_plugin_manager)
