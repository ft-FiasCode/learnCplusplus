#include <iostream>
using namespace std;

int main() {
    int n; 
    cout << "Enter array size ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " number" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int sum = 0; 
    for (int i = 0; i < n; ++i) {
        sum += arr[i]; 
    }

    cout << "The sum of array is " << sum << endl;
    return 0;
}
