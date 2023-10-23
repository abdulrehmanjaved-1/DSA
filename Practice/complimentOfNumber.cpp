#include <iostream>
using namespace std;
int main()
{
    int num;
    cin>>num;
    int num2=num;
    int mask=0;
    if(num2==0){
        return 1;
    }
    while (num2!=0)
    {
        /* code */
        mask=(mask<<1) | 1;
        num2=num2>>1;
    }
    int ans=(~num2) & mask;
    return ans;
}