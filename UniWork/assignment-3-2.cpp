#include <iostream>
#include <queue>

using namespace std;

const int MAX_ROOMS = 10;

// Room types
enum RoomType {
    DELUXE,
    STANDARD,
    ECONOMY,
    SUITE
};

// PriorityQueue class
class PriorityQueue {
private:
    queue<int> roomQueue;

public:
    PriorityQueue() {
        // Initialize queue with room numbers
        for (int i = 1; i <= MAX_ROOMS; ++i) {
            roomQueue.push(i);
        }
    }

    bool isEmpty() const {
        return roomQueue.empty();
    }

    int dequeue() {
        if (!isEmpty()) {
            int roomNumber = roomQueue.front();
            roomQueue.pop();
            return roomNumber;
        } else {
            return -1;  // Indicates no rooms available
        }
    }
};

// Hotel class
class Hotel {
private:
    PriorityQueue roomQueues[4];

public:
    // Checkout function
    void checkout() {
        const char* roomTypeNames[] = {"Deluxe", "Standard", "Economy", "Suite"};

        for (int type = 0; type < 4; ++type) {
            int roomNumber = roomQueues[type].dequeue();
            if (roomNumber != -1) {
                cout << "Checkout successful for Room " << roomNumber << " (" << roomTypeNames[type] << ")\n";
                return;
            }
        }

        cout << "No rooms available." << endl;
    }
};

int main() {
    Hotel hotel;

    // Simulate checkouts
    hotel.checkout();  // Checkout from Deluxe
    hotel.checkout();  // Checkout from Standard
    hotel.checkout();  // Checkout from Economy
    hotel.checkout();  // Checkout from Suite
    hotel.checkout();  // No rooms available

    return 0;
}

