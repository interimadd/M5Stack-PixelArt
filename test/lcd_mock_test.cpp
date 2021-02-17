#include "gtest/gtest.h"
#include "../src/lcd_controller.h"


namespace {
  class TestLCDMock : public ::testing::Test
  {
    protected:
      LCDController *lcd;
      void SetUp(){
        const int kLCDHorizontalPixelNum = 3;
        const int kLCDVerticalPixelNum = 2;
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
    int v_pos = 0, h_pos = 1;
    int v_len = 2, h_len = 1;
    lcd->fillRect(v_pos, h_pos, v_len, h_len, 1);
    LCDState expect_state = {
      {0, 1, 0},
      {0, 1, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, FillRectBlackAll)
  {
    int v_pos = 0, h_pos = 0;
    int v_len = 2, h_len = 3;
    lcd->fillRect(v_pos, h_pos, v_len, h_len, 1);
    LCDState expect_state = {
      {1, 1, 1},
      {1, 1, 1}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, FillRectBlackOverSize)
  {
    int v_pos = 0, h_pos = 0;
    int v_len = 100, h_len = 100;
    lcd->fillRect(v_pos, h_pos, v_len, h_len, 1);
    LCDState expect_state = {
      {1, 1, 1},
      {1, 1, 1}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, DrawDot)
  {
    int dot_size = 1;
    int dot_color = 1;
    lcd->fillRect(0, 0, dot_size, dot_size, dot_color);
    lcd->fillRect(1, 2, dot_size, dot_size, dot_color);
    LCDState expect_state = {
      {1, 0, 0},
      {0, 0, 1}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }

  TEST_F(TestLCDMock, DrawDotAtUnderLimit)
  {
    int dot_size = 1;
    int dot_color = 1;
    lcd->fillRect(-1, -1, dot_size, dot_size, dot_color);
    LCDState expect_state = {
      {0, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }
} // namespace
