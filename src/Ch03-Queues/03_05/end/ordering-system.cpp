#include <iostream>
#include <queue>
using namespace std;

class MerchOrderSystem
{
private:
    queue<int> regularOrders;
    queue<int> priorityOrders;

public:
    // Function to place an order
    void place_order(int orderID, bool isPriority = false)
    {
        if (isPriority)
        {
            priorityOrders.push(orderID);
            cout << "Placed priority order with ID: " << orderID << endl;
        }
        else
        {
            regularOrders.push(orderID);
            cout << "Placed regular order with ID: " << orderID << endl;
        }        
    }

    // Function to fulfill an order
    int fulfill_order()
    {
        if (!priorityOrders.empty())
        {
            int orderID = priorityOrders.front();
            priorityOrders.pop();
            return orderID;
        }
        else if (!regularOrders.empty())
        {
            int orderID = regularOrders.front();
            regularOrders.pop();
            return orderID;
        }
        else
        {
            cout << "No orders to fulfill." << endl;
            return -1; // Return -1 if no orders in either queue
        }
    }
};

int main()
{
    MerchOrderSystem system; // Instantiate MerchOrderSystem object

    // Placing some orders
    system.place_order(201);       // Regular order
    system.place_order(202);       // Regular order
    system.place_order(101, true); // Priority order
    system.place_order(203);       // Regular order

    // Fulfilling all orders
    int orderID;
    while ((orderID = system.fulfill_order()) != -1)
    {
        cout << "Order with ID " << orderID << " has been fulfilled.\n";
    }

    return 0;
}