/* 
Write a menu driven program to calculate volume of the box.
Provide necessary constructors.*/

#include <iostream>

using namespace std;

class Box {
private:
    double length;
    double width;
    double height;

public:
    
    Box() {
        length = 0.0;
        width = 0.0;
        height = 0.0;
    }

    Box(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }


    double calculateVolume() {
        return length * width * height;
    }

    void setDimensions(double l, double w, double h) {
        length = l;
        width = w;
        height = h;
    }

    void printDimensions() {
        cout << "Length: " << length << " units" << endl;
        cout << "Width: " << width << " units" << endl;
        cout << "Height: " << height << " units" << endl;
    }
};

int main() {
    Box box;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Initialize Box\n";
        cout << "2. Set Dimensions\n";
        cout << "3. Calculate Volume\n";
        cout << "4. Print Dimensions\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                box = Box();
                cout << "Box initialized." << endl;
                break;
            }
            case 2: {
                double length, width, height;
                cout << "Enter Length: ";
                cin >> length;
                cout << "Enter Width: ";
                cin >> width;
                cout << "Enter Height: ";
                cin >> height;
                box.setDimensions(length, width, height);
                cout << "Dimensions set." << endl;
                break;
            }
            case 3: {
                double volume = box.calculateVolume();
                cout << "Volume of the box: " << volume << " cubic units" << endl;
                break;
            }
            case 4: {
                cout << "Box Dimensions:" << endl;
                box.printDimensions();
                break;
            }
            case 5:
                cout << "Exit" << endl;
                return 0; 
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
