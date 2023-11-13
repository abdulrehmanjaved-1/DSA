#include <iostream>
using namespace std;
const int siz = 5;

class Queue {
    int array[siz];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void enque(int data) {
        if ((rear == siz - 1 && front == 0) || (rear == front - 1)) {
            cout << "Queue is full" << endl;
            return;
        } else if (rear == -1) {
            rear = 0;
            front = 0;
        } else {
            rear = (rear + 1) % siz;
        }
        array[rear] = data;
    }

    void deque() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % siz;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
        } else {
            int i = front;
            do {
                cout << array[i] << " ";
                i = (i + 1) % siz;
            } while (i != (rear + 1) % siz);
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.enque(12);
    q.enque(13);
    q.enque(14);
    q.enque(15);
    q.enque(16);
    q.display();
    q.deque();
    q.display();
    q.enque(18);
    q.display();

    return 0;
}
