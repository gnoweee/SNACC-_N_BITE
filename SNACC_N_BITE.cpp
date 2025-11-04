#input <iostream>

using namespace std;
int main() {
cout << "===========================\n";
cout << "WELCOME TO SNACC 'N BITE\n"; 
cout << "===========================\n";

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

  int quatity[11] = {0};
  double price[11] = {79, 99, 49, 69, 79, 25, 20, 15, 15, 10, 25};
  int choice;
  
  do {
    cout << "\n Enter the number of item you want to order: ";
    cin >> choice;

    if (cin.fail() || choice < 1 || choice > 11 ) {
      cin.clear();
      cin.ignore (1000, '\n');
      cout << "Invalid Choice! Please Try Another. \n";
      continue;
    }
  }
    cout << "Enter Quantity: ";
  cin >> choice;
  if (cin.fail() || qty <= 0) {
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid Quantity! Please Enter a positive number. \n;
      continue;
  }
  quantity[choice - 1] += qty;

}
