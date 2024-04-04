cmake_minimum_required(VERSION 3.27)
project(CSE165FinalProj)

set(CMAKE_CXX_STANDARD 23)

add_executable(CSE165FinalProj main.cpp)

target_link_libraries(CSE165FinalProj
        ${CMAKE_SOURCE_DIR}/freeglut/lib/x64/freeglut.lib
        opengl32
)

add_custom_command(TARGET CSE165FinalProj POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${CMAKE_SOURCE_DIR}/freeglut/bin/x64/freeglut.dll
        $<TARGET_FILE_DIR:CSE165FinalProj>
)