#include <iostream>
using namespace std;


int main() {
   cout << "=================================\n";
   cout << "  WELCOME TO SNACC & BITEE !!! \n";
   cout << "=================================\n";

   cout << "1. Shawarma Rice (Regular) - 79\n";
   cout << "2. Shawarma Rice (W/ Fries) - 99\n";
   cout << "3. Burger Patty W/ Rice (Regular) - 49\n";
   cout << "4. Burger Patty W/ Rice (W/ Fries) - 69\n";
   cout << "5. Double Patty W/ Rice (Regular) - 79\n";
   cout << "\n";
   cout << "===== ADD ONS =====\n";
   cout << "6. EXTRA Meat - 25\n";
   cout << "7. EXTRA Java Rice - 20\n";
   cout << "8. EXTRA Garlic MAyo - 15\n";
   cout << "9. EXTRA Melted Cheese - 15\n";
   cout << "10. EXTRA Veggies - 10\n";
   cout << "11. EXTRA Fries - 25\n";

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
   double prices[11] = {79, 99, 49, 69, 79, 25, 20, 15, 15, 10, 25};
   double total;
   char again;
   int choice, qty;

   do {
   cout << "\nEnter the number of item you want to order: ";
   cin >> choice;
   if (choice < 1 || choice > 11){
    cout << "Invalid Choice! Try another.\n";
    continue;
   }

   cout << "Enter Quantity: ";
   cin >> qty;
   quantity[choice - 1] += qty;

   cout << "Do you want to add another item? (Y/N): ";
   cin >> again;
   } while (again == 'Y' || again == 'y'); // it'll repeat if you enter 'Y' or 'y'

   cout << "\n=============================================\n";
   cout << "                    RECEIPT\n";
   cout << "\n=============================================\n";
   cout << "Item\t\t\tqty\tSubtotal\n";
   cout << "\n=============================================\n";

   for (int i = 0; i < 11; i++) {
    if (quantity[i] > 0) {
        double subtotal = prices[i] * quantity[i];
        cout << items[i] << "\t" << quantity[i] << "\tP" << subtotal << endl;
        total += subtotal;
    }
   }

    cout << "--------------------------------------------\n";
    cout << "TOTAL:\t\t\t\tP" << total << endl;
    cout << "--------------------------------------------\n";
    cout << "Thank you for ordering at SNACC 'N Bite! Bon Appétit! \n";



   return 0;
}
