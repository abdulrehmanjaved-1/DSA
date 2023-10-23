#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int num;
    int ans = 0;
    int i = 0;
    cout << "welcome\n";
    cin >> num;
    while (num != 0)
    {
        /* code */
        int bit = num & 1;
        ans = (bit * pow(10, i)) + ans;
        num = num >> 1;
        i++;
    }
    cout << "Binary form of number is " << ans << endl;
    return 0;
}