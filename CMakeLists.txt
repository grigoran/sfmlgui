cmake_minimum_required(VERSION 3.24)
project(sfmlui)

set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(SFML 2.5 COMPONENTS graphics)
include_directories("./headers")
set(SOURCE gui.cpp uielement.cpp button.cpp list.cpp main.cpp)
add_executable(app ${SOURCE})
set_target_properties(app PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(app sfml-graphics)