cmake_minimum_required(VERSION 3.14)

project(visualize C)
set(CMAKE_C_STANDARD 99)
include_directories(~/Library/Frameworks/SDL2.framework/Headers)
add_executable(visualize include/lem_in_viz.h src/main_viz.c)
target_link_libraries(visualize "-framework SDL2")
set_target_properties(visualize PROPERTIES LINK_FLAGS "-F /Users/$ENV{USER}/Library/Frameworks")