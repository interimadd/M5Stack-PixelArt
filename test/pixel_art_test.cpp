#include "gtest/gtest.h"
#include "../src/pixel_art.h"
#include "../src/lcd_controller.h"



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

  TEST_F(TestPixelArt, InitPixelArtManager)
  {
    const int kLCDHorizontalPixelNum = 3;
    const int kLCDVerticalPixelNum = 2;
    LCDController *lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    PixelArtManager *mng = new PixelArtManager(lcd);

    MonochromePixelArt expect = {
      {0, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect, lcd->getState());
  }

  TEST_F(TestPixelArt, DrawPixelArt)
  {
    const int kLCDHorizontalPixelNum = 3;
    const int kLCDVerticalPixelNum = 2;
    LCDController *lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    PixelArtManager *mng = new PixelArtManager(lcd);

    int pos_x = 0, pos_y = 0, scale = 1;
    MonochromePixelArt pixel_art = {
      {1, 0, 0},
      {0, 0, 1}
    };
    mng->drawPixelArt(pixel_art, pos_x, pos_y, scale);

    EXPECT_EQ(pixel_art, lcd->getState());
  }

  TEST_F(TestPixelArt, DrawDoubleScalePixelArt)
  {
    const int kLCDHorizontalPixelNum = 6;
    const int kLCDVerticalPixelNum = 4;
    LCDController *lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    PixelArtManager *mng = new PixelArtManager(lcd);

    int pos_x = 1, pos_y = 0, scale = 2;
    MonochromePixelArt pixel_art = {
      {1, 0},
      {0, 1}
    };
    mng->drawPixelArt(pixel_art, pos_x, pos_y, scale);

    LCDState expect_state = {
      {0, 1, 1, 0, 0, 0},
      {0, 1, 1, 0, 0, 0},
      {0, 0, 0, 1, 1, 0},
      {0, 0, 0, 1, 1, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestPixelArt, DrawOverSizePixelArt)
  {
    const int kLCDHorizontalPixelNum = 6;
    const int kLCDVerticalPixelNum = 4;
    LCDController *lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    PixelArtManager *mng = new PixelArtManager(lcd);

    int pos_x = 1, pos_y = 0, scale = 3;
    MonochromePixelArt pixel_art = {
      {1, 0},
      {0, 1}
    };
    mng->drawPixelArt(pixel_art, pos_x, pos_y, scale);

    LCDState expect_state = {
      {0, 1, 1, 1, 0, 0},
      {0, 1, 1, 1, 0, 0},
      {0, 1, 1, 1, 0, 0},
      {0, 0, 0, 0, 1, 1}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }
} // namespace
