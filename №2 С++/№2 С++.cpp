#include <iostream>

using namespace std;

bool Simple(int number);

class Queue {

private:
    int* arr;
    int front;
    int rear;
    int current;
    int capacity;

public:
    Queue(int size) {
        arr = new int[size];
        front = 0;
        rear = -1;
        current = 0;
        capacity = size;
    }

    ~Queue() {
        delete[] arr;
    }

    bool isFull() {
        return (current == capacity);
    }

    bool isEmpty() {
        return (current == 0);
    }

    void enqueue(int number) {
        if (isFull()) {
            cout << "Queue - Full";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = number;
        current++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue - Empty";
            return;
        }
        front = (front + 1) % capacity;
        current--;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue - Empty";
            return -1;
        }
        return arr[front];
    }

    void Show() {
        cout << "Prime numbers in queue: ";
        for (int i = 0; i < capacity; i++) {
            int index = front + i;
            if (Simple(arr[index])) {
                cout << arr[index] << " ";
            }
        }

    }
};

    int main() {

        srand(time(NULL));

        cout << "Enter your variant: "; 
        int variant;
        cin >> variant;

        int S = variant * 5 + 50;

        Queue q(S);

        for (int i = 0; i < S; i++) {
            int a = rand() % 1000 + 1;
            q.enqueue(a);
        }

        q.Show(); 

    }

    bool Simple(int number) {
        if (number <= 1) return false;
        for (int i = 2; i <= sqrt(number); i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
    
