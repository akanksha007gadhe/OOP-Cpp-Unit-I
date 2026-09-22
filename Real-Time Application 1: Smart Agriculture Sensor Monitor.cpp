#include <iostream>
#include <string>
#include <vector>
using namespace std;

class SoilSensor {
private:
    string sensorId;
    double moistureLevel;
    string timestamp;

public:
    SoilSensor(string id, double moisture, string time)
        : sensorId(id), moistureLevel(moisture), timestamp(time) {}

    void readSensor(double newMoisture, string newTime) {
        moistureLevel = newMoisture;
        timestamp = newTime;
    }

    void displayData() const {
        cout << "Sensor: " << sensorId
             << " | Moisture: " << moistureLevel << "%"
             << " | Time: " << timestamp << endl;
    }
};

int main() {
    vector<SoilSensor> farmSensors;

    farmSensors.emplace_back("S101", 42.6, "07:30");
    farmSensors.emplace_back("S102", 56.3, "07:30");
    farmSensors.emplace_back("S103", 35.9, "07:30");

    cout << "=== Morning Sensor Readings ===" << endl;

    for (const auto& sensor : farmSensors) {
        sensor.displayData();
    }

    farmSensors[0].readSensor(49.2, "08:30");

    cout << "\n=== Updated Reading ===" << endl;
    farmSensors[0].displayData();
}
