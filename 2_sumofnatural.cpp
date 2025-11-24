#include <iostream>
using namespace std;

int main() {
    int N, sum = 0; 

    cout<<"Enter integer ";
    cin>>N;

    if (N < 1) {
        cout << "Please enter a number greater than 0." << endl;
    } else {
            for (int i = 1; i <= N; ++i) {
            sum += i; 
        }
        cout << "The sum of the first " << N << " natural numbers is: " << sum << endl;
    }

    return 0;
}
