#include "gtest/gtest.h"
#include "../src/button_service.h"
#include "../mock/fake_button_service.h"


namespace {
  class TestButtonService : public ::testing::Test
  {
    protected:
      virtual void SetUp(){}
      virtual void TearDown(){}
  };

  TEST_F(TestButtonService, Create)
  {
    EXPECT_EQ(OperationType::NO_OPERATION, getButtonOperation());
  }

  TEST_F(TestButtonService, Set)
  {
    setButtonoperation(OperationType::NEXT_BUTTON);
    EXPECT_EQ(OperationType::NEXT_BUTTON, getButtonOperation());
  }
} // namespace
