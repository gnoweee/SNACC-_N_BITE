#include <iostream>
#include <iomanip>
using namespace std;
int main() {
cout << "===========================\n";
cout << "WELCOME TO SNACC 'N BITE\n"; 
cout << "===========================\n";

cout << "\n GET 20% DISCOUNT IF YOUR ORDER IS ₱500 OR ABOVE! \n";
    
    cout << "\n===== MAIN MENU =====\n";
    cout << "1. Shawarma Rice (Regular) - ₱79\n";
    cout << "2. Shawarma Rice (W/ Fries) - ₱99\n";
    cout << "3. Burger Patty W/ Rice (Regular) - ₱49\n";
    cout << "4. Burger Patty W/ Rice (W/ Fries) - ₱69\n";
    cout << "5. Double Patty W/ Rice (Regular) - ₱79\n";
    cout << "\n===== ADD ONS =====\n";
    cout << "6. EXTRA Meat - ₱25\n";
    cout << "7. EXTRA Java Rice - ₱20\n";
    cout << "8. EXTRA Garlic Mayo - ₱15\n";
    cout << "9. EXTRA Melted Cheese - ₱15\n";
    cout << "10. EXTRA Veggies - ₱10\n";
    cout << "11. EXTRA Fries - ₱25\n";

  string items[11] = {
  "Shawarma Rice (Regular)",
  "Shawarma Rice (With Fries)",
  "Burger Patty w/ Rice (Regular)",
  "Burger Patty w/ Rice (With Fries)",
  "Double Patty w/ Rice",
  "EXTRA Meat",
  "EXTRA Java Rice",
  "EXTRA Garlic Mayo",
  "EXTRA Melted Cheese",
  "EXTRA Veggies",
  "EXTRA Fries"
  };

  int quantity[11] = {0};
  double price[11] = {79, 99, 49, 69, 79, 25, 20, 15, 15, 10, 25};
  int choice, qty;
  char again = 'Y';
  

// Ordering Section
  do {
    cout << "\nEnter the number of item you want to order: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 11 ) {
      cin.clear();
      cin.ignore (1000, '\n');
      cout << "Invalid Choice! Please Try Another.\n";
      continue;
    }
    cout << "Enter Quantity: ";
  cin >> qty;
  if (cin.fail() || qty <= 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Quantity! Please Enter a positive number.\n" ;
      continue;
  }
  quantity[choice - 1] += qty;

  cout << "Do you want to Add another Item? (Y/N):" ;
  cin >> again;

      
    // View menu again option
    if (again == 'Y' || again == 'y') {
        cout << " \nWould you like to see the menu again? (Y/N): ";
        char viewMenu;
        cin >> viewMenu; 
        if (viewMenu == 'Y' || viewMenu == 'y') {
             cout << "\n===== MAIN MENU =====\n";
    cout << "1. Shawarma Rice (Regular) - ₱79\n";
    cout << "2. Shawarma Rice (W/ Fries) - ₱99\n";
    cout << "3. Burger Patty W/ Rice (Regular) - ₱49\n";
    cout << "4. Burger Patty W/ Rice (W/ Fries) - ₱69\n";
    cout << "5. Double Patty W/ Rice (Regular) - ₱79\n";
    cout << "\n===== ADD ONS =====\n";
    cout << "6. EXTRA Meat - ₱25\n";
    cout << "7. EXTRA Java Rice - ₱20\n";
    cout << "8. EXTRA Garlic Mayo - ₱15\n";
    cout << "9. EXTRA Melted Cheese - ₱15\n";
    cout << "10. EXTRA Veggies - ₱10\n";
    cout << "11. EXTRA Fries - ₱25\n";
        }
    }
  } while (again == 'Y' || again == 'y');

// Edit section
    char editChoice = 'Y';
    while (editChoice == 'Y' || editChoice == 'y') {
        cout << "\nDo you want to remove or change an item  before finalizing? (Y/N): ";
        cin >> editChoice;
        if (editChoice == 'Y' || editChoice == 'y') {
            cout <<"\nEnter the item you want to change or remove: ";
            int removeItem;
            cin >> removeItem;

        if (removeItem >= 1 && removeItem <= 11 && quantity[removeItem - 1] > 0 ) {
            cout << "Current quantity for " << items[removeItem - 1] << ":" << quantity[removeItem - 1] << endl;
            cout << "Enter new quantity (0 to remove completely): ";
            int newQty;
            cin >> newQty;
            
            if (newQty >= 0) {
                quantity[removeItem - 1] = newQty;
                cout << "Item updated successfully!\n";
                } else {
                  cout << "Invalid quantity!\n";
                }
        } else {
            cout << "Invalid item number or item not yet ordered.\n" ;
        }
        }
    }
// Receipt section
    cout << fixed << setprecision(2);
    cout << "\n=============================================\n";
    cout << "                   RECEIPT\n";
    cout << "=============================================\n";
    cout  << left << setw(30) << "Item" << setw(10) << "Qty" << "Subtotal\n";
    cout << "---------------------------------------------\n";

    double total = 0;
    for (int i = 0; i < 11; i++) {
        if (quantity[i] > 0) {
        double subtotal = price[i] * quantity[i];
     cout << left << setw(30) << items[i]
     << setw(10) << quantity [i]
     << "₱" << subtotal << endl;
            total += subtotal;
        }
    }
    cout << "---------------------------------------------\n";
    cout << right << setw(35) << "TOTAL: ₱" << total << endl;

 // tax/discount section
double taxRate = 0.12;
double discountRate = 0.20;
double tax = total * taxRate; 
double discount = 0;

if (total >= 500) {
discount = total * discountRate;
}
double finalTotal = total + tax - discount;
cout << "Tax (12%): ₱" << tax << endl;
    if (discount > 0)
        cout << "Discount (20%): -₱" << discount << endl;
    cout << "---------------------------------------------\n";
    cout << right << setw(35) << "FINAL TOTAL: ₱" << finalTotal << endl;
    cout << "---------------------------------------------\n";

// payment section
    double payment = 0, change = 0;

while (true) {
    cout << "Enter amount paid: ₱";
    cin >> payment;
    if (cin.fail() || payment < finalTotal) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Insufficient/Invalid payment. Please pay at least ₱" << finalTotal << ".\n";
    } else {
        change = payment - finalTotal;
        break;   
    }
    
}
    cout << "Change: \t\t\t₱" << change << endl;
    cout << "=============================================\n";
    cout << "Thank you for ordering at SNACC 'N BITE!\n";
    cout << "Have a great day! Enjoy your food!\n";

    return 0;
}
