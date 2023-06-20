#include <iostream>
#include <list>
using namespace std;

class SensorData
{
private:
    list<double> readings;

public:
    // Add a new sensor reading to the list
    void add_reading(double value)
    {
        readings.push_back(value);
    }

    // Go through the list and replace any spike or dip with the previous reading
    void smooth_data()
    {
        if(readings.size() < 2)
        {
            return;
        }
        auto prev = readings.begin();
        auto current = prev;
        ++current;

        while(current != readings.end())
        {
            if(*current >= 2 * (*prev) || *current <= 0.5 * (*prev))
            {
                *current = *prev;
            }
            ++prev;
            ++current;
        }
    }

    // Print all sensor readings
    void print_data()
    {
        for(const auto &reading : readings)
        {
            cout << reading << " ";
        }
        cout << endl;
    }
};

int main()
{
    SensorData sensorData;
    sensorData.add_reading(10.0);
    sensorData.add_reading(24.0);   // spike
    sensorData.add_reading(6.0);
    sensorData.add_reading(2.0);    // dip
    sensorData.add_reading(4.0);

    cout << "Sensor data: ";
    sensorData.print_data();

    cout << "Normalized sensor data: ";
    sensorData.smooth_data();
    sensorData.print_data();

    return 0;
}