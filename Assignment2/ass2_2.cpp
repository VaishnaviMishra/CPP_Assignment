/*Imagine a tollbooth at a bridge. Cars passing by the booth are
expected to pay a fifty-cent toll. Mostly they do, but sometimes a car
goes by without paying.
The tollbooth keeps track of the number of cars that have gone by
and of the total amount of money collected. Model this tollbooth
with a class called tollbooth.
The two data items are a type unsigned int to hold the total number
of cars, and a type double to hold the total amount of money
collected.
A constructor initializes all data members to 0.
A member function called payingCar() increments the car total and
adds 0.50 to the cash total. Another function, called nopayCar()
increments the car total but adds nothing to the cash total.
Finally, a member function called printOnConsole() displays the two
totals and number of paying as well as non paying cars total.*/

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
