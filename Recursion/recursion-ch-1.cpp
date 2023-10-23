#include <iostream>
using namespace std;
string reverse_string(string& name,int starting_index,int s){
    if(starting_index>s-starting_index){
        return name;
    }
        swap(name[starting_index],name[s-starting_index]);
        starting_index++;
        return reverse_string(name,starting_index,s);

}
int main()
{
    string name="abdulrehman";
    int start=0,s=name.length()-1;
    cout<<"reversed string is "<<reverse_string(name,start,s);
    return 0;
}