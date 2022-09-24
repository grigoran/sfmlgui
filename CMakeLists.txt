cmake_minimum_required(VERSION 3.24)
project(gui)

set(CMAKE_DEBUG_POSTFIX d)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
find_package(SFML 2.5 COMPONENTS graphics)
include_directories("./headers")
set(SOURCE gui.cpp uielement.cpp button.cpp list.cpp main.cpp) #coment when build like a library
add_executable(gui ${SOURCE})                                  #coment when build like a library
#set(SOURCE gui.cpp uielement.cpp button.cpp list.cpp)         #uncomment when build like a library
#add_library(gui ${SOURCE})                                    #uncomment when build like a library
set_target_properties(gui PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})
target_link_libraries(gui sfml-graphics)

#target_include_directories(gui PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers/)