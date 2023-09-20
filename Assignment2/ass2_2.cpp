

#include <iostream>

class TollBooth {
private:
    unsigned int totalCars;
    double totalMoney;

public:
    // Constructor to initialize all data members to 0
    TollBooth() {
        totalCars = 0;
        totalMoney = 0.0;
    }

    // Function to handle a paying car
    void payingCar() {
        totalCars++;
        totalMoney += 0.50;
    }

    // Function to handle a non-paying car
    void nopayCar() {
        totalCars++;
    }

    // Function to print the totals
    void printOnConsole() {
        std::cout << "Total Cars: " << totalCars << std::endl;
        std::cout << "Total Money Collected: $" << totalMoney << std::endl;
        std::cout << "Paying Cars: " << totalMoney / 0.50 << std::endl;
        std::cout << "Non-Paying Cars: " << totalCars - (totalMoney / 0.50) << std::endl;
    }
};

int main() {
    TollBooth booth;

    booth.payingCar();
    booth.nopayCar();
    booth.payingCar();
    booth.payingCar();
    booth.nopayCar();

    booth.printOnConsole();

    return 0;
}
