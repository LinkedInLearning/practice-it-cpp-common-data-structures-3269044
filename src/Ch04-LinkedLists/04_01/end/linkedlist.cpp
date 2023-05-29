#include <list>
#include <iostream>
using namespace std;

int main()
{
    // Initialize a list with values
    list<int> intList{1, 2, 3, 4, 5};

    // Add elements
    intList.push_back(6);

    intList.push_front(0);

    // Insert an element at the third position
    auto it = intList.begin();
    advance(it, 2);        // Move iterator to the 3rd position
    intList.insert(it, -1); // Insert -1 at the 3rd position

    // Print the list in forward direction
    cout << "List in forward direction: ";
    for (auto &el : intList)
    {
        cout << el << ' ';
    }
    cout << endl;

    // Remove the last element
    intList.pop_back();

    // Remove the first element
    intList.pop_front();

    // Reverse the list
    intList.reverse();

    // Print the list in forward direction (which is now reversed)
    cout << "List after reversing: ";
    for (auto &el : intList)
    {
        cout << el << ' ';
    }
    cout << endl;

    // Sort the list
    intList.sort();

    // Print the list after sorting
    cout << "List after sorting: ";
    for (auto &el : intList)
    {
        cout << el << ' ';
    }
    cout << endl;

    return 0;
}