 // Stats.cpp
 // Version 1.00
 // This is a program that calculates mean and median.
 // Stats.cpp holds the functions
 
 #include <stdlib.h> 
 #include "stats.h"
 
 // This function calculates the mean
 float Mean(const int* array, size_t size)
 {
   // Declare variable to hold mean
   float mean = 0;
 
   // For loop to count the sum
   for (size_t j = 0; j < size; j++)
     mean = mean + array[j];
 
   mean = mean / size;
  
   return mean;
 }
 
 // This function calculates the median
 float Median(int* array, size_t size)
 {
   // Call the Sort Function
   Sort(array,size);
 
   // Declare variable to hold median value
   float median = 0;
  
   // If statement to determine if even or odd
   if (size % 2 == 0)
     median = 1.0 * ((array[size/2 - 1]) + (array[size/2])) / 2;
   else
     median = 1.0 * (array[(size-1)/2]);
 
   return median;
 }
 
 // This function sorts the data in the array
 void  Sort(int* array, size_t size)
 {
   // Delcare variables
   size_t OuterLoop, InnerLoop;
  
   // Iterate through two loops to exchange values
   for (OuterLoop=0; OuterLoop < size ; OuterLoop++)
   {
     for (InnerLoop = OuterLoop + 1; InnerLoop < size; InnerLoop++)
     {       
       if(array[InnerLoop] < array[OuterLoop])
         // Call Swap Function
         Swap(array[OuterLoop],array[InnerLoop]);
     }
   }
 }
 
 // This function swaps out the x and y values of the array
 void  Swap(int& x, int& y)
 {
   // Declare variable
   size_t loop = 0;
  
   // Swap x and y
   loop=x;
   x=y;
   y=loop;
 }