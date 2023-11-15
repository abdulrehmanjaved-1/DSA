#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include<cmath>
using namespace std;
const int siz=10;
class stack{
	int arr[siz];
	int index;
	public:
		stack(){
			index=-1;
		}
		void push(int data){
			if(index==siz-1){
				cout<<"Stack is overflowing\n";
			}else{
				arr[++index]=data;
			}
		}
		void pop(){
			if(index==-1){
				cout<<"Stack is empty\n";
			}else{
				cout<<"Deleted value is : "<<arr[index]<<endl;
				index--;
			}
		}
		int top(){
			return arr[index];
		}
};
class queue{
	int front,rear;
	int arr[siz];
	public:
		queue(){
			rear=-1;
			front=-1;
		}
		void enqueue(int data){
			//checkPost
			if(rear==siz-1){
				cout<<"Stack is in overflow condition\n";
			}else if(rear==-1 and front==-1){
				front=0;
				rear=0;
				
			}else{
				rear++;
			}
			arr[rear]=data;
		}
		void dequeue(){
			if(front==-1){
				cout<<"Queue is underFlowing\n";
			}else if(front==rear){
				front=0;rear=0;
			}
			else{
				cout<<"Deleted value is "<<arr[front]<<endl;
				front++;
			}
		}
		int top(){
			return arr[front];
		}
};

struct Medicine
{
	queue Quantity;
	stack Price;
    int ExpiryDate, ExpiryMonth, ExpiryDay;
    string Name;
};

void addStock(Medicine& medicine, int newPrice, int newQuantity) {
    medicine.Price.push(newPrice);
    medicine.Quantity.enqueue(newQuantity);
}
void sellMedicine(Medicine& medicine, int Quantity_to_be_sold) {
    if (medicine.Quantity.top() == -1) {
        cout << "No stock available for selling\n";
    } else if (Quantity_to_be_sold > medicine.Quantity.top()) {
        cout << "Not enough stock available for selling\n";
    } else {
        medicine.Quantity.enqueue(medicine.Quantity.top() - Quantity_to_be_sold);
        cout << "Sold " << Quantity_to_be_sold << " units of " << medicine.Name << endl;
    }
}

int main()
{
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
    //    cout<<n<<endl;

       // Reopen the file to read the data
       ReadFile.open("dataFile.txt");
       Medicine ReadMedicine[n];
       for (int i = 0; i < n; i++)
       {
            int oldPrice=0;
            int oldQuantity=0;
           ReadFile >> ReadMedicine[i].Name >> oldPrice >> oldQuantity >> ReadMedicine[i].ExpiryDate >> ReadMedicine[i].ExpiryMonth >> ReadMedicine[i].ExpiryDay;
           ReadMedicine[i].Price.push(oldPrice);
           ReadMedicine[i].Quantity.enqueue(oldQuantity);
       }
       ReadFile.close();
        //testing
   addStock(ReadMedicine[0], 15, 50);
//    sellMedicine(ReadMedicine[0], 20);
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
   cout << "Quantity: " << ReadMedicine[foundIndex].Quantity.top() << endl;
   cout << "Expiry Date: " << ReadMedicine[foundIndex].ExpiryDate << " / " << ReadMedicine[foundIndex].ExpiryMonth << " / " << ReadMedicine[foundIndex].ExpiryDay << endl;
   cout << "Price: " << ReadMedicine[foundIndex].Price.top() << endl;

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
    


	// int price,quant;
	// cout<<"enter price of new stack\n";
	// cin>>price;
	// Medicine medicine;
	// medicine.Price.push(price);
	// cout<<"the price of new stock is : "<<medicine.Price.top()<<endl;
	// cout<<"Enter the quantity (of new stock)"<<endl;
	// cin>>quant;
	// medicine.Quantity.enqueue(quant);
	// cout<<"Quantity of this medicine is "<<medicine.Quantity.top()<<endl;
    return 0;
}