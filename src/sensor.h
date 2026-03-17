#pragma once
#include <string>

class AirQualitySensor {
public:
    struct Reading {
        float co_ppm;
        float pm25;
        float temperature;
        bool is_valid;
    };

    Reading read(float co, float pm25, float temp);
    std::string classify(float co_ppm);
    bool isHazardous(float co_ppm, float threshold = 300.0f);
    float calibrate(float raw_value, float offset, float gain);
};
