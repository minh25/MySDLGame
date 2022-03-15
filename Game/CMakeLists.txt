add_executable(game src/app.cpp)

target_link_libraries(game 
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-x86_64-w64-mingw32/bin/SDL2.dll
)

target_include_directories(game
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-x86_64-w64-mingw32/include
)