#include "gtest/gtest.h"
#include "../src/pixel_art.h"
#include "../src/lcd_controller.h"



namespace {
  class TestPixelArt : public ::testing::Test
  {
    protected:
      void SetUp(){}
      void TearDown(){}
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

  TEST_F(TestPixelArt, InitPixelArtWithFrame)
  {
    MonochromePixelArt frame_zero = {{0}};
    MonochromePixelArt frame_one = {{1}};
    MonochromePixelArtWithFrame *pixel_with_frame = new MonochromePixelArtWithFrame({frame_zero, frame_one});
    EXPECT_EQ(frame_zero, pixel_with_frame->getCurrentFramePixelArt());
  }

  TEST_F(TestPixelArt, MoveToNextPixelArtFrame)
  {
    MonochromePixelArt frame_zero = {{0}};
    MonochromePixelArt frame_one = {{1}};
    MonochromePixelArtWithFrame *pixel_with_frame = new MonochromePixelArtWithFrame({frame_zero, frame_one});
    EXPECT_EQ(frame_zero, pixel_with_frame->toNextFrame());
    EXPECT_EQ(frame_one, pixel_with_frame->toNextFrame());
    EXPECT_EQ(frame_zero, pixel_with_frame->toNextFrame());
  }
} // namespace
