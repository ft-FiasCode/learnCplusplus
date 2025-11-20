#include <iostream>
using namespace std;

int main() {
    int arr[] = {10, 20, 30};
    int *ptr = arr; // Pointer to the first element of the array

    for (int i = 0; i < 3; i++) {
        cout << "Address: " << ptr << ", Value: " << *ptr << endl;
        ptr++; // Move to the next integer (4 bytes ahead)
        cout << "Address:-> " << endl;
        
        
    }
    return 0;
}