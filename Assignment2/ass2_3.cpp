

#include <iostream>
#include <string>


namespace NStudent {
    
    class Student {
    private:
        int rollNo;
        std::string name;
        float marks;

    public:
        
        Student() {
            rollNo = 0;
            name = "";
            marks = 0.0;
        }

       
        void initStudent() {
            std::cout << "Enter Roll No: ";
            std::cin >> rollNo;
            std::cin.ignore(); 
            std::cout << "Enter Name: ";
            std::getline(std::cin, name);
            std::cout << "Enter Marks: ";
            std::cin >> marks;
        }

        
        void printStudentOnConsole() {
            std::cout << "Roll No: " << rollNo << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Marks: " << marks << std::endl;
        }

        
        void acceptStudentFromConsole() {
            initStudent();
        }
    };
}

int main() {
   
    NStudent::Student student;

    int choice;

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Initialize Student\n";
        std::cout << "2. Print Student\n";
        std::cout << "3. Accept Student\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                student.initStudent();
                std::cout << "Student initialized." << std::endl;
                break;
            case 2:
                student.printStudentOnConsole();
                break;
            case 3:
                student.acceptStudentFromConsole();
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
