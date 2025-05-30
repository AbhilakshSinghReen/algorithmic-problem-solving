#include <iostream>
#include <stdexcept>

#include "timer.h"

using namespace std;
using namespace chrono;

Timer::Timer(bool autoStart) {
    hasStarted = autoStart;

    if (autoStart) {
        start();
    }
}

void Timer::start() {
    high_resolution_clock::time_point startTime = high_resolution_clock::now();
    timestamps.push_back(startTime);
}

void Timer::markEventCompleted(string eventName) {
    if (!hasStarted) {
        throw runtime_error(
                "Timer object must be started before marking an event as completed. In order to do "
                "so, construct the object with 'autoStart=true' or call the 'start' method.");
    }

    high_resolution_clock::time_point timePoint = high_resolution_clock::now();
    timestamps.push_back(timePoint);
    eventNames.push_back(eventName);
}

vector<pair<string, duration<double, micro>>> Timer::getEventDurations() {
    vector<pair<string, duration<double, micro>>> eventDurations;

    int numEvents = eventDurations.size();
    for (int i = 0; i < numEvents; i++) {
        duration<double, micro> eventDuration = timestamps[i + 1] - timestamps[i];
        pair<string, duration<double, micro>> eventNameAndDuration =
                make_pair(eventNames[i], eventDuration);
        eventDurations.push_back(eventNameAndDuration);
    }

    return eventDurations;
}

void Timer::printEventDurations() {
    vector<pair<string, duration<double, micro>>> eventDurations = getEventDurations();

    int numEvents = eventDurations.size();
    for (int i = 0; i < numEvents; i++) {
        cout << eventDurations[i].first << ": " << eventDurations[i].second.count() << "us" << "\n";
    }
}
