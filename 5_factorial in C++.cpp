#include <iostream>
using namespace std;

int main() {
    int number, factorial = 1; 

    cout<<"Enter a positive integer ";
    cin>>number;

    if (number < 0) {
        cout<<"Factorial is not defined"<<endl;
    } else {
       
        for (int i = 1; i <= number; ++i) {
            factorial *= i; 
        }
        cout<<"Factorial of "<<number<< " = " <<factorial<<endl;
    }

    return 0;
}
