#include <iostream>
using namespace std;
int main(){
    cout<<"Welcome Back?"<<endl;
    int num;
    // char num2='A';
    cin>>num;
    for(int i=1;i<=num;i++){
        for (int j = 1; j>i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <=num; k++)
        {
            cout<<"*";
        }
        
        cout<<endl;
    }
}