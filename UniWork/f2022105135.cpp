#include<iostream>
using namespace std;
class Stack{
	int array[500];
	char array2[500];
	int top=0;
	int top2=0;
	public:
		Stack(){
			top=-1;
			top2=-1;
		}
		int length(){
			return top;
		}
		void push(int data){
			++top;
    		array[top] = data;
		}
		void push2(char infix){
			++top2;
    		array2[top2] = infix;
		}
		int pop(){
			int temp;
    		temp = array[top];
    		--top;
   			return temp;
		}
		string pop2(){
			string temp;
    		temp = array2[top];
    		--top;
   			return temp;
		}
		//destr. to be
		void Print_In_Reverse(){
		int i; //for loop
    	cout << "Reversed elements are : ";
    	for (i = (top); i >= 0; i--)
        cout << array[i] << " ";
    	cout << endl;
		}
		void Print_In_Reverse2(){
		int i; 
    	cout << "Postfix : \n";
    	for (i = (top2); i >= 0; i--)
        cout << array2[i];
		}
};
void ConvertToBinary(int &dec,Stack &s2){
	while(dec!=0){
		int rem=dec%2;
		s2.push(rem);
		dec=dec/2;
	}
	s2.Print_In_Reverse();
	cout<<endl;
}
void InfixToPostfix(string s){ //to be cont.
    Stack s1;
    for(int i=0;i<s.length();i++){
        if()
    }
};
int main(){
	//task1 (print in reversed form)
	Stack s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.Print_In_Reverse();
	
	//task2 (Decimal to Binary conversion)
	Stack s2;
	int dec;
	cout<<"Enter value \n";
	cin>>dec;
	ConvertToBinary(dec,s2);

	//task3 (Infix to Postfix)
	string infix;
	Stack s3;
	cout<<"Enter expression\n";
	cin>>infix;
    InfixToPostfix(infix,s3);
	

    

	
	
	
}
