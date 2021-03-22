#include "gtest/gtest.h"
#include "../pixel_art_m5stack/std_arduino.hpp"


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
    LCDState expect(240, std::vector<uint8_t>(320));
    EXPECT_EQ(expect, lcd->getState());
  }
} // namespace
