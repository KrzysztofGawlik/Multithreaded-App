cmake_minimum_required(VERSION 3.20)

project(MultithreadedApp)

# Main app components
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# SFML setup
include (FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)
FetchContent_MakeAvailable(SFML)

# Copy resources
file(GLOB RESOURCE_FILES "resources/*")
foreach(file ${RESOURCE_FILES})
    get_filename_component(filename ${file} NAME)
    configure_file(${file} ${CMAKE_BINARY_DIR}/resources/${filename} COPYONLY)
endforeach()

add_executable(${PROJECT_NAME} main.cpp ${SOURCES})

target_link_libraries(${PROJECT_NAME}
    sfml-graphics
    sfml-window
    sfml-system
)