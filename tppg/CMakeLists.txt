cmake_minimum_required(VERSION 3.5)

project(tppg VERSION 1.0.0)


set(OpenGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED)

add_executable(${PROJECT_NAME}
    utils/configs.cpp
    utils/configs.hpp
    utils/info.cpp
    utils/info.hpp
    utils/input_parser.cpp
    utils/input_parser.hpp  
    utils/logger.cpp
    utils/logger.hpp
    graphics/glfw/glfw_utils.cpp
    graphics/glfw/glfw_utils.hpp
    graphics/imgui/imgui_base.hpp
    graphics/imgui/imgui_gl.hpp
    graphics/imgui/imgui_vk.hpp
    graphics/main_window.cpp
    graphics/main_window.hpp
    main.cpp
    tpp.cpp
    tpp.hpp
    )


target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} glfw tppcore imgui implot)

include_directories(
    .
    ../core 
    ../third/glfw/include
    ../third/imgui/
    ../third/implot/)