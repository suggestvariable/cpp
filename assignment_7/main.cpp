 // Main.cpp
 // Version 1.00
 // This is a program that calculates mean and median.
 
 #include <iostream>
 #include <stdlib.h> 
 #include "stats.h"
 
 int main()
 {
   // Variable Declarations
 
   // This is the maximum size the array can be
   const int MAXSIZE = 100;
   // This is the array
   int array[ MAXSIZE ];
   // This hold the input from the user
   int input = 0;
   size_t index = 0;
 
   // Output text to user
   std::cout << "Enter integers ('x' to quit): ";
 
   // Loop to receive input from user
   while( std::cin >> input && index < 100)
   {
     array[index] = input;
     ++index;
   }
 
   std::cout << std::endl;
 
   // Output text to user
   std::cout << "Data as entered: ";
 
   // For loop to display the integers entered
   for (size_t i = 0; i < index; i++)
   {
     std::cout << array[i] << " ";
   }
 
   std::cout << std::endl;
 
   // Call Mean Function
   std::cout << "Mean: " << Mean(array, index) << std::endl;
 
   // Call Median Function
   std::cout << "Median: " << Median(array, index) << std::endl;
 
   // Output text to user
   std::cout << "Data after sort: ";
 
   // For loop to display the integers sorted
   for (size_t j = 0; j < index; j++)
   {
     std::cout << array[j] << " ";
   }
 
   std::cout << std::endl;
 
   return 0;
 }