#include <iostream>
using namespace std;
int powerOfBase(int base,int p){
    //base case
    if(p == 0)
        return 1;
    if(p == 1)
        return base;
    //recursive call  
    int ans= powerOfBase(base,p/2);
    if(p%2==0){
        return ans*ans;
    }else{
        return base*ans*ans;

    }
          
}
int main()
{
    int base,power;
    cin>>base>>power;
    cout<<powerOfBase(base,power);
    return 0;
}