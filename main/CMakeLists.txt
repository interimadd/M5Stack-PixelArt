cmake_minimum_required(VERSION 2.6)
project(console-pixelart)

add_executable(console-pixelart main.cpp
               ../mock/lcd_controller_mock.cpp
               ../pixel_art_m5stack/entrypoint.cpp
               ../pixel_art_m5stack/pixel_art_data.cpp
               ../pixel_art_m5stack/src/pixel_art.cpp
               ../pixel_art_m5stack/src/pixel_art_manager.cpp)
target_link_libraries(console-pixelart)