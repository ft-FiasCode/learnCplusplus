#include <iostream>
using namespace std;
#define MAX 10

class Stack {
private:
    int items[MAX];
    int top;
public:
    Stack() {
        top=-1;
    }
    bool isFull() {
        return top==MAX-1;
    }
    bool isEmpty() {
        return top==-1;
    }
    void push(int newItem) {
        if (isFull()) {
            cout<<"STACK FULL"<<endl;
        } else {
            items[++top]=newItem;
            cout<<newItem<<" pushed to stack"<<endl;
        }
    }
    void display() {
        cout<<"Current Top Pointer: "<<top<<endl;
        cout<<"Elements in Stack (LIFO Order): ";
        for (int i=top;i>=0;i--) {
            cout<<items[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
	cout<<"Current Top Pointer: "<<endl;
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    return 0;
}