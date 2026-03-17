#include "sensor.h"

AirQualitySensor::Reading AirQualitySensor::read(
    float co, float pm25, float temp) {
    return {
        .co_ppm = co,
        .pm25 = pm25,
        .temperature = temp,
        .is_valid = (co >= 0 && pm25 >= 0 && temp > -40)
    };
}

std::string AirQualitySensor::classify(float co_ppm) {
    if (co_ppm > 400) return "HAZARDOUS";
    if (co_ppm > 250) return "ELEVATED";
    return "NORMAL";
}

bool AirQualitySensor::isHazardous(float co_ppm, float threshold) {
    return co_ppm > threshold;
}

float AirQualitySensor::calibrate(
    float raw, float offset, float gain) {
    return (raw + offset) * gain;
}
