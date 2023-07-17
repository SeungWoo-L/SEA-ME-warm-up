#include "Engine.hpp"
#include <iostream>
#include <chrono>

Engine::Engine() {
    engineStarted = false;
    temperature = 18;
}

Engine::~Engine(){
    if(engineStarted){
        stopEngine();
    }
}

void Engine::startEngine() {
    std::string answer;
    std::cout << "Would you like to start the engine? (y/n): ";
    std::cin >> answer;

    while (answer != "y" && answer != "Y" && answer != "n" && answer != "N") {
        std::cout << "Invalid input. Please enter a valid value (y/n): ";
        std::cin >> answer;
    }

    if (answer == "y" || answer == "Y") {
        int random = rand() % 10;  // 10% chance of engine failure
        if (random != 0) {  
            engineStarted = true;
            std::cout << "Engine Started" << std::endl;
            startTemperatureIncrease();  // Start the temperature increase thread
        } else {
            std::cout << "Engine Failed to Start. Try again." << std::endl;
            startEngine();
        }
    } else {
        std::cout << "Engine Not Started" << std::endl;
    }
}

void Engine::stopEngine() {
    engineStarted = false;
    temperature = 18;
    std::cout << "Engine Stopped" << std::endl;
}

void Engine::increaseTemperature() {
    if (engineStarted) {
        temperature += 10;

        if (temperature >= 400) {
            std::cout << "Engine is too hot! Engine is Automatically Shutdown" << std::endl;
            stopEngine();
            exit(0);
        }
    }
}

void Engine::startTemperatureIncrease() {
    temperatureThread = std::thread([&]() {
        while (engineStarted) {
            std::this_thread::sleep_for(std::chrono::seconds(5));
            increaseTemperature();
        }
    });
    temperatureThread.detach();
}

int Engine::getEngineTemp() {
    return temperature;
}

bool Engine::getEngineStatus(){
    return engineStarted;
}
