#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 6, 2, 9, 7, 22, 5, 3, 8};
    int s = sizeof(arr) / sizeof(arr[0]); // Calculate size dynamically

    // Insertion Sort
    for (int i = 1; i < s; i++)
    {
        int temp = arr[i];
        int j;
        for (j = i; j > 0 && arr[j - 1] > temp; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[j] = temp;
    }

    cout << "Array index first element is " << arr[0] << endl;
    cout << "Array index last element is " << arr[s - 1] << endl;

    for (int w = 0; w < s; w++)
    {
        cout << "Array element " << arr[w] << endl;
    }

    return 0;
}