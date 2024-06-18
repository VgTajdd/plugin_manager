add_executable(app src/main.cpp)

target_include_directories(app
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/app/include"
)

# Plugins.
add_subdirectory(plugins/PluginA)
add_subdirectory(plugins/PluginB)
