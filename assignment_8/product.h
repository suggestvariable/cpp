 // product.h
 // Header file that contains the prototypes for
 // the class Product
 
 #include <iostream>
 #include <cstdlib>
 #include <cstdint>
 #include <iomanip>
 
 #ifndef _PRODUCT_H
 #define _PRODUCT_H
 
 class Product
 {
 public:
   // sets the name field
   void SetName ( const char* );
   // sets the bar code field
   void SetBarCode ( uint32_t );
   // sets the cost field   
   void SetCost ( float );
   // returns a const pointer to the name field     
   const char* GetName () const;
   // returns the bar code by value       
   uint32_t GetBarCode () const;   
   // returns cost by value   
   float GetCost () const;         
 
   // default constructor
   Product();
   // 3-argument constructor
   Product(const char* name, uint32_t code, float cost);
   // copy constructor
   ~Product();
   // assignment operator
   Product (const Product& prod);
   // destructor
   Product& operator= (const Product& prod);
 
 private:
   // the product name
   char * name_; 
   // the product bar code
   uint32_t code_; 
   // the product cost
   float cost_; 
 };
 
 // overloaded operator
 std::ostream& operator<< (std::ostream& output, const Product& prod);
 
 #endif