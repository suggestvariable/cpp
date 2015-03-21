/***********************
Assignment 1
***********************/
#include <iostream>

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	int number1;// first integer read from user
	int number2;// second integer read from user
	int number3;// third integer read from user
	int smallest;// smallest integer read from user
	int largest;// largest integer read from user
	int sum;// sum of integers read from user
	double average;// average of integers read from user
	int product;// product of integers read from user

	cout << "Input three different integers: ";// prompt
	cin >> number1 >> number2 >> number3;
	
	largest = number1;// assume first integer is largest
	
	if ( number2 > largest )
		largest = number2;
	if ( number3 > largest )
		largest = number3;

	smallest = number1;// assume first integer is smallest

	if ( number2 < smallest )
		smallest = number2;
	if ( number3 < smallest )
		smallest = number3;

	product = number1 * number2 * number3;
	sum = number1 + number2 + number3;
	average = sum / 3;

	cout << "The answers are: \nLargest=" << largest << "\nSmallest=" 
          << smallest << "\nSum=" << sum << "\nAverage=" << average << "\nProduct=" << product << "\n";

	int done;// This code keeps the command prompt from closing
	cout << "Enter 0 and return when done.\n";
	cin >> done;
	return 0;
}
// end main