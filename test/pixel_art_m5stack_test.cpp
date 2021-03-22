#include "gtest/gtest.h"
#include "../pixel_art_m5stack/std_arduino.hpp"

int LCD_HORIZONTAL_PIXEL_NUM = 3;
int LCD_VERTICAL_PIXEL_NUM = 2;

std::vector<std::vector<MonochromePixelArt>> ALL_PIXEL_ARTS_LIST;
int PIXEL_ART_POS_X;
int PIXEL_ART_POS_Y;
int PIXEL_ART_SCALE;


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

  TEST_F(TestPixelArtM5stack, SetPixelArt)
  {
    ALL_PIXEL_ARTS_LIST = {
      {  {{1}},  {{2}}  }
    };
    PIXEL_ART_POS_X = 0;
    PIXEL_ART_POS_Y = 0;
    PIXEL_ART_SCALE = 1;
    setup();
    loop();
    MonochromePixelArt expect_loop1 = {
      {1, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect_loop1, lcd->getState());
    loop();
    MonochromePixelArt expect_loop2 = {
      {2, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect_loop2, lcd->getState());
  }

  TEST_F(TestPixelArtM5stack, SetPixelArtWithSizeAndScale)
  {
    ALL_PIXEL_ARTS_LIST = {
      {{{1}}}
    };
    PIXEL_ART_POS_X = 1;
    PIXEL_ART_POS_Y = 0;
    PIXEL_ART_SCALE = 2;
    setup();
    loop();
    MonochromePixelArt expect = {
      {0, 1, 1},
      {0, 1, 1}
    };
    EXPECT_EQ(expect, lcd->getState());
  }

  TEST_F(TestPixelArtM5stack, ButtonOperation)
  {
    ALL_PIXEL_ARTS_LIST = {
      {{{1}}}, {{{2}}}
    };
    PIXEL_ART_POS_X = 0;
    PIXEL_ART_POS_Y = 0;
    PIXEL_ART_SCALE = 1;
    setup();

    OperationType next_op = OperationType::NEXT_BUTTON;
    setButtonoperation(next_op);
    loop();
    MonochromePixelArt expect = {
      {2, 0, 0},
      {0, 0, 0}
    };
    EXPECT_EQ(expect, lcd->getState());
  }
} // namespace
