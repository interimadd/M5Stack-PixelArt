#include "gtest/gtest.h"
#include "../src/pixel_art.h"
#include "../src/lcd_controller.h"



namespace {
  class TestPixelArt : public ::testing::Test
  {
    protected:
      LCDController *lcd;
      PixelArtManager *mng;
      void SetUp(){
        const int kLCDHorizontalPixelNum = 6;
        const int kLCDVerticalPixelNum = 4;
        lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
        mng = new PixelArtManager(lcd);
      }
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

  TEST_F(TestPixelArt, InitPixelArtManager)
  {
    LCDState expect = {
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    };
    EXPECT_EQ(expect, lcd->getState());
  }

  TEST_F(TestPixelArt, DrawPixelArt)
  {
    int pos_x = 0, pos_y = 0, scale = 1;
    MonochromePixelArt pixel_art = {
      {1, 0, 0},
      {0, 0, 1}
    };
    mng->drawPixelArt(pixel_art, pos_x, pos_y, scale);
  
    LCDState expect = {
      {1, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    };
    EXPECT_EQ(expect, lcd->getState());
  }

  TEST_F(TestPixelArt, DrawDoubleScalePixelArt)
  {
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
