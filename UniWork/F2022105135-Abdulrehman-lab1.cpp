#include <iostream>
#include <ctime>
using namespace std;
struct Medicine {
    string name;
    tm expiryDate;
};

void findExpiredMedicines(Medicine medicines[], int size) {
    time_t now = time(0);
    tm threeDaysLater = *localtime(&now);
    threeDaysLater.tm_mday += 3;

    cout << "Expired or expiring medicines within the next 3 days:" << endl;

    for (int i = 0; i < size; i++) {
        if (difftime(mktime(&medicines[i].expiryDate), now) < 0) {
            cout << "Expired: " << medicines[i].name << endl;
        }
        else if (difftime(mktime(&medicines[i].expiryDate), mktime(&threeDaysLater)) <= 0) {
            cout << "Expiring within 3 days: " << medicines[i].name << endl;
        }
    }
}

int main()
{
    // task 1
    //b is correct
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *s;
    s = &a[9]; // Start at the end of the array
    for (int i = 9; i >= 0; i--)
    {
        cout << *(s) << endl;
        s--; // Move the pointer to the previous element
    }
    // // task 2
    // int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int *p;
    // p = &b[9]; // Start at the end of the array
    // for (int i = 9; i >= 0; i--)
    // {
    //     cout << *(p) << endl;
    //     p--; // Move the pointer to the previous element
    // }
    // to update
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *q;
    q = &c[0];
    int index, newValue;

    cout << "Enter the index which has to update: ";
    cin >> index;

    if (index >= 0 && index < 10)
    {
        cout << "Enter the new value: ";
        cin >> newValue;
        *(q + index) = newValue; // Update the value using pointers
    }
    else
    {
        cout << "Invalid index." << endl;
    }
    //task3 
    int numMedicines = 5;
    Medicine medicines[numMedicines];

    medicines[0] = { "Medicine 1", { 123, 9, 121 } };  // Expired
    medicines[1] = { "Medicine 2", { 123, 9, 126 } };  // Expiring in 3 days
    medicines[2] = { "Medicine 3", { 123, 9, 130 } };  // Expiring in 7 days
    medicines[3] = { "Medicine 4", { 123, 9, 105 } };  // Expired
    medicines[4] = { "Medicine 5", { 123, 9, 140 } };  // Expiring in 14 days

    findExpiredMedicines(medicines, numMedicines);
}