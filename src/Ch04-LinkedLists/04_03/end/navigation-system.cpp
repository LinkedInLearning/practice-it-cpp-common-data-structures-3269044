#include <iostream>
#include <list>
using namespace std;

class Route
{
private:
    list<string> stops;
    list<string>::iterator current;
public:
    Route()
    {
        current = stops.end();
    }

    // Add a new stop to the route
    void add_stop(const string &stop)
    {
        stops.push_back(stop);

        if (current == stops.end())
        {
            current = stops.begin();
        }
    }

    // Advance to the next stop on the route
    void next_stop()
    {
        if(!stops.empty())
        {
            ++current;
            if(current == stops.end())
            {
                current = stops.begin();
            }
        }
    }

    // Go back to the previous stop on the route
    void prev_stop()
    {
        if(!stops.empty())
        {
            if(current == stops.begin())
            {
                current = stops.end();
            }
            --current;
        }
    }

    // Display the current stop on the route
    void current_stop()
    {
        if(!stops.empty())
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

    route.add_stop("Los Angeles");
    route.add_stop("Las Vegas");
    route.add_stop("Salt Lake City");
    route.add_stop("Denver");

    route.current_stop(); // "Current stop: Los Angeles"
    route.next_stop();
    route.current_stop(); // "Current stop: Las Vegas"
    route.next_stop();
    route.current_stop(); // "Current stop: Salt Lake City"
    route.next_stop();
    route.current_stop(); // "Current stop: Denver"
    route.prev_stop();
    route.current_stop(); // "Current stop: Salt Lake City"

    return 0;
}