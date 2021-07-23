add_executable(app main.cpp)

target_include_directories(app
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/plugin_manager/include"
    PRIVATE "${PROJECT_SOURCE_DIR}/lib/common/include"
)

# if(UNIX)
# set_target_properties(app
#     PROPERTIES
#     ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#     LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
#     RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
# )
# endif(UNIX)
