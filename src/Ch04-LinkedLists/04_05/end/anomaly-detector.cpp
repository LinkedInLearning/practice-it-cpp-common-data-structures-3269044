#include <iostream>
#include <list>
using namespace std;

class SensorData
{
private:
    list<double> readings;

public:
    // Add a new sensor reading to the list
    void addReading(double value)
    {
        readings.push_back(value);
    }

    // Go through the list and replace any spike or dip with the previous reading
    void smoothData()
    {
        if (readings.size() < 3)
        {
            return;
        }

        auto prev = readings.begin();
        auto current = prev;
        ++current;
        auto next = current;
        ++next;

        while (next != readings.end())
        {
            double average = (*prev + *next) / 2;
            if (*current >= 2 * average || *current <= 0.5 * average)
            {
                *current = average;
            }
            ++prev;
            ++current;
            ++next;
        }
    }

    // Print all sensor readings
    void printData()
    {
        for (const auto &reading : readings)
        {
            cout << reading << " ";
        }
        cout << "\n";
    }
};

int main()
{
    SensorData sensorData;

    sensorData.addReading(10.0);
    sensorData.addReading(20.0); // A spike
    sensorData.addReading(5.0);
    sensorData.addReading(2.0); // A dip
    sensorData.addReading(7.0);

    sensorData.printData(); // "10 20 5 2 7"
    sensorData.smoothData();
    sensorData.printData(); // "10 10 5 5 7"

    return 0;
}
