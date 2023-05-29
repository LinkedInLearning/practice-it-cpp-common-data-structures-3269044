#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> intQueue; // Create an empty queue of ints

    int arr[] = {5, 10, 42};
    const int arrayCount = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < arrayCount; ++i)
    {
        intQueue.push(arr[i]);
    }

    cout << intQueue.front() << endl;

    intQueue.pop();
    cout << intQueue.front() << endl;
    if (intQueue.empty())
    {
        cout << "The queue is now empty!";
    }
    else
    {
        cout << "There are still items in the queue.";
    }

    return 0;
}
