#include "gtest/gtest.h"


namespace {
  class PixelArtTest : public ::testing::Test
  {
    virtual void SetUp(){}
    virtual void TearDown(){}
  };

  TEST_F(PixelArtTest, FirstTest)
  {
    EXPECT_EQ(0, 0);
  }
} // namespace
