#include <iostream>
using namespace std;
int main()
{
    int array[5];
    cout<<"Enter elements of Array which are too be sorted\n";
    for (int i = 0; i < 5; i++)
    {
        cin>>array[i];
    }
    
    for (int i = 1; i < 5; i++)
    {
        int temp=array[i];
        int j=i-1;
        while (j>=0 && array[j]>temp)
        {
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
    
    for (int i = 0; i < 5; i++)
    {
        cout<<array[i]<<" ";
    }
    
    return 0;
}