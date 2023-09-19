#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T>
class Array {
private:
    T* elements;
    int size;
    int capacity;

public:
    Array(int capacity) : size(0), capacity(capacity) {
        if (capacity <= 0) {
            throw invalid_argument("Capacity must be greater than zero");
        }
        elements = new T[capacity];
    }

    ~Array() {
        delete[] elements;
    }

    void addElement(const T& element) {
        if (size < capacity) {
            elements[size] = element;
            size++;
        } else {
            throw overflow_error("Array is full");
        }
    }

    T getElement(int index) const {
        if (index >= 0 && index < size) {
            return elements[index];
        } else {
            throw out_of_range("Index out of range");
        }
    }

    void deleteElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                elements[i] = elements[i + 1];
            }
            size--;
        } else {
            throw out_of_range("Index out of range");
        }
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    void displayElements() const {
        for (int i = 0; i < size; ++i) {
            cout << "Element[" << i << "]: " << elements[i] << endl;
        }
    }
};

int main() {
    try {
        // Create an array of integers with a capacity of 5
        Array<int> intArray(5);

        intArray.addElement(10);
        intArray.addElement(20);
        intArray.addElement(30);
        intArray.addElement(40);
        intArray.addElement(50);

        intArray.displayElements();

        int index = 2;
        cout << "Element at index " << index << ": " << intArray.getElement(index) << endl;

        intArray.deleteElement(1);
        cout << "After deleting element at index 1:" << endl;
        intArray.displayElements();

       

    } catch (const exception& e) {
        cerr << "Error: "  << endl;
    }

    return 0;
}
