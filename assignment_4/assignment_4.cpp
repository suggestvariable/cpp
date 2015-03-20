/***********************
AcmePayroll.cpp
Version 1.0
Project 1
This program is for Acme Incorporated
This program functions as a payroll calculator
***********************/

#include <iostream>
#include <iomanip>// for 'fixed' and 'setprecision'

//function displays a greeting
int Welcome()
{
  std::cout << "Welcome to Payroll Calculator for Acme Inc." << std::endl;
  std::cout << "Version 1.0" << std::endl;
  std::cout << "By: Jason Harris" << std::endl << std::endl;
  return 0;
}

//function calculates the pay of salaried employees
double CalculateSalary (double salary)
{
  salary = salary;
  return salary;
}

//function calculates the pay of hourly employees
double CalculateHourly (double hourpay, double hoursworked)
{
  // a variable to hold the calculated pay of hourly employees
  double hourtotalpay = 0;

  // if statement to determine overtime adjustment
  if (hoursworked > 40)
    hourtotalpay = (hourpay * 40) + ((hoursworked - 40) * 
      (hourpay * 1.5));
  else 
    hourtotalpay = hourpay * hoursworked;
  return hourtotalpay;
}

//function calculates the pay of commissioned employees
double CalculateCommission (double commissionsalary, double commission, 
  double sales)
{
  // a variable to hold the calculated pay of commissioned employees
  double commissiontotalpay = 0;
  commissiontotalpay = commissionsalary + ((commission / 100) * sales);
  return commissiontotalpay;
}

//function calculates the pay of employees that create widgets
double CalculateWidget (double widgetpay, int numberofwidgets)
{
  // a variable to hold the calculated pay of widget employees
  double totalwidgetpay = 0;
  totalwidgetpay = widgetpay * numberofwidgets;
  return totalwidgetpay;
}

//function main begins program execution
int main()
{
  // a variable to hold user input
  char selection = '0';
  // a variable to track the total pay of all employees
  double totalpay = 0;
  // a variable to contain the pay of each employee
  double salary = 0;
  // a variable of what hourly employees make per hour
  double hourpay = 0;
  // a variable of how many hours per week hourly employees work
  double hoursworked = 0;
  // a variable of the salary of commissioned employees
  double commissionsalary = 0;
  // a variable of the percentage that commissioned employees make
  double commission = 0;
  // a variable of the number of sales commissioned employees sold
  double sales = 0;
  // a variable of what employees get paid per widget created
  double widgetpay = 0;
  // a variable of the number of widgets an employee created
  int numberofwidgets = 0;

  //call Welcome function
  Welcome();

  //loop to get input from user for employee pay
  while (selection != 'Q')
  {
    //keep a running total of the pay for all employees
    totalpay = totalpay + salary;

    // Display a menu to the user
    std::cout << "Employee Pay Codes:" << std::endl;
    std::cout << "Managers           - (1)" << std::endl;
    std::cout << "Hourly Workers     - (2)" << std::endl;
    std::cout << "Commission Workers - (3)" << std::endl;
    std::cout << "Widget Workers     - (4)" << std::endl;
    std::cout << "Enter pay code ([Q]uit): ";
    std::cin >> selection;

    //input validation for menu
    if ((selection != '1') && (selection != '2') && (selection != '3')
      && (selection != '4') && (selection != 'Q'))
    std::cout << "You typed an invalid pay code.  Please try again."
      << std::endl << std::endl;
      
    // Use a switch statement to detect their option
    switch (selection)
    {
      case '1':			// case 1 calculates manager pay
        std::cout << "Manager selected." << std::endl;
        std::cout << "Enter weekly salary: $";
        std::cin >> salary;

        //call function
        salary = CalculateSalary (salary);

        //display output to user
        std::cout << "Manager's pay is $" << std::setprecision(2) <<
          std::fixed << salary << std::endl << std::endl;
        break;
      case '2':			// case 2 calculates hourly pay
        std::cout << "Hourly Worker selected." << std::endl;
        std::cout << "Enter the hourly pay: $";
        std::cin >> hourpay;
        std::cout << "Enter the total hours worked: ";
        std::cin >> hoursworked;

        //call function
        salary = CalculateHourly (hourpay, hoursworked);

        //display output to user
        std::cout << "Hourly Worker's pay is $" << std::setprecision(2) <<
          std::fixed << salary << std::endl << std::endl;
        break;
      case '3':			// case 3 calculates commissioned pay
        std::cout << "Commission Worker selected." << std::endl;
        std::cout << "Enter weekly salary: $";
        std::cin >> commissionsalary;
        std::cout << "Enter commission (%): ";
        std::cin >> commission;
        std::cout << "Enter gross weekly sales: ";
        std::cin >> sales;

        //call function
        salary = CalculateCommission (commissionsalary, commission, sales);
      
        //display output to user
        std::cout << "Commission Worker's pay is $" << std::setprecision(2) <<
          std::fixed << salary << std::endl << std::endl;
        break;
      case '4':			// case 4 calculates widget pay
        std::cout << "Widget Worker selected." << std::endl;
        std::cout << "Enter pay per widget: $";
        std::cin >> widgetpay;
        std::cout << "Enter number of widgets: ";
        std::cin >> numberofwidgets;

        //call function
        salary = CalculateWidget (widgetpay, numberofwidgets);

        //display output to user
        std::cout << "Widget Worker's pay is $" << std::setprecision(2) <<
          std::fixed << salary << std::endl << std::endl;
        break;
      case 'Q':
        // Do nothing. The while-loop will exit when it evaluates the 
        // expression
        break;
    }
  }
  std::cout << std::endl;
  //Display total pay for all employees and end of program
  std::cout << "Total pay is $" << std::setprecision(2) << std::fixed << 
    totalpay << std::endl;
  std::cout << "Goodbye." << std::endl;
  std::cout << "Press ENTER";
  std::cin.get();
  std::cin.get();
}
// end main