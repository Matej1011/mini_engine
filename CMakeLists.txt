cmake_minimum_required(VERSION 3.6)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(MiniEngine)

option(PLATFORM_WINDOWS "Build for windows?" ON)

if(PLATFORM_WINDOWS)
    list(APPEND COMPILE_DEFS "PLATFORM_WINDOWS")
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/src/Platforms/Windows")
    list(APPEND SOURCE_FILES src/platforms/Windows/WindowsWindow.cpp src/platforms/Windows/WindowsWindow.h)
    list(APPEND EXTRA_LIBS gdi32 user32)
else()
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}src/Platforms/Linux")
    list(APPEND SOURCE_FILES src/platforms/Windows/LinuxWindow.cpp src/platforms/Windows/LinuxWindow.h)
    list(APPEND EXTRA_LIBS X11)
endif()

list(APPEND SOURCE_FILES src/core/engine.cpp src/core/engine.h src/core/entry_point.cpp src/core/mini_window.h src/core/time.h)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
target_compile_definitions(${PROJECT_NAME} PUBLIC ${COMPILE_DEFS} PUBLIC PROJECT_DIR="${PROJECT_SOURCE_DIR}")
target_include_directories(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})