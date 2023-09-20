#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int size;
    int top;

public:
   
    Stack(int stackSize = 5) {
        size = stackSize;
        arr = new int[size];
        top = -1;
    }

    
    ~Stack() {
        delete[] arr;
    }

    
    void push(int value) {
        if (isFull()) {
            std::cout << "Stack is full. Cannot push." << std::endl;
            return;
        }
        arr[++top] = value;
    }

    
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
            return;
        }
        --top;
    }

    
    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot peek." << std::endl;
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

    
    void print() {
        if (isEmpty()) {
            std::cout << "Stack is empty." << std::endl;
            return;
        }
        std::cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    
    Stack stack(5);

    
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    
    stack.print();

   
    int topElement = stack.peek();
    if (topElement != -1) {
        std::cout << "Top element: " << topElement << std::endl;
    }

    
    stack.pop();

    
    stack.print();

    return 0;
}