#include <iostream>
using namespace std;

class Stack {
    int top;
    int size;
    int *arr;

public:
    Stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return;
        }
        top--;
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == size - 1;
    }

    void display() {
        if (top == -1) {
            cout << "Stack is Empty\n";
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();

    cout << "Top element: " << st.peek() << endl;

    st.pop();
    st.display();

    return 0;
}