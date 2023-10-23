#include <iostream>
using namespace std;

int main()
{
    int array[5]={1,4,3,10,5};
    for (int i = 0; i < 5; i++)
    {
        for (int j = i+1; j < 5; j++)
        {
            if(array[i]>array[j]){
                swap(array[i],array[j]);
            }
        }
        
    }
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<endl;
    }
    
    
    return 0;
}