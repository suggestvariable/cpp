// ArrayOperations.cpp
// Version 1.00
// This is a program that tests the functionality of arrays.
// This progam generates 20 random numbers, and then performs
// various functions to manipulate that data.

// DO NOT REMOVE ANY OF THE FOLLOWING CODE THAT
// IS GIVEN TO YOU IN THIS TEMPLATE (including comments)

#include <iostream>
#include <iomanip>
#include <cstdlib>

// Function Prototypes

// Function to get a seed value
void SeedRand(int);
// Function to generate values into array
void InitializeArray(int [], int);
// Function that determines if a given value is present in the array
bool Contains(int [], int, int );
// Function that adds up the elements in the array
int SumArray(int [], int);
// Function that determines the largest value in the array
int Largest(int [], int);
// Function that determines the smallest value in the array
int Smallest(int [], int);
// Function that calculates the average of the values in the array
double Average(int [], int);
// Function that sorts the array from smallest to largest
void BubbleSort(int [], int );

// DO NOT REMOVE THIS LINE OR THE NEXT
//[BEGIN MAIN]
int main()
{
  // This entire main() function will be deleted
  // during the assessment and replaced with
  // another main() function that tests your code.

  // This size may change!
  // Make sure your functions work for any array size.
  const int ARRAY_SIZE = 20;
  int a[ARRAY_SIZE];

  // Develop code here to test your functions
  // You may use std::cout in any tests you develop
  // DO NOT put std::cout statements in any of the
  // provided function skeletons.
  // DO NOT WRITE CODE ABOVE HERE
  // ================================

  // Variable Declarations

  // This is the seeding variable
  int seed;
  // This holds user input on how many tests to perform
  int numTests;
  // This is a randomly generated number that is checked to see
  // if it resides in the array.
  int testValue;  

  // Receives user input for a seed value
  std::cout << "Enter a seed value: ";
  std::cin >> seed;

  // Calls the SeedRand function to seed the random number generator
  SeedRand(seed);

  // Calls the function that generates the random numbers for the array
  InitializeArray(a, ARRAY_SIZE);

  // Displays the numbers in the array
  std::cout << std::endl << "Initial Array: " << std::endl;
  // For loop that displays the values in the array
  for ( int i = 0; i < ARRAY_SIZE; i++ )
    std::cout << a[i] << " ";

  // Calls the function that calculates the sum of all the numbers in
  // the array and displays the sum to the user.
  std::cout << std::endl << std::endl << "The sum of the values is: " 
    << SumArray(a, ARRAY_SIZE) << std::endl;

  // Calls the function that calculates the largest of all the numbers in
  // the array and displays the value to the user.  
  std::cout << "The largest value is: " << Largest(a, ARRAY_SIZE) 
    << std::endl;

  // Calls the function that calculates the smallest of all the numbers in
  // the array and displays the value to the user.  
  std::cout << "The smallest value is: " << Smallest(a, ARRAY_SIZE) 
    << std::endl;

  // Calls the function that calculates the average of all the numbers in
  // the array and displays the value to the user.  
  std::cout << "The average is: " << Average(a, ARRAY_SIZE) << std::endl;

  // Receive input from the user about how many tests to run, to see if
  // a number is contained within the array
  std::cout << std::endl << "How many extra tests do you want to run? ";
  std::cin >> numTests;

  // For loop that iterates through the number of tests received from
  // user, and checks to see if any randomly generated number matches
  // any value in the array.
  for ( int j = 0; j < numTests; j++ )
    {
      // Generate random value
      testValue = 1 + rand() % 100;
      
      // If statement that adds a "0" for numbers 0-9 for formatting
      // purposes.
      if (testValue < 10)

        // Call function to check if there is a match, and display the
        // answer to the user.  There is an If Statement to display
        // "True" if the boolean value returned is TRUE or "False"
        //  if the boolean value returned is FALSE.
        if (Contains(a, ARRAY_SIZE, testValue))
          std::cout << "Contains(0" << testValue << ")=True" 
            << std::endl;
        else 
          std::cout << "Contains(0" << testValue << ")=False" 
            << std::endl;
	  else

        // Call function to check if there is a match, and display the
        // answer to the user.  There is an If Statement to display
        // "True" if the boolean value returned is TRUE or "False"
        //  if the boolean value returned is FALSE.
        if (Contains(a, ARRAY_SIZE, testValue))
          std::cout << "Contains(" << testValue << ")=True" 
            << std::endl;
        else 
          std::cout << "Contains(" << testValue << ")=False" 
            << std::endl;
    }
  
  // Call function to perform a bubble sort on array
  BubbleSort(a, ARRAY_SIZE);
  // Display the sorted array to the user
  std::cout << std::endl << "Sorting..." << std::endl;
  std::cout << "The sorted array is: " <<  std::endl;
  // For loop that iterates through the sorted array
  for ( int k = 0; k < ARRAY_SIZE; k++ )
    std::cout << a[k] << " ";
  std::cout << std::endl;

  // ================================
  // DO NOT WRITE CODE BELOW HERE

  std::cout << "Press ENTER";
  std::cin.get();	
  return 0;
}
// DO NOT REMOVE THIS LINE OR THE NEXT
//[END MAIN]

