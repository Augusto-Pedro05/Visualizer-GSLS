cmake_minimum_required(VERSION 3.20)
    project(VisualizadorGLSL CXX C)
  
    set(CMAKE_CXX_STANDARD 20)
  
    include(FetchContent)
  
    # GLFW: o CMake baixa e compila junto com o projeto
    FetchContent_Declare(glfw
      GIT_REPOSITORY https://github.com/glfw/glfw.git
      GIT_TAG 3.4)
    set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_TESTS    OFF CACHE BOOL "" FORCE)
    set(GLFW_BUILD_DOCS     OFF CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(glfw)
  
    # glad: código gerado e guardado dentro do repositório
    add_library(glad external/glad/src/glad.c)
    target_include_directories(glad PUBLIC external/glad/include)
    
    add_executable(visualizador main.cpp)
    target_link_libraries(visualizador PRIVATE glfw glad)
    target_compile_options(visualizador PRIVATE -Wall -Wextra)