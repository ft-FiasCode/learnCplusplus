#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9}; // Sorted array
    int val;
    cout << "Enter value to search: ";
    cin >> val;

    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1; // Correctly calculate the last index
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;
        cout << "start: " << start << ", mid: " << mid << ", end: " << end << endl;

        if (arr[mid] == val)
        {
            cout << "val = " << val << " index = " << mid << endl;
            return 0; // Return a value
        }
        else if (val > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    cout << "Value not found." << endl; // Inform if value is not found
    return 0; // Return a value
}