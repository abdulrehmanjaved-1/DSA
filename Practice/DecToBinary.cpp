#include <iostream>
using namespace std;
class Stack{
    int array[500];
    int top=0;
    public:
    //constructor
    Stack(){top=-1;}
    void pop(){
        top--;
    }
    void push(int data){
        top++;
        array[top]=data;
    }
    void display(){
        cout<<"top is "<<array[top]<<endl;
    }
};
int main()
{
    int num;
    cin>>num;
    Stack s1;
    s1.push(num);
    s1.push(2);
    s1.push(3);
    cout<<"before\n";
    s1.display();
    s1.pop();
    cout<<"after\n";
    s1.display();

    return 0;
}