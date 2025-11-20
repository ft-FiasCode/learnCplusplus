#include <iostream>
using namespace std;

class RationalNumber {
public:
    int numerator;
    int denominator;
    RationalNumber(int num, int denom) : numerator(num), denominator(denom) {}
};
/*
void swap(int &a, int &b) {
    int temp = a;
    a = b; // Modifies original variables
    b = temp;
}
*/
void swap(int *a, int *b) {
    int temp = *a;
    *a =*b; // Modifies original variables
    *b = temp;
}


int main() {
	
	  int a =20;
      int *p = &a;
      cout<<a<<"  "<<&a<<endl;
      cout<<p<<"  L"<<&p<<endl;
      cout << *p<<endl;
      cout << "-----------------"<< endl;
	
    // Pointer to an integer
    int num = 10;
    int* pNum = &num;

    // Pointer to a character
    char letter = 'C';
    char* pChar = &letter;

    // Pointer to a user-defined object
    RationalNumber* pRational = new RationalNumber(1, 2);

    // Pointer to pointer example
    int** ppNum = &pNum;

    cout << "Value of num: " << *pNum << endl; // Outputs: Value of num: 10
    cout << "Value of letter: " << *pChar << endl; // Outputs: Value of letter: C
    cout << "Rational Number: " << pRational->numerator << "/" << pRational->denominator << endl; // Outputs: Rational Number: 1/2

    delete pRational; // Free allocated memory for RationalNumber
     
     
      cout << "-----------------"<< endl;
       cout << "ptr to ptr"<< endl;
    int var = 3000;          // Original variable
    int *ptr = &var;        // Pointer to var
    int **pptr = &ptr;      // Pointer to ptr

    // Outputting values
    cout << "Value of var: " << var << endl;               // Outputs: 3000
    cout << "Value available at *ptr: " << *ptr << endl;   // Outputs: 3000
    cout << "Value available at **pptr: " << **pptr << endl; // Outputs: 3000

     


     cout << "-----------------"<< endl;
       cout << "pass by refrenves or value"<< endl;

    int x = 5, y = 10;
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swap: x = " << x << ", y = " << y << endl; // Values are swapped
 
 
  cout << "-----------------"<< endl;
  cout << "ppointer as arrray constant"<< endl;

    int myArray[3] = {10, 20, 30}; // Declaration and initialization of an array

    cout << *myArray << "   " << myArray[0] << endl; // Accessing the first element
    
    cout << "arrray constant as pointer"<< endl;
    int *ptrr = myArray; // Pointer pointing to the first element of myArray

    cout << myArray[0] << "   " << *ptrr << endl; // Accessing the first element



    return 0;
}