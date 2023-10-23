#include <iostream>
using namespace std;
int Minimum(int a, int b, int c) {
    int minimum;
    if (a <= b && a <= c) {
        minimum = a;
    } else if (b <= a && b <= c) {
        minimum = b;
    } else {
        minimum = c;
    }
    return minimum;
}
int FindDis(string a,string b){
    int size_of_a=a.length();
    int size_of_b=b.length();
    int distance[size_of_a+1][size_of_b+1];
    for (int i = 0; i <= size_of_a; i++)
    {
        distance[i][0]=i;
    }
    for (int j = 0; j <= size_of_b; j++)
    {
        distance[0][j]=j;
    }
    for (int j = 1; j <=size_of_b ; j++)
    {
        for (int i = 1; i <= size_of_a; i++)
        {
            int indicator=a[i-1]!=b[j-1]?1:0;
            int deletion=distance[i-1][j]+1;
            int insertion=distance[i][j-1]+1;
            int substitition=distance[i-1][j-1]+indicator;
            distance[i][j]=Minimum(deletion,insertion,substitition);
        }
    }
    return distance[size_of_a][size_of_b];
    
    
}
int main()
{
    string a,b;
    cout<<"enter correct word\n";
    cin>>a;
    cout<<"enter value which have to be compared\n";
    cin>>b;
    cout<<"Distance according to Levenshtein algo is : "<<FindDis(a,b)<<endl;
    return 0;
}