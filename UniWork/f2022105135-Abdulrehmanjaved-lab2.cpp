#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include<cmath>
using namespace std;

struct Medicine
{
    int Quantity, Price, ExpiryDate, ExpiryMonth, ExpiryDay;
    string Name;
};

// Change 1: Modify the base_to_power function to handle non-integer exponents
double base_to_power(double base, double exponent)
{
    if (exponent >= 0)
    {
        double result = 1;
        for (int i = 0; i < exponent; i++)
        {
            result *= base;
        }
        double fraction = exponent - static_cast<int>(exponent);
        if (fraction > 0)
        {
            double root = pow(base, fraction);
            result *= root;
        }
        return result;
    }
    else
    {
        // Handle negative exponents by taking the reciprocal
        double result = 1;
        for (int i = 0; i < -exponent; i++)
        {
            result *= (1.0 / base);
        }
        double fraction = -exponent - static_cast<int>(-exponent);
        if (fraction > 0)
        {
            double root = pow(base, fraction);
            result *= root;
        }
        return result;
    }
}

int main()
{
	//task of base_to_power in double elments
	double a,b;
	cin>>a>>b;
	cout<<base_to_power(a,b)<<endl;
    ifstream ReadFile("dataFile.txt");
    int n;

    // Check if the file exists and open it
    if (ReadFile.is_open())
    {
        // Counting the number of lines 
        n = 0;
        string line;
        while (getline(ReadFile, line))
        {
            n++;
        }
        ReadFile.close();

        // Reopen the file to read the data
        ReadFile.open("dataFile.txt");
        Medicine ReadMedicine[n];
        for (int i = 0; i < n; i++)
        {
            ReadFile >> ReadMedicine[i].Name >> ReadMedicine[i].Price >> ReadMedicine[i].Quantity >> ReadMedicine[i].ExpiryDate >> ReadMedicine[i].ExpiryMonth >> ReadMedicine[i].ExpiryDay;
        }
        ReadFile.close();

       //
        string Search;
        cout << "Search Medicine by entering name of it\n";
        cin >> Search;

int foundIndex = -1;
string search_lowercase = Search;
for (int i = 0; i < n; i++)
{
    string name_from_file = ReadMedicine[i].Name;
    int j;
    bool match = true;
    for (j = 0; j < search_lowercase.length(); j++)
    {
        if (j >= name_from_file.length() || tolower(search_lowercase[j]) != tolower(name_from_file[j]))
        {
            match = false;
            break;
        }
    }

    if (match && j == search_lowercase.length())
    {
        foundIndex = i;
        break; 
    }
}

if (foundIndex != -1)
{
    cout << "Medicine Found: " << ReadMedicine[foundIndex].Name << endl;
    cout << "Quantity: " << ReadMedicine[foundIndex].Quantity << endl;
    cout << "Expiry Date: " << ReadMedicine[foundIndex].ExpiryDate << " / " << ReadMedicine[foundIndex].ExpiryMonth << " / " << ReadMedicine[foundIndex].ExpiryDay << endl;
    cout << "Price: " << ReadMedicine[foundIndex].Price << endl;
}
else
{
    cout << "Not found\n";
}


    }
    else
    {
        cout << "The dataFile.txt does not exist. Please write data to the file first." << endl;
    }

    return 0;
}

	// task 2(Explanation of each swap function)

	// void swap(int num1, int num2): This function swaps two integers num1 and num2, but the changes made within the function do not affect the original values of i and j in the main function. This is because the arguments are passed by value, and the function operates on copies of the values.
	//  void swap(int &num1, int &num2): This function swaps two integers num1 and num2 by reference. In this case, the changes made within the function do affect the original values of i and j in the main function, resulting in a successful swap.
	//  void swap(int* num1, int* num2): This function swaps two integers pointed to by num1 and num2. It operates on the memory locations pointed to by the pointers, so it also successfully swaps the values of i and j in the main function.

