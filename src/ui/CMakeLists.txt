add_library(ui STATIC
        window.cpp
        window.h
        graphic.h
        game.cpp
        game.h
)
target_link_libraries(ui
        ${CMAKE_SOURCE_DIR}/freeglut/lib/x64/libfreeglut.a
        opengl32
)
target_include_directories(ui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})