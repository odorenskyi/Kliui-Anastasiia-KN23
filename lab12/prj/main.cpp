#include <iostream>
#include <chrono>
#include <thread>
#include <filesystem>
#include <vector>
#include <fstream>
#include <cmath>
#include <limits>

#include "ModulesKlui.h"

#define BEEP_COUNT 100
#define BEEP_REPEAT_DELAY 500
const std::vector<std::filesystem::path> expectedSourceFilePath {"lab12", "prj", "main.cpp"};
const auto sourceFilePath = std::filesystem::path(__FILE__);
const auto testResultsFilePath = sourceFilePath.parent_path().parent_path() / "TestSuite" / "TestResult.txt";
#define ERROR_MESSAGE "Встановлені вимоги порядку виконання лабораторної роботи порушено!"

void playBeepSounds(unsigned int count,
                    unsigned int repeatDelay = BEEP_REPEAT_DELAY) {
    for(auto n = 0; n < count; n++) {
        std::cout << "beep " << n + 1 << '\a' << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(repeatDelay));
    }
}

bool checkRequirements() {
    auto sourceFilePath = std::filesystem::path(__FILE__);
    auto pathElements = std::vector(sourceFilePath.begin(), sourceFilePath.end());
    if(pathElements.size() >= 3) {
        pathElements.erase(pathElements.begin(), pathElements.end() - 3);
    }
    
    return pathElements == expectedSourceFilePath;
}

auto openResultFile() {
    auto stream = std::ofstream(testResultsFilePath);
    if(!stream.is_open()) {
        std::cerr << "cannot open " << testResultsFilePath.filename() << std::endl;
        exit(-1);
    }
    return stream;
}

bool doUnitTestCase(float radius,
                    float height,
                    float expectedVolume) {
    auto object = new ClassLab12_Klui();
    
    object->setRadius(radius);
    object->setHeight(height);
    
    auto actualVolume = object->calculateVolume();
    delete object;
    
    return std::fabs(actualVolume - expectedVolume) < std::numeric_limits<float>::epsilon();
}

void doUnitTestCase(std::ostream &stream,
                    unsigned int number,
                    float radius,
                    float height,
                    float expectedVolume) {
    stream << "Test Case " << number << ": ";
    if(doUnitTestCase(radius, height, expectedVolume)) {
        stream << "passed";
    } else {
        stream << "failed";
    }
    stream << std::endl;
}

void doUnitTesting() {
    auto stream = openResultFile();
    
    doUnitTestCase(stream, 1, 10.0f, 11.5f, 100.0f);
    doUnitTestCase(stream, 2, 10.0f, 11.5f, 100.0f);
    doUnitTestCase(stream, 3, 10.0f, 11.5f, 100.0f);

    stream.close();
}

void handleFailedRequirements() {
    auto stream = openResultFile();

    stream << ERROR_MESSAGE;
    stream.close();
}

int main() {
    playBeepSounds(BEEP_COUNT);
    if(checkRequirements()) {
        doUnitTesting();
    } else {
        handleFailedRequirements();
    }
    
    return 0;
}
