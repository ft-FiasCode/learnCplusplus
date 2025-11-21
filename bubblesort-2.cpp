#include <iostream>
using namespace std;

int main()
{
      int arr[]={4,6,2,9,7,22,5,3,8};
      int s=9;
      
      for(int round=1;round<=s-2; round++)
      {
      	int flag=0;
      	for(int j=0;j<s-1;j++)
      	{
      	   if(arr[j]>arr[j+1])
			 {
			 	flag=1;
			 	int temp=arr[j];
			 	arr[j]=arr[j+1];
			 	arr[j+1]=temp;
			 }	
					    
		}
	  }
      
      cout<<"array inde first element is "<<arr[0]<<endl;
      cout<<"array inde last is element is "<<arr[8]<<endl;
      for(int w=0; w<9; w++)
      {
      	cout<<"array  "<<arr[w]<<endl;
	  }
      
      
    return 0;
}