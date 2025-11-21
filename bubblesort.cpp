#include <iostream>
using namespace std;

int main()
{
      int arr[]={4,6,2,9,7,22,5,3,8};
      int s=9;
      
      for(int i=0;i<9; i++)
      {
      	int swapped=0;
      	for(int j=1;j<s;j++)
      	{
      	   if(arr[j]<arr[j-1])
			 {
			 	int temp=arr[j];-
			 	arr[j]=arr[j-1];
			 	arr[j-1]=temp;
			 	swapped=1;
			 }	
		}
		if(swapped==0)
		{
			cout<<"0000 means array is sorted now"<<endl;
			break;
		}
					    
		cout<<"pass "<<i+1<<endl;
	  }
      
      cout<<"array inde first element is "<<arr[0]<<endl;
      cout<<"array inde last is element is "<<arr[8]<<endl;
      for(int w=0; w<9; w++)
      {
      	cout<<"array  "<<arr[w]<<endl;
	  }
      
      
    return 0;
}