add_library(tetris STATIC
        game.cpp
        piece.cpp
        pieces.cpp
)
target_include_directories(tetris PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})