// Implement all of the following functions
// DO NOT put any std::cout statements in them.
// DO NOT change their signatures
// Implement the required functionality only
// Do all of your coding between these two sections
// in each function:
// ================================
// [Your code here]
// ================================
// Failure to follow these simple rules will result
// in major deductions.
void SeedRand(int x)
{
  // Seed the random number generator with x
  // ================================
  srand( x );
  // ================================
}

void InitializeArray(int a[], int arraySize)
{
  // Develop an algorithm that inserts random numbers
  // between 1 and 100 into a[]
  // ================================
  // For loop that iterates through the array and 
  // generates random numbers
  for ( int i = 0; i < arraySize; i++ )
    a[i] = 1 + rand() % 100;
  // ================================
}

bool Contains(int a[], int arraySize, int testVal)
{
  bool contains = false;
  // Develop a linear search algorithm that tests
  // whether the array contains testVal
  // ================================
  // For loop that iterates through the array
  // and compares whether testVal is part of the 
  // array
  for (int i = 0; i < arraySize; i++)
  {
    if ( a[i] == testVal )
      contains = true;
  }
  // ================================
  return contains;
}

void BubbleSort(int a[], int arraySize)
{
  // Develop an algorithm that performs the bubble sort
  // ================================
  // Declare local variables

  // Variable to hold temporary value for the sorting
  int tempVal;
  // Variable to count through the array elements
  int j = 0;
  // Boolean value to end the loop once the array has been sorted
  bool flag = true;

  // While loop to sort the array
  while (flag)
  {
    // Set the boolean to false
    flag = false;

    // Increment the counter
    ++j;

    // For loop to iterate through the array, sorting it
    for (int i = 0; i < arraySize - j; i++)
    {
      // If statement to compare which array element is greater;
      // this swaps the elements
      if ( a[i] > a[i+1])
      {
        // Assign the value of the lesser number to the temporary
        // placeholder
        tempVal = a[i+1];
        // Assign the greater value to the "right" of it's previous
        // position
        a[i+1] = a[i];
        // Assign the temporary value to the element to the "left"
        a[i] = tempVal;
        // Continue the loop after swapping the elements
        flag = true;
      }
    }
  }
  // ================================
}

int SumArray(int a[], int arraySize)
{
  int sum = 0;
  // Develop an algorithm that sums the entire array
  // and RETURNS the result
  // ================================
  // For loop to add up all the elements in the array
  for ( int i = 0; i < arraySize; i++ )
    sum += a[i];
  // ================================
  return sum;
}

int Largest(int a[], int arraySize)
{
  int largest = a[0];
  // Develop an algorithm to figure out the largest value
  // ================================
  // For loop to iterate through the array, finding the largest value
  for ( int i = 0; i < arraySize; i++ )
    // If statement to assign largest value to "largest" variable
    if ( a[i] > largest)
      largest = a[i];
  // ================================
  return largest;
}

int Smallest(int a[], int arraySize)
{
  int smallest = a[0];
  // Develop an algorithm to figure out the smallest value
  // ================================
  // For loop to iterate through the array, finding the smallest value  
  for ( int i = 0; i < arraySize; i++ )
    // If statement to assign smallest value to "smallest" variable
    if ( a[i] < smallest)
      smallest = a[i];
  // ================================
  return smallest;
}

double Average(int a[], int arraySize)
{
  double average = 0;
  // Develop an algorithm to figure out the average INCLUDING decimals
  // You might find your previous SumArray function useful
  // ================================
  // Declare local variable to hold the sum
  double sum = 0;
  
  // For loop to add up the array elements
  for ( int i = 0; i < arraySize; i++ )
    sum += a[i];

  // Calculate the average
  average = sum / arraySize;
  // ================================
  return average;
}
