#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 6, 2, 9, 7, 22, 5, 3, 8};
    int s = sizeof(arr) / sizeof(arr[0]); // Calculate size dynamically
    int in = 0, out = 0;

    // Insertion Sort
    for (out = 1; out < s; out++)
    {
        int temp = arr[out]; // Initialize temp with the current element
        in = out;

        while (in > 0 && arr[in - 1] > temp)
        {
            arr[in] = arr[in - 1];
            in--;
        }
        arr[in] = temp; // Place temp in the correct position
    }

    cout << "Array index first element is " << arr[0] << endl;
    cout << "Array index last element is " << arr[s - 1] << endl;

    for (int w = 0; w < s; w++)
    {
        cout << "Array element " << arr[w] << endl;
    }

    return 0;
}