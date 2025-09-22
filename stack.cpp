#include <iostream>
using namespace std;

template<class A>
class StackADT {
    int n;
    int top;
    A *arr;
public:
    StackADT(int size) {
        n = size;
        top = -1;
        arr = new A[n];
    }

    ~StackADT() {
        delete[] arr;
    }

    void push(A el);
    A pop();
    bool isEmpty();
    bool isFull();
    A peekTop();
    void display();
};

template <class A>
void StackADT<A>::push(A el) {
    if (!isFull()) {
        top++;
        arr[top] = el;
    } else {
        cout << "Stack Overflow error\n";
    }
}

template <class A>
A StackADT<A>::pop() {
    if (!isEmpty()) {
        A r = arr[top];
        top--;
        return r;
    } else {
        cout << "Stack Underflow error\n";
        return A(); // Return default value of type A
    }
}

template <class A>
bool StackADT<A>::isEmpty() {
    return top == -1;
}

template <class A>
bool StackADT<A>::isFull() {
    return top == n - 1;
}

template <class A>
A StackADT<A>::peekTop() {
    if (!isEmpty()) {
        return arr[top];
    } else {
        cout << "Stack is Empty\n";
        return A(); // Return default value of type A
    }
}

template <class A>
void StackADT<A>::display() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = 0; i <= top; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the stack: ";
    cin >> size;

    StackADT<int> stack(size);

    int choice;
    do {
        cout << "\nMenu\n";
        cout << "1. Push\n2. Pop\n3. IsEmpty\n4. IsFull\n5. PeekTop\n6. Display\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            }

            case 2: {
                int popped = stack.pop();
                cout << "Popped element: " << popped << endl;
                break;
            }

            case 3: {
                if (stack.isEmpty()) {
                    cout << "Stack is Empty" << endl;
                } else {
                    cout << "Stack is not Empty" << endl;
                }
                break;
            }

            case 4: {
                if (stack.isFull()) {
                    cout << "Stack is Full" << endl;
                } else {
                    cout << "Stack is not Full" << endl;
                }
                break;
            }

            case 5: {
                if (!stack.isEmpty()) {
                    int peek = stack.peekTop();
                    cout << "Peek Top element is: " << peek << endl;
                }
                break;
            }

            case 6: {
                stack.display();
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
