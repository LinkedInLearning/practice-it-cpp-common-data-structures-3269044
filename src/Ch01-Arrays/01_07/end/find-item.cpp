#include <iostream>
#include <string>
using namespace std;

template <typename T>
int findItem(const T arr[], size_t size, T target)
{
    int result = -1;
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] == target)
        {
            result = i;
            break;
        }
    }
    return result;
}

int main()
{
    int intNumbers[] {4, 7, 12, 3, 9, 17, 29};
    size_t intSize = sizeof(intNumbers) / sizeof(intNumbers[0]);
    int targetInt = 17;
    size_t intIndex = findItem(intNumbers, intSize, targetInt);

    string strArray[] = {"apple", "banana", "cherry", "orange"};
    size_t strSize = sizeof(strArray) / sizeof(strArray[0]);
    string targetStr = "kiwi";
    size_t strIndex = findItem(strArray, strSize, targetStr);

    if (intIndex != -1)
    {
        cout << "The target integer " << targetInt << " is found at index " << intIndex << "." << endl;
    }
    else
    {
        cout << "The target integer " << targetInt << " is not found in the array." << endl;
    }

    if (strIndex != -1)
    {
        cout << "The target string \"" << targetStr << "\" is found at index " << strIndex << "." << endl;
    }
    else
    {
        cout << "The target string \"" << targetStr << "\" is not found in the array." << endl;
    }

    return 0;
}
