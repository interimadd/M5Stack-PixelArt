#include "gtest/gtest.h"
#include "../src/pixel_art.h"


namespace {
  class TestPixelArt : public ::testing::Test
  {
    virtual void SetUp(){}
    virtual void TearDown(){}
  };

  TEST_F(TestPixelArt, CreatePixelArtObj)
  {
    MonochromePixelArt pixel_art = {
      {1, 0, 0},
      {0, 0, 1}
    };
    EXPECT_EQ(1, pixel_art[0][0]);
    EXPECT_EQ(0, pixel_art[1][1]);
  }
} // namespace
