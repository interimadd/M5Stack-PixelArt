#include "gtest/gtest.h"
#include "../pixel_art_m5stack/std_arduino.hpp"

int LCD_HORIZONTAL_PIXEL_NUM = 320;
int LCD_VERTICAL_PIXEL_NUM = 240;


namespace {
  class TestPixelArtM5stack : public ::testing::Test
  {
    protected:
      virtual void SetUp(){}
      virtual void TearDown(){}
  };

  TEST_F(TestPixelArtM5stack, Init)
  {
    setup();
    LCDState expect(LCD_VERTICAL_PIXEL_NUM, std::vector<uint8_t>(LCD_HORIZONTAL_PIXEL_NUM));
    EXPECT_EQ(expect, lcd->getState());
  }
} // namespace
