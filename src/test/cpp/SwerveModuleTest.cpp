#include <gtest/gtest.h>

#include "swerve/src/include/SwerveModule.h"

class SwerveTrainTest : public testing::Test {

    protected:
        SwerveModule* sm = new SwerveModule(0, 1);
};

TEST_F(SwerveTrainTest, SingleNicFromPosition) {

    EXPECT_DOUBLE_EQ(R_nicsConstant * 3.0 / 4.0, sm->SingleNic(-R_nicsConstant * 10 - R_nicsConstant * 1.0 / 4.0));
    EXPECT_DOUBLE_EQ(R_nicsConstant * 3.0 / 4.0, sm->SingleNic(R_nicsConstant * 3.0 / 4.0));
    EXPECT_DOUBLE_EQ(R_nicsConstant * 1.0 / 4.0, sm->SingleNic(R_nicsConstant * 10 + R_nicsConstant * 1.0 / 4.0));
}