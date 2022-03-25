add_executable(game 
    src/Main.cpp
    src/Window.cpp
    src/Surface.cpp
    src/SDLWrap.cpp
    src/Application.cpp
)

find_package(SDL2 REQUIRED)

target_include_directories(game 
    PRIVATE ${SDL2_INCLUDE_DIRS}
)
target_link_libraries(game 
    PRIVATE ${SDL2_LIBRARIES}
)