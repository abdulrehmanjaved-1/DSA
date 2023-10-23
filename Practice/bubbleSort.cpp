#include <iostream>
using namespace std;
void swap_me(int a,int b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
int main()
{
    int array[5]={1,4,5,2,3};
    for (int i = 1; i < 5; i++)
    {
        for (int j = 0; j < 5-i; j++)
        {
            if(array[j]>array[j+1]){
                swap_me(array[i],array[j]);
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    
    
    return 0;
}