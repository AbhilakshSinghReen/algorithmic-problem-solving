#include <chrono>
#include <string>
#include <vector>

class Timer {
  private:
    bool hasStarted;
    std::vector<std::chrono::high_resolution_clock::time_point> timestamps;
    std::vector<std::string> eventNames;

  public:
    Timer(bool autoStart = false);
    // Destructor not required, the vectors clean up themselves

    void start();
    void markEventCompleted(std::string eventName);
    std::vector<std::pair<std::string, std::chrono::duration<double, std::micro>>>
    getEventDurations();
    void printEventDurations();
};