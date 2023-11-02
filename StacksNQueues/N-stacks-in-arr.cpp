#include <iostream>
using namespace std;

class KQueue {
    int *arr;
    int *front;
    int *rear;
    int *next;
    int freeSpot;
    int n, k;
    
public:
    KQueue(int n, int k) {
        this->n = n;
        this->k = k;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        next = new int[n];
        freeSpot = 0;
        
        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }
        
        for (int i = 0; i < n; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;
    }

    void enQueue(int data, int qn) {
        if (qn < 1 || qn > k) {
            cout << "Invalid queue number\n";
            return;
        }
        
        if (freeSpot == -1) {
            cout << "Sorry, no space available\n";
        } else {
            int index = freeSpot;
            freeSpot = next[index];

            if (front[qn - 1] == -1) {
                front[qn - 1] = index;
            } else {
                next[rear[qn - 1]] = index;
            }
            
            next[index] = -1;
            rear[qn - 1] = index;
            arr[index] = data;
        }
    }

    int deQueue(int qn) {
        if (qn < 1 || qn > k) {
            cout << "Invalid queue number\n";
            return -1;
        }
        
        if (front[qn - 1] == -1) {
            cout << "Empty Queue\n";
            return -1;
        } else {
            int index = front[qn - 1];
            front[qn - 1] = next[index];
            // manage freeSpots
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }
    }
};

int main() {
    KQueue q(10, 3);
    q.enQueue(2, 1);
    q.enQueue(3, 2);
    cout << q.deQueue(2) << endl;
    return 0;
}
