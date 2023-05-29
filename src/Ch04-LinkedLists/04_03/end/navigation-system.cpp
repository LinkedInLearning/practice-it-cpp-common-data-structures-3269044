#include <iostream>
#include <list>
using namespace std;

class Route
{
private:
    list<string> stops;
    list<string>::iterator current;

public:
    // Constructor
    Route()
    {
        current = stops.end();
    }

    // Add a new stop to the route
    void addStop(const string &stop)
    {
        stops.push_back(stop);
        if (current == stops.end())
        {
            current = stops.begin();
        }
    }

    // Advance to the next stop on the route
    void nextStop()
    {
        if (!stops.empty())
        {
            ++current;
            if (current == stops.end())
            {
                current = stops.begin();
            }
        }
    }

    // Go back to the previous stop on the route
    void prevStop()
    {
        if (!stops.empty())
        {
            if (current == stops.begin())
            {
                current = stops.end();
            }
            --current;
        }
    }

    // Display the current stop on the route
    void currentStop()
    {
        if (!stops.empty())
        {
            cout << "Current stop: " << *current << endl;
        }
        else
        {
            cout << "No stops in the route" << endl;
        }
    }
};

int main()
{
    Route route;

    route.addStop("Los Angeles");    
    route.addStop("Las Vegas");
    route.addStop("Salt Lake City");
    route.addStop("Denver");

    route.currentStop(); // "Current stop: Los Angeles"
    route.nextStop();
    route.currentStop(); // "Current stop: Las Vegas"
    route.nextStop();
    route.currentStop(); // "Current stop: Salt Lake City"
    route.nextStop();
    route.currentStop(); // "Current stop: Denver"
    route.prevStop();
    route.currentStop(); // "Current stop: Salt Lake City"

    return 0;
}