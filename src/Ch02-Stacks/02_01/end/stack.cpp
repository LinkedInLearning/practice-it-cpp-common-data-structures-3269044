#include <iostream>
#include <stack> // This is the header file for the stack
using namespace std;

int main() {
    stack<int> intStack; // Declaring a stack of integers

    // Using the push operation to add elements to the stack
    intStack.push(5);
    intStack.push(10);
    intStack.push(15);

    // Using the top operation to view the top element
    cout << "Top element is: " << intStack.top() << endl; // Should output 15

    // Using the pop operation to remove the top element
    intStack.pop();

    // Using the peek operation to view the top element after the pop operation
    cout << "Top element is: " << intStack.top() << endl; // Should output 10

    // Loop and call pop() until the stack is empty
    while (!intStack.empty())
    {
        cout << "Top element is: " << intStack.top() << endl; // Should output 10        
        intStack.pop();
    }

    return 0;
}