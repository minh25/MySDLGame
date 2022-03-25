add_executable(game 
    src/app.cpp
    src/sdl.cpp
)

find_package(SDL2 REQUIRED)

target_include_directories(game 
    PRIVATE ${SDL2_INCLUDE_DIRS}
)
target_link_libraries(game 
    PRIVATE ${SDL2_LIBRARIES}
)

# target_link_libraries(game 
#     PRIVATE ${CMAKE_SOURCE_DIR}/bin/SDL2.dll
# )

# target_include_directories(game
#     PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL2-x86_64-w64-mingw32/include
# )