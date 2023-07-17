#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <thread>

class Engine {
protected:
    bool engineStarted;  // Indicates whether the engine is started or not
    int temperature;  // The current temperature of the engine
    std::thread temperatureThread;  // Thread to increase the engine temperature

public:
    Engine();  // Default constructor
    ~Engine();  // Destructor added

    void startEngine();  // Starts the engine
    void stopEngine();  // Stops the engine
    void increaseTemperature();  // Increases the engine temperature
    void startTemperatureIncrease();  // Starts the thread to continuously increase the engine temperature
    int getEngineTemp();  // Retrieves the current engine temperature
    bool getEngineStatus();  // Retrieves the engine status (started or stopped)
};

#endif
