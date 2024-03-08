cmake_minimum_required(VERSION 3.15)
project(devmonitor_lvgl_rpi)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})


include_directories(${PROJECT_SOURCE_DIR}/inc)
include_directories(${PROJECT_SOURCE_DIR}/lvgl)
include_directories(${PROJECT_SOURCE_DIR}/lvgl/src)
include_directories(${PROJECT_SOURCE_DIR}/guiguider)
include_directories(${PROJECT_SOURCE_DIR})
file(GLOB SRC ${PROJECT_SOURCE_DIR}/src/*.c)
file(GLOB SRC_LVGL ${PROJECT_SOURCE_DIR}/lvgl/*.c)
# file(GLOB_RECURSE SRC_LVGL_DEMO ${PROJECT_SOURCE_DIR}/lvgl/demos/*.c)
file(GLOB_RECURSE SRC_LVGL_GUIGUIDER ${PROJECT_SOURCE_DIR}/guiguider/*.c)

add_compile_options(-g -c)

add_subdirectory(lvgl)
add_executable(${PROJECT_NAME} ${SRC} ${SRC_LVGL} ${SRC_LVGL_DEMO} ${SRC_LVGL_GUIGUIDER})
target_link_libraries(${PROJECT_NAME} lvgl pthread wiringPi)
