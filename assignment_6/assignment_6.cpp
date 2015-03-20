// FileOperations.cpp
// Version 1.01
// This is a bank application.  It reads data from a file about bank accounts
// and then either calculates interest earnings for positive accounts or
// charges interest on negative accounts.

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// Function prototypes
// Function to perform calculations
void ProcessAccounts(std::ifstream &ifile, std::ofstream &ofile, double);
// Function to print the contents of the file
void PrintFileContents(std::ifstream &str);
// Function to go to the beginning of the file
void SetInputStreamPos(std::ifstream &str, int pos);
// Function to go to the beginning of the file
void SetOutputStreamPos(std::ofstream &str, int pos);
// Function to check if Output file exists, and open it
std::ofstream GetOutputFile(std::string filename);
// Function to check if Input file exists, and open it
std::ifstream GetInputFile(std::string filename);

//[BEGIN MAIN]
int main()
{
  // Declare variables
  // String to hold filename of input file
  std::string inputFileName;
  // String to hold filename of output file
  std::string outputFileName;
  // Variable of the interest rate
  double interestRate;
    
  // Display infomation to user and receive input
  std::cout << "Enter an input filename: ";
  std::cin >> inputFileName;
  std::cout << "Enter an output filename: ";
  std::cin >> outputFileName;
  std::cout << "Enter an interest rate (%): ";
  std::cin >> interestRate;
    
  std::cout << std::endl;
  // Call function and assign variable
  std::ifstream ifile = GetInputFile(inputFileName);
  // Call function and assign variable
  std::ofstream ofile = GetOutputFile(outputFileName);
    
  std::cout << "Current account status:" << std::endl;
  // Call function
  PrintFileContents(ifile);
  
  // Call function
  ProcessAccounts(ifile, ofile, interestRate);
  
  // Close out files
  ifile.close();
  ofile.close();
   
  std::cout << std::endl;
  std::cout << "New account status:" << std::endl;
  // Call function and assign to variable
  ifile = GetInputFile(outputFileName);
  
  // Call function
  PrintFileContents(ifile);
    
  // Close out file
  ifile.close();
    
  std::cout << "Press ENTER";
  std::cin.ignore();
  std::cin.get();
  return 0;
}
//[END MAIN]

void ProcessAccounts(std::ifstream &ifile, std::ofstream &ofile, double rate)
{
  // Everyday the bank checks the status of the accounts and processes them
  // If the customer has:
  // 1) a positive savings balance, pay them interest
  // 2) a negative savings balance, transfer it to credit (credit is positive)
  // 3) a credit balance, charge them interest
  // Note: Unlike normal banks, the interest rate for savings and credit is the same
    
  // Read the info from the input file
  // Put the new info into the output file
  // The format for the input file and output file should be
  // [NAME] [SAVINGS BALANCE] [CREDIT BALANCE]
  // There is a single space between each value and a newline at the end
    
  // Put your code here

  // Call function to go to beginning of files
  SetInputStreamPos(ifile, 0);
  SetOutputStreamPos(ofile, 0);

  // Declare local variables
  std::string name;
  double savings;
  double credit;

  // Loop to process through file, performing calculations
  while ( ifile >> name >> savings >> credit )
    {
      if (savings > 0 )
        // Add interest earnings to accounts that have positive balance
        savings = savings * (rate * .01) + savings;
      else
      {
        // Move negative accounts over to credit accounts
        credit = credit - savings;
        savings = 0;
      }
      if (credit > 0)
        // Add interest to credit accounts
        credit = credit * (rate * .01) + credit;
		
      // Process data to output file
      ofile << name << " " << savings << " " << credit << std::endl;
    }
}

void PrintFileContents(std::ifstream &str)
{
  // Print the contents of the file
  // First, print the file headers
  // Then, print each line.
  // Make sure the text is properly formatted
  // Remember the functions available in iomanip?
    
  // EXAMPLE:
  // Name      Savings   Credit
  // Bob        $23.56   $0.00
  // Joe        $43.52   $0.00
  // Sally     -$1.58    $0.00
    
  // Put your code here
  // Call function to go to beginning of file
  SetInputStreamPos(str, 0);

  // Declare local variables
  std::string name;
  double savings;
  double credit;

  // Print headers
  std::cout << std::left << std::setw( 10 ) << "Name" << std::setw( 10 ) 
    << "Savings" << std::setw( 7 ) << "Credit" << std::endl;
  
  // Loop to process through file and print data
  while ( str >> name >> savings >> credit )
  {
    if (savings < 0) 
      // Formatting issues on negative accounts
      std::cout << std::left << std::setw( 10 ) << name << "-$" 
        << std::setw( 8 ) << std::setprecision(2) << std::fixed << -savings;
    else
      std::cout << std::left << std::setw( 11 ) << name << "$" 
        << std::setw( 8 ) << std::setprecision(2) << std::fixed << savings;

    std::cout	<< "$" << std::setw( 6 ) << std::setprecision(2) << std::fixed 
      << credit << std::endl;
  }
}

std::ifstream GetInputFile(std::string filename)
{
  // Open the file named filename
  // Make sure it exists
  // Return it as an input file stream
    
  // Put your code here

  // Declare local variable
  std::ifstream inFilename(filename);

  // If file doesn't exist, display error
  if ( !inFilename )
  {
    std::cerr << "File could not be opened" << std::endl;
    exit( 1 );
  }
  return inFilename;
}

std::ofstream GetOutputFile(std::string filename)
{
  // Open the file named filename
  // Make sure it exists
  // Return it as an output file stream
  
  // Put your code here

  // Declare local variable
  std::ofstream outFilename(filename);

  // If file doesn't exist, display error
  if ( !outFilename )
  {
    std::cerr << "File could not be opened" << std::endl;
    exit( 1 );
  }
  return outFilename;
}

void SetInputStreamPos(std::ifstream &str, int pos)
{
  // Set the 'g'et cursor to the desired byte in the stream
  // Use the beginning of the file as the reference point
    
  // Put your code here
  // Go to beginning of file
  str.clear();
  str.seekg( pos );
}

void SetOutputStreamPos(std::ofstream &str, int pos)
{
  // Set the 'p'ut cursor to the desired byte in the stream
  // Use the beginning of the file as the reference point
    
  // Put your code here
  // Go to beginning of file
  str.clear();
  str.seekp ( pos );
}