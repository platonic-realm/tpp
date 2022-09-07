cmake_minimum_required(VERSION 3.5)

add_library(implot STATIC
implot_demo.cpp
implot_internal.h
implot_items.cpp
implot.cpp
implot.h)

target_link_libraries(implot imgui)

include_directories(
    ../imgui/)