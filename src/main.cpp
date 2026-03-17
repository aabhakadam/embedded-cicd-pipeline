#include <iostream>
#include "sensor.h"

int main() {
    AirQualitySensor sensor;

    auto reading = sensor.read(320.0f, 15.0f, 22.5f);
    std::cout << "Reading valid: " << reading.is_valid << "\n";
    std::cout << "Classification: " << sensor.classify(reading.co_ppm) << "\n";
    std::cout << "Is hazardous: " << sensor.isHazardous(reading.co_ppm) << "\n";

    float calibrated = sensor.calibrate(100.0f, 5.0f, 1.1f);
    std::cout << "Calibrated value: " << calibrated << "\n";

    return 0;
}
