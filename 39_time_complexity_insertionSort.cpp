#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

class insertion{
	private: 
		int i , j , temp;
	public:
		void insertionSort(int arr[], int size){
			for(i=1; i<size; i++){
				temp = arr[i];
				j = i-1;
				
				while(arr[j]>temp && j>=0){
					arr[j+1] = arr[j];
					j--;				
				}
				arr[j+1] = temp;
			}
		}
	
		void display(int arr[], int size){		
		for(i=0; i<size; i++){
				cout<<" "<<arr[i];
			}
			cout<<endl;
		}
	
};	

int main(){
	insertion i1;
	int n, i;
	cout<<"Enter the size of array : ";
	cin>>n;
	int arr[n];
	for(i=0; i<n; i++){
		arr[i] = rand() % 10000;
	}
	auto start = high_resolution_clock::now();
	i1.insertionSort(arr,n);
	auto end = high_resolution_clock::now();
	i1.display(arr, n);
	
	auto duration = duration_cast<milliseconds>(end - start);
	
	cout<<"Time taken : "<<duration.count()<<" in milisecond  "<<endl;
	
	return 0;
}
