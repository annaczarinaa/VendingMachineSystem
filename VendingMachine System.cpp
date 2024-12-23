#include <iostream>
#include <iomanip>
using namespace std;

// Global variables
string items[5] = {"Coke", "Sprite", "Royal", "Sting", "Mountain Dew"};
int price[5] = {20, 20, 20, 20, 25};
int quantity[5] = {100, 100, 100, 100, 100};
int balance = 0; // Initialize balance

void Operate();
void Display_Items();
void Insert_Coins();
void Buy_Product();

int main() {
    Operate();
    return 0;
}
void Operate() {
    int choice;
    do {
        // Display the main menu
        cout << "\n\n\n\t\t\t\t\t\tWelcome to the Vending Machine\n";
        for (int a = 0; a <= 132; a++) {
            cout << "_";
        }
        cout << "\n\n\n\t\t1. Buy Product\t\t\t\t\t\t\t2. Exit\n";
        
        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            
            case 1:
                Buy_Product();
                break;
            
            case 2:
                cout << "Thank you for using the vending machine. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please select a valid option.\n";
        }
    } while (choice != 2); // Exit when the user selects 2
}

void Display_Items() {
    cout << "\n\n\n\t\t\t\t\t\t******** Available Products ********\n";
    for (int a = 0; a <= 132; a++) {
        cout << "_";
    }
    cout << "\n\n\n\t\t1. " << items[0] << " (PHP " << price[0] << ") - Stock: " << quantity[0]
         << "\t\t\t\t\t2. " << items[1] << " (PHP " << price[1] << ") - Stock: " << quantity[1] << "\n";
    cout << "\n\n\n\t\t3. " << items[2] << " (PHP " << price[2] << ") - Stock: " << quantity[2]
         << "\t\t\t\t\t4. " << items[3] << " (PHP " << price[3] << ") - Stock: " << quantity[3] << "\n";
    cout << "\n\n\n\t\t\t\t\t\t5. " << items[4] << " (PHP " << price[4] << ") - Stock: " << quantity[4] << "\n";
}

void Insert_Coins() {
    int amount;
    cout << "\n\nInsert a coins: PHP ";
    cin >> amount;
  
        balance += amount;
        cout << "Coins successufully inserted PHP: " << amount << endl;  
}
void Buy_Product() {
    Display_Items();
     Insert_Coins();
    int choice;
    cout << "\n\nEnter the product number you want to buy (1-5): ";
    cin >> choice;
    int index = choice - 1;
    if (index < 0 || index > 4) {
        cout << "Invalid choice. Please select a valid product.\n";
    } else if (quantity[index] <= 0) {
        cout << "Sorry, " << items[index] << " is out of stock.\n";
    } else {
        cout << "You selected " << items[index] << ". Price: PHP " << price[index] << endl;
        cout << "Enter the quantity to buy: ";
        int quantityToBuy;
        cin >> quantityToBuy;

        if (quantityToBuy <= 0) {
            cout << "Invalid quantity.\n";
        } else if (quantityToBuy > quantity[index]) {
            cout << "Not enough stock available.\n";
        } else {
            int totalPrice = price[index] * quantityToBuy;
            if (balance < totalPrice) {
                cout << "Insufficient balance. You need PHP " << totalPrice - balance << " more.\n";
            } else {
                balance -= totalPrice;
                quantity[index] -= quantityToBuy;
                cout << "Purchase successful! You bought " << quantityToBuy << " " << items[index] << "(s).\n";    
            }
        }
    }
}