#include "gtest/gtest.h"
#include "../src/lcd_controller.h"


namespace {
  class TestLCDMock : public ::testing::Test
  {
    protected:
      LCDController *lcd;
      void SetUp(){
        int kLCDHorizontalPixelNum = 3;
        int kLCDVerticalPixelNum = 2;
        lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
      }
      virtual void TearDown(){}
  };

  TEST_F(TestLCDMock, LCDisWhiteWhenInitilize)
  {
    LCDState expect_state = {
      {0, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, FillRectBlack)
  {
    int x_pos = 0, y_pos = 0;
    int width = 2, height = 2;
    lcd->fillRect(x_pos, y_pos, width, height, 1);
    LCDState expect_state = {
      {1, 1, 0},
      {1, 1, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, FillRectBlackOverSize)
  {
    int x_pos = 0, y_pos = 0;
    int width = 100, height = 100;
    lcd->fillRect(x_pos, y_pos, width, height, 1);
    LCDState expect_state = {
      {1, 1, 1},
      {1, 1, 1}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }
} // namespace
