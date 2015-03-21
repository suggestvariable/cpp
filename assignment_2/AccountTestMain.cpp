/***********************
AccountTestMain.cpp
Assignment 3
This program functions as an ATM.  You can see account balances and make 
withdrawls or transfers.
***********************/

#include <iostream>
#include <iomanip>// for 'fixed' and 'setprecision'

//function main begins program execution
int main()
{
  // declare account balances
  double account1 = 100;
  double account2 = 50;

  // display initial balance of each account
  std::cout << "Account 1 balance: $" << std::setprecision(2) << std::fixed 
    << account1 << std::endl;
  std::cout << "Account 2 balance: $" << std::setprecision(2) << std::fixed 
    << account2 << std::endl;

  // a variable to hold their choice
  int selection = 0;
  // a variable to track the number of transactions
  int transaction = 0;
	
  while (selection != 5)
  {
    // declare variable for user input
    int amount = 0;

    // Display a menu to the user
    std::cout << "(1) to debit account 1" << std::endl;
    std::cout << "(2) to debit account 2" << std::endl;
    std::cout << "(3) to transfer from account 1 to 2" << std::endl;
    std::cout << "(4) to transfer from account 2 to 1" << std::endl;
    std::cout << "(5) to exit" << std::endl; // sentinel value

    // Ask the user for their choice
    std::cout << "What would you like to do? ";
    std::cin >> selection;
    
    // Use a switch statement to detect their option
    switch (selection)
    {
      case 1:  // case 1 debits account 1
        std::cout << "Enter withdrawal amount for Account 1: ";
        std::cin >> amount;
        if ( amount <= account1 )
        {
          std::cout << "Subracting " << amount << " from Account 1 balance." 
            << std::endl;
          account1 = account1 - amount;
        }
        else
          std::cout << "Error: Debit amount exceeds balance." << std::endl;
        break;
      case 2:  // case 2 debits account 2
        std::cout << "Enter withdrawal amount for Account 2: ";
        std::cin >> amount;
        if ( amount <= account2 )
        {
          std::cout << "Subracting " << amount << " from Account 2 balance." 
            << std::endl;
          account2 = account2 - amount;
        }
        else
          std::cout << "Error: Debit amount exceeds balance." << std::endl;
        break;
      case 3:  // case 3 transfers from account 1 to 2
        std::cout << "Enter transfer amount from Account 1 to 2: ";
        std::cin >> amount;
        if ( amount <= account1 )
        {
          std::cout << "Transferring " << amount 
            << " from Account 1 to Account 2." << std::endl;
          account2 = account2 + amount;
          account1 = account1 - amount;
        }
        else
          std::cout << "Error: Transfer amount exceeds balance." 
            << std::endl;
        break;
      case 4:  // case 4 transfers from account 2 to 1
        std::cout << "Enter transfer amount from Account 2 to 1: ";
        std::cin >> amount;
        if ( amount <= account2 )
        {
          std::cout << "Transferring " << amount 
            << " from Account 2 to Account 1." << std::endl;
          account2 = account2 - amount;
          account1 = account1 + amount;
        }
        else
          std::cout << "Error: Transfer amount exceeds balance." << std::endl;
        break;
      case 5:
        // Do nothing. The while-loop will exit when it evaluates the 
        // expression
        break;
    }

    transaction += 1;
    // display new balances after each transaction


    std::cout << "[" << transaction << "] Account 1 balance: $" 
      << std::setprecision(2) << std::fixed << account1 << std::endl;
    std::cout << "[" << transaction << "] Account 2 balance: $" 
      << std::setprecision(2) << std::fixed << account2 << std::endl;

    std::cout << std::endl;
  }
}
// end main