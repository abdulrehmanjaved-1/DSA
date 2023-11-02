#include <iostream>
using namespace std;
class Stack
{
    int array[500];
    char array2[500];
    int top = 0;
    int top2 = 0;

public:
    Stack()
    {
        top = -1;
        top2 = -1;
    }
    char getTop()
    {
        if (top2 >= 0)
        {
            return array2[top2];
        }
        return '\0'; // Return a default value when the stack is empty.
    }

    int length()
    {
        return top2;
    }
    void push(int data)
    {
        ++top;
        array[top] = data;
    }
    void push2(char infix)
    {
        ++top2;
        array2[top2] = infix;
    }
    int pop()
    {
        int temp;
        temp = array[top];
        --top;
        return temp;
    }
    char pop2()
    {
        char temp;
        temp = array2[top2];
        --top2;
        return temp;
    }
    // destr. to be
    void Print_In_Reverse()
    {
        int i; // for loop
        cout << "Reversed elements are : ";
        for (i = (top); i >= 0; i--)
            cout << array[i] << " ";
        cout << endl;
    }
    void Print_In_Reverse2()
    {
        int i;
        cout << "Postfix : \n";
        for (i = (top2); i >= 0; i--)
            cout << array2[i];
    }
};
void ConvertToBinary(int &dec, Stack &s2)
{
    while (dec != 0)
    {
        int rem = dec % 2;
        s2.push(rem);
        dec = dec / 2;
    }
    s2.Print_In_Reverse();
    cout << endl;
}
int checkPrecedence(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
void InfixToPostfix(string s) {
    Stack s3;
    string res;

    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            res += s[i];
        } else if (s[i] == '(') {
            s3.push2(s[i]);
        } else if (s[i] == ')') {
            while (s3.getTop() != '(') {
                res += s3.pop2();
            }
            s3.pop2(); // Pop the '('
        } else {
            while (s3.length() > 0 && s3.getTop() != '(' && checkPrecedence(s[i]) <= checkPrecedence(s3.getTop())) {
                res += s3.pop2();
            }
            s3.push2(s[i]);
        }
    }
    while (s3.length() > 0) {
        res += s3.pop2();
    }

    cout << "String in postfix form is: " << res << endl;
}
void EvaluationOfPostfix(string s) {
    Stack s4;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            s4.push(s[i] - '0');
        } else {
            int op2 = s4.pop();
            int op1 = s4.pop();
            switch (s[i]) {
                case '+':
                    s4.push(op1 + op2);
                    break;
                case '-':
                    s4.push(op1 - op2);
                    break;
                case '*':
                    s4.push(op1 * op2);
                    break;
                case '/':
                    s4.push(op1 / op2);
                    break;
                case '^':
                    s4.push(op1 ^ op2);
                    break;
            }
        }
    }
    cout << "Result is: " << s4.pop() << endl;
}

int main()
{
    // task1 (print in reversed form)
    Stack s1;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.Print_In_Reverse();

    // task2 (Decimal to Binary conversion)
    Stack s2;
    int dec;
    cout << "Enter value \n";
    cin >> dec;
    ConvertToBinary(dec, s2);

    // task3 (Infix to Postfix)
    Stack s3;
    string infix;
    cout << "Enter expression\n";
    cin >> infix;
    InfixToPostfix(infix);
    //task4 (evaluation of postfix)
    string postfix;
    cout << "Enter postfix expression\n";
    cin >> postfix;
    EvaluationOfPostfix(postfix);

}
