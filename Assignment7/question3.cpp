#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

enum class AccountType {
    SAVINGS,
    CURRENT,
    FIXED_DEPOSIT
};

class InsufficientFunds : public std::exception {
public:
    InsufficientFunds(double balance, double amount) : balance(balance), amount(amount) {}

    const char* what() const noexcept override {
        return "Insufficient funds.";
    }

    double getBalance() const {
        return balance;
    }

    double getAmount() const {
        return amount;
    }

private:
    double balance;
    double amount;
};

class Account {
public:
    Account(const std::string& accNumber, const std::string& accHolder, AccountType accType, double balance = 0)
        : accNumber(accNumber), accHolder(accHolder), accType(accType), balance(balance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be greater than zero.");
        }
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw std::invalid_argument("Amount must be greater than zero.");
        }
        if (balance < amount) {
            throw InsufficientFunds(balance, amount);
        }
        balance -= amount;
    }

    double getBalance() const {
        return balance;
    }

    const std::string& getAccNumber() const {
        return accNumber;
    }

    const std::string& getAccHolder() const {
        return accHolder;
    }

    AccountType getAccType() const {
        return accType;
    }

private:
    std::string accNumber;
    std::string accHolder;
    AccountType accType;
    double balance;
};

int main() {
    std::vector<Account> accounts;

    for (int i = 0; i < 5; ++i) {
        std::cout << "Enter details for Account " << i + 1 << std::endl;
        std::string accNumber, accHolder;
        AccountType accType;

        std::cout << "Account Number: ";
        std::cin >> accNumber;
        std::cout << "Account Holder: ";
        std::cin >> accHolder;
        int accTypeChoice;
        std::cout << "Account Types: 0. Savings, 1. Current, 2. Fixed Deposit" << std::endl;
        std::cout << "Select Account Type: ";
        std::cin >> accTypeChoice;
        accType = static_cast<AccountType>(accTypeChoice);

        accounts.emplace_back(accNumber, accHolder, accType);
    }

    while (true) {
        std::cout << "\nMenu:" << std::endl;
        std::cout << "1. Deposit" << std::endl;
        std::cout << "2. Withdraw" << std::endl;
        std::cout << "3. Exit" << std::endl;
        int choice;
        std::cout << "Select an option: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string accNumber;
            double amount;
            std::cout << "Enter Account Number: ";
            std::cin >> accNumber;
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            
            for (auto& account : accounts) {
                if (account.getAccNumber() == accNumber) {
                    account.deposit(amount);
                    std::cout << "Deposit successful. Updated balance: " << account.getBalance() << std::endl;
                    break;
                }
            }
        } else if (choice == 2) {
            std::string accNumber;
            double amount;
            std::cout << "Enter Account Number: ";
            std::cin >> accNumber;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            
            for (auto& account : accounts) {
                if (account.getAccNumber() == accNumber) {
                    try {
                        account.withdraw(amount);
                        std::cout << "Withdrawal successful. Updated balance: " << account.getBalance() << std::endl;
                    } catch (const InsufficientFunds& e) {
                        std::cout << e.what() << " Available balance: " << e.getBalance() << ", Required: " << e.getAmount() << std::endl;
                    }
                    break;
                }
            }
        } else if (choice == 3) {
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }}