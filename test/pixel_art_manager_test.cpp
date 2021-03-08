#include "gtest/gtest.h"
#include "../src/pixel_art.h"
#include "../src/pixel_art_manager.h"
#include "../src/lcd_controller.h"



namespace {
  class TestPixelArtManager : public ::testing::Test
  {
    protected:
      LCDController *lcd;
      PixelArtManager *mng;
      LCDController *lcd_small;
      PixelArtManager *mng_small;
      void SetUp(){
        const int kLCDHorizontalPixelNum = 6;
        const int kLCDVerticalPixelNum = 4;
        lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
        mng = new PixelArtManager(lcd);
        lcd_small = new LCDController(1, 1);
        mng_small = new PixelArtManager(lcd_small);
      }
      void TearDown(){}
  };

  TEST_F(TestPixelArtManager, InitPixelArtManager)
  {
    LCDState expect = {
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0}
    };
    EXPECT_EQ(expect, lcd->getState());
  }

  TEST_F(TestPixelArtManager, DrawSinglePixelArt)
  {
    MonochromePixelArt frame_one = {{1}};
    mng_small->drawPixelArt({{1}}, 0, 0, 1);

  }

  TEST_F(TestPixelArtManager, DrawPixelArt)
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

  TEST_F(TestPixelArtManager, DrawDoubleScalePixelArt)
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

  TEST_F(TestPixelArtManager, DrawOverSizePixelArt)
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

  TEST_F(TestPixelArtManager, DrawNullPixelFrameDoNotChangeLCD)
  {
    OperationType no_op = OperationType::NO_OPERATION;
    mng_small->drawNextFrame(no_op);
    LCDState expect = {{0}};
    EXPECT_EQ(expect, lcd_small->getState());
  }

  TEST_F(TestPixelArtManager, AddOnePixelArtWithFrame)
  {
    MonochromePixelArt frame_zero = {{1}};
    MonochromePixelArt frame_one = {{0}};
    MonochromePixelArtWithFrame *pixel_with_frame = new MonochromePixelArtWithFrame({frame_zero, frame_one});
    mng_small->addPixelArtWithFrame(*pixel_with_frame);

    OperationType no_op = OperationType::NO_OPERATION;
    mng_small->drawNextFrame(no_op);
    EXPECT_EQ(frame_zero, lcd_small->getState());
    mng_small->drawNextFrame(no_op);
    EXPECT_EQ(frame_one, lcd_small->getState());
  }

  TEST_F(TestPixelArtManager, AddTwoPixelArtWithFrame)
  {
    MonochromePixelArt frame_zero = {{0}};
    MonochromePixelArt frame_one = {{1}};
    MonochromePixelArtWithFrame *pixel_with_frame_zero = new MonochromePixelArtWithFrame({frame_zero});
    MonochromePixelArtWithFrame *pixel_with_frame_one = new MonochromePixelArtWithFrame({frame_one});
    mng_small->addPixelArtWithFrame(*pixel_with_frame_zero);
    mng_small->addPixelArtWithFrame(*pixel_with_frame_one);

    OperationType next_op = OperationType::NEXT_BUTTON;
    mng_small->drawNextFrame(next_op);
    EXPECT_EQ(frame_one, lcd_small->getState());
    mng_small->drawNextFrame(next_op);
    EXPECT_EQ(frame_zero, lcd_small->getState());
    mng_small->drawNextFrame(next_op);
    EXPECT_EQ(frame_one, lcd_small->getState());
  }
} // namespace
