#include <gtest/gtest.h>
#include "sensor.h"

class SensorTest : public ::testing::Test {
protected:
    AirQualitySensor sensor;
};

TEST_F(SensorTest, ClassifiesHazardousCorrectly) {
    EXPECT_EQ(sensor.classify(450.0f), "HAZARDOUS");
    EXPECT_EQ(sensor.classify(300.0f), "ELEVATED");
    EXPECT_EQ(sensor.classify(100.0f), "NORMAL");
}

TEST_F(SensorTest, DetectsHazardousLevel) {
    EXPECT_TRUE(sensor.isHazardous(400.0f, 300.0f));
    EXPECT_FALSE(sensor.isHazardous(200.0f, 300.0f));
}

TEST_F(SensorTest, ValidatesReadings) {
    auto valid = sensor.read(100.0f, 25.0f, 28.0f);
    EXPECT_TRUE(valid.is_valid);

    auto invalid = sensor.read(-1.0f, 25.0f, 28.0f);
    EXPECT_FALSE(invalid.is_valid);
}

TEST_F(SensorTest, CalibratesCorrectly) {
    float result = sensor.calibrate(100.0f, 5.0f, 1.1f);
    EXPECT_FLOAT_EQ(result, 115.5f);
}

TEST_F(SensorTest, BoundaryClassification) {
    EXPECT_EQ(sensor.classify(400.0f), "ELEVATED");
    EXPECT_EQ(sensor.classify(401.0f), "HAZARDOUS");
    EXPECT_EQ(sensor.classify(250.0f), "NORMAL");
    EXPECT_EQ(sensor.classify(251.0f), "ELEVATED");
}

TEST_F(SensorTest, RejectsExtremeTemperature) {
    auto reading = sensor.read(100.0f, 25.0f, -41.0f);
    EXPECT_FALSE(reading.is_valid);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
