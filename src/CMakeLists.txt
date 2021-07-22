add_executable(app main.cpp)

target_include_directories(app
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)
