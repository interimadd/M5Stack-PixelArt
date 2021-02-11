#include "gtest/gtest.h"
#include "../src/lcd_controller.h"


namespace {
  class TestLCDMock : public ::testing::Test
  {
    virtual void SetUp(){}
    virtual void TearDown(){}
  };

  TEST_F(TestLCDMock, LCDisWhiteWhenInitilize)
  {
    int kLCDHorizontalPixelNum = 3;
    int kLCDVerticalPixelNum = 2;
    LCDController *lcd = new LCDController(kLCDHorizontalPixelNum, kLCDVerticalPixelNum);
    LCDState expect_state = {
      {0, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect_state, lcd->getState());
  }
} // namespace
