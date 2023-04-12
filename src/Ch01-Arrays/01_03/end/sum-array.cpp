#include <iostream>
using namespace std;

int calculateSum(const int arr[], size_t size)
{
    // handle edge cases
    if(size == 0)
    {
        return 0;
    }

    if(size == 1)
    {
        return arr[0];
    }

    int sum = 0;
    for (size_t i = 0; i < size; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    const int ints[] {1, -7, 17};
    cout << "The sum of all elements in the array is " << calculateSum(ints, 3) << endl;
}