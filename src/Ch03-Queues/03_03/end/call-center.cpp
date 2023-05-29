#include <iostream>
#include <queue>
using namespace std;

class CallCenter
{
private:
    queue<int> callQueue; // Queue to hold the call IDs

public:
    // Function to enqueue a call
    void receive_call(const int id)
    {
        callQueue.push(id);
        cout << "Received call with ID: " << id << endl;
    }

    // Function to process a call
    int process_call()
    {
        // Check if there are calls in the queue
        if (callQueue.empty())
        {            
            cout << "No calls to process." << endl;
            return -1; // Return -1 if no calls
        }
        else
        {
            int call_id = callQueue.front(); // Get the call id at the front of the queue
            callQueue.pop();                 // Remove the call from the queue            
            return call_id; // Return the call id
        }
    }
};

int main()
{
    CallCenter center; // Instantiate CallCenter object

    // Receiving some calls
    center.receive_call(101);
    center.receive_call(102);
    center.receive_call(103);

    // Processing all calls
    int call_id;
    while((call_id = center.process_call()) != -1) {
        std::cout << "Successfully processed call: " << call_id << std::endl;
    }

    return 0;
}
