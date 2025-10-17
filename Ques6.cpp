#include<iostream>
using namespace std;

template<class A>
class QueueADT {
    int front;
    int rear;
    int count;
    A* arr;
public:
    QueueADT(int size)
    {
        n = size;
        arr = new A[size];
        front = 0;
        rear = -1;
        count = 0;
    }
    void enqueue(A x);
    A dequeue();
    bool isEmpty();
    bool isFull();
    int sizeofthequeue();
    void display();
};

template<class A>
void QueueADT<A>::enqueue(A x) {
    if (!isFull()) {
        rear = (rear + 1) % n;  
        arr[rear] = x;
        count++;                 
    }
    else {
        cout << "Queue Overflow Error\n";
    }
}

template<class A>
A QueueADT<A>::dequeue() {
    if (!isEmpty()) {
        A temp = arr[front];
        front = (front + 1) % n; 
        count--;              
        return temp;
    }
    else {
        cout << "Queue Underflow Error\n";
        return A();  
    }
}

template<class A>
bool QueueADT<A>::isEmpty() {
    return (count == 0);
}

template<class A>
bool QueueADT<A>::isFull() {
    return (count == n);
}

template<class A>
void QueueADT<A>::display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = 0; i < count; i++) {
        int index = (front + i) % n;
        cout << arr[index] << " ";
    }
    cout << endl;
}

template<class A>
int QueueADT<A>::sizeofthequeue() {
    return count;
}

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    QueueADT<int> queue(size);

    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Enqueue\n2. Dequeue\n3. IsEmpty\n4. IsFull\n5. Size of the Queue\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter the value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;
        }

        case 2: {
            int popped = queue.dequeue();
            if (!queue.isEmpty() || popped != 0) 
                cout << "Dequeued element: " << popped << endl;
            break;
        }

        case 3: {
            if (queue.isEmpty()) {
                cout << "Queue is Empty" << endl;
            }
            else {
                cout << "Queue is not Empty" << endl;
            }
            break;
        }

        case 4: {
            if (queue.isFull()) {
                cout << "Queue is Full" << endl;
            }
            else {
                cout << "Queue is not Full" << endl;
            }
            break;
        }

        case 5: {
            cout << "Size of the queue is: " << queue.sizeofthequeue() << endl;
            break;
        }

        case 6: {
            queue.display();
            break;
        }

        case 7: {
            cout << "Exiting...\n";
            break;
        }

        default: {
            cout << "Invalid choice! Try again.\n";
        }
        }

    } while (choice != 7);

    return 0;
}