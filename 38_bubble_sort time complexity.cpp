#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

class BubbleSort{
    private:
        int i, j, temp;
    public:
           void bubbleSort(int arr[], int size){
            for(i = 0; i < size-1; i++){
                for(j = 0; j < size-i-1; j++){
                    if(arr[j] > arr[j+1]){
                        temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
        void display(int arr[], int size){
            for(i = 0; i < size; i++){
                cout << " " << arr[i];
            }
            cout << endl;
        }
};

int main(){
    BubbleSort b1;
    int n, i;
    cout << "Enter the size of array : ";
    cin >> n;
    int arr[n];

    for(i = 0; i < n; i++){
        arr[i] = rand() % 10000;
    }

    auto start = high_resolution_clock::now();
    b1.bubbleSort(arr, n);
    auto end = high_resolution_clock::now();
    
    b1.display(arr, n);

    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Time taken : " << duration.count() << " milliseconds" << endl;

    return 0;
}
