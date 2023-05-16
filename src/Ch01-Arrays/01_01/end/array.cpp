#include <iostream>
using namespace std;

int main()
{
    // Declares an array of 5 integers
    int numbers[5];

    // Declares an array of 10 strings
    string names[10];

    // Initializes the array
    int numbers2[] = {1, 2, 3, 4, 5};

    // Brace initialization
    int numbers3[] {1, 2, 3, 4, 5};

    // Reads the first element
    int first_number = numbers[0];

    // Modifies the third element
    numbers[2] = 42;

    // Iterates over the numbers array using a for loop
    for (int i = 0; i < 5; ++i)
    {
        cout << "Element at index " << i << ": " << numbers[i] << endl;
    }

    // Iterates over the numbers array using a foreach loop
    for (int number : numbers)
    {
        cout << "Element: " << number << endl;
    }

    return 0;
}