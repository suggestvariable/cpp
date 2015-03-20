// PointerOperations.cpp
// Version 1.00
// This program manipulates strings, and uses pointers to do so.

#include <iostream>
#include <stdlib.h>
#include <time.h>

// Function Prototypes=========================================================
// Do NOT change the signature of these function prototypes.
// If you do, your code will not compile with my altered main() function
// I suggest that you copy the prototypes below and then fill them in.
// ----------------------------------------------------------------------------
// Read in a line of text INCLUDING SPACES into a string.
// You may assume that the input will NOT exceed the maxLength available.
// Keep in mind that cin stops reading at a whitespace. See page 318.
void ReadString(char * c, int maxLength);

// Get the length of the string and store it in length
// Hint: How does C++ terminate a string? Look for that character!
void GetStringLength(char * c, int * len);

// PrintString - Just print the string in forward order using cout
void PrintString(char * const c);

// PrintStringBackwards - Print the string in reverse order using cout
void PrintStringBackwards(char * const c);

// Return a pointer to the character at the index given
char * GetValueAtIndex(char * const c, int index);

// Return true/false if the string contains the testVal
bool SearchString(char * c, char testVal);
// ============================================================================

//[BEGIN MAIN] -- Don't delete this line
int main()
{
  // Use these variables to test.
  // SIZE could change so make sure your code works with different sizes.
    
  const int SIZE = 100;
  char ca[SIZE];
  char * pc = ca;
    
  // Your code below
  // =========================
  // Variable declarations
    
  // Variable for length of string
  int length = 0;
    
  // Pointer for length
  int * lenPtr = &length;
    
  // Seed value for random generation
  srand((unsigned) time(0));
    
  // Variable to randomly generate a value
  int r = rand() % 52;
    
  // Variable to hold random letter
  char testValue = r + 'A';
    
  // variable for index value
  int index = 0;
    
  // Call pointer function to get string input
  ReadString(pc, SIZE);
    
  // Display to user
  std::cout << "Forward: ";
    
  // Call pointer function to display string
  PrintString(pc);
    
  // Display to user
  std::cout << "Backward: ";
    
  // Call pointer function to display string backwards
  PrintStringBackwards(pc);
    
  // Call pointer function to calculate length of string
  GetStringLength(pc, lenPtr);
    
  // Display length to user
  std::cout << "Length: " << length << std::endl;
    
  // If statement for formatting purposes
  if (SearchString(pc, testValue))    
    std::cout << "Contains(" << testValue << ")=True"
    << std::endl;
  else
    std::cout << "Contains(" << testValue << ")=False"
    << std::endl;
    
  // Change index value randomly to prepare for index calculation
  index = rand() % length;
    
  // Display and call the function for the value at the index
  std::cout << "Character at index " << index << ": "
    
  << *GetValueAtIndex(pc, index) << std::endl;
    
  // =========================
  // Your code above
    
  std::cout << "Press ENTER";
  std::cin.get();
  return 0;
}
//[END MAIN] -- Don't delete this line

// Function to get string input from user
void ReadString(char * c, int maxLength)
{
  std::cout << "Enter a string less than " << maxLength << " characters." 
    << std::endl;
    
  // Your code here
  // ==============================
  std::cin.getline( c, maxLength);
  // ==============================
}

// You need to provide the rest of the functions
// See Function Prototypes at the top.

// Function to calculate string length
void GetStringLength(char * const c, int * len)
{
  // For loop to count through the loop, adding up the length
  for (int i = 0; c[i] !='\0'; i++)
    *len = i+1;
}

// Function to simply display the string on screen
void PrintString(char * const c)
{
  std::cout << c << std::endl;
}

// Function to display the string backwards
void PrintStringBackwards(char * const c)
{
  // Variable declartion for counter
  int i=0;
    
  // Loop that looks for the end of the string
  while (c[i] != '\0')
    i++;
    
  // Once the end is found, move back one space
  i--;
    
  // For loop to display string backwards
  for (int k = 0; c[k] != '\0'; k++)    
  {
    std::cout << c[i];
    i--;
  }
    
  std::cout << std::endl;
}

// Function to see if value index is present in string
char * GetValueAtIndex(char * const c, int index)
{
  // Declare Pointer Variable
  char *GetValuePtr = &c[index];
        
  return GetValuePtr;
}

//Function to test if a character is present in string
bool SearchString(char * c, char testVal)
{
  // Declare boolean variable
  bool SearchString = false;
    
  // For loop to count through the array pointer
  for (int i = 0; c[i]!='\0'; i++)
  {
    if ( c[i] == testVal )
      SearchString = true;
  }
    
  return SearchString;
}