cmake_minimum_required(VERSION 3.24)
project(gui)

set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(SFML 2.5 COMPONENTS graphics)
include_directories("./headers")
set(SOURCE gui.cpp uielement.cpp button.cpp list.cpp Plot.cpp)
add_library(gui ${SOURCE})                                                           #uncomment when build like a library
set_target_properties(gui PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(gui sfml-graphics)

target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/) #uncomment when build like a library