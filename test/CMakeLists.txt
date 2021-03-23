cmake_minimum_required(VERSION 2.6)
project(m5stack-pixelart-test)

add_subdirectory(lib/googletest/googletest)
add_executable(m5stack-pixelart-test test_main.cpp
               pixel_art_test.cpp
               pixel_art_manager_test.cpp
               lcd_mock_test.cpp
               fake_button_service_test.cpp
               pixel_art_m5stack_test.cpp
               ../mock/lcd_controller_mock.cpp
               ../mock/fake_button_service.cpp
               ../pixel_art_m5stack/src/pixel_art.cpp
               ../pixel_art_m5stack/src/pixel_art_manager.cpp
               ../pixel_art_m5stack/entrypoint.cpp)
target_link_libraries(m5stack-pixelart-test gtest_main)