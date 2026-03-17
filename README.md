# Embedded CI/CD Pipeline

![CI](https://github.com/aabhakadam/embedded-cicd-pipeline/actions/workflows/ci.yml/badge.svg)

Automated build, unit test, and static analysis pipeline for embedded air quality sensor software.

## Tech Stack
- **Language**: C++17
- **Build System**: CMake 3.14+
- **Testing**: GoogleTest (6 unit tests)
- **Static Analysis**: cppcheck
- **Containerisation**: Docker (Ubuntu 22.04)
- **CI/CD**: GitHub Actions

## Pipeline Stages
1. Install dependencies
2. Configure and build with CMake
3. Run 6 GoogleTest unit tests
4. Run CTest
5. Build Docker image
6. Run tests inside Docker container
7. Static analysis with cppcheck

## Build Locally
```bash
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --parallel
./build/run_tests
```

## CV Line
Embedded CI/CD Pipeline — C++17, CMake, GoogleTest, Docker, GitHub Actions. Automated build, unit test, and static analysis pipeline for embedded air quality sensor software; pipeline executes on every push.
