add_library(tetris STATIC
        tetris_game.cpp
        piece.cpp
        pieces.cpp
        tileset.cpp
)

target_link_libraries(tetris
        ${CMAKE_SOURCE_DIR}/freeglut/lib/x64/libfreeglut.a
        opengl32
)

target_include_directories(tetris PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})