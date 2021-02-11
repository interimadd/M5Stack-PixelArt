cmake_minimum_required(VERSION 2.6)
project(m5stack-pixelart-test)

add_subdirectory(lib/googletest/googletest)
add_executable(m5stack-pixelart-test test_main.cpp pixel_art_test.cpp lcd_mock_test.cpp ../mock/lcd_controller_mock.cpp)
target_link_libraries(m5stack-pixelart-test gtest_main)