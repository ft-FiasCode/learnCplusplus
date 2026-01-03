#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter array size:";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << "number" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int lar = arr[0];
    int sam = arr[0]; 
    
    for (int i = 1; i < n; ++i) {
        if (arr[i] > lar) {
            lar = arr[i]; 
        }
        if (arr[i] < sam) {
            sam = arr[i]; 
        }
    }  
    cout << "The largest number in the array is: " << lar << endl;
    cout << "The samllest number in the array is: " << sam << endl;

    return 0;

}

