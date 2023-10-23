#include <iostream>
using namespace std;
void towerOfHanoi(int n,string src,string helper,string dest){
    //base case
    if(n==0){
        return;
    }
    //recursive call
    towerOfHanoi(n-1,src,dest,helper);
    cout<<"Move "<<n<<"th disk from "<<src<<" to "<<dest<<endl; 
    towerOfHanoi(n-1,helper,src,dest);    
}
int main()
{
    int n;
    cout<<"Enter the number of disks\n";
    cin>>n;
    towerOfHanoi(n,"SRC","HELPER","DEST");    
    return 0;
}