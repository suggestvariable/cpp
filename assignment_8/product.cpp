 // product.cpp
 // Project file that contains the implementations for
 // the class Product
 
 #include <product.h>
 #include <cstring>
 
 // Function that sets name field
 void Product::SetName ( const char* name )
 {
   if (name_ != NULL)
     delete [] name_;
   size_t SizeOfString = strlen(name);
   name_ = new char [1+SizeOfString];
   name_[SizeOfString] = '\0';
   strcpy(name_, name);
 }
 
 // Function that sets bar code field
 void Product::SetBarCode ( uint32_t code )
 {
   code_ = code;
 }
 
 // Function that sets cost field
 void Product::SetCost ( float cost )
 {
   cost_ = cost;
 }
 
 // Function that returns const pointer to name field
 const char* Product::GetName () const
 {
   return name_;
 }
 
 // Function that returns bar code by value
 uint32_t Product::GetBarCode () const
 {
   return code_;
 }
 
 // Function that returns cost by value
 float Product::GetCost    () const
 {
   return cost_;
 }
 
 // Default Constructor
 Product::Product() : name_(NULL), code_(0), cost_(0.0)
 {
   name_ = new char [2];
   name_[0] = '#';
   name_[1] = '\0';
 }
 
 // 3-argument Constructor
 Product::Product(const char* name, uint32_t code, float cost) :
   name_(NULL), code_(code), cost_(cost)
 {
   size_t SizeOfString = strlen(name);
   name_ = new char [1+SizeOfString];
   name_[SizeOfString] = '\0';
   strcpy(name_, name);
 }
 
 // Copy Constructor
 Product::~Product()
 {
   if (name_ != NULL)
     delete [] name_;
 }
 
 // Assigntment Operator
 Product::Product (const Product& prod) :
   name_(NULL), code_(prod.code_), cost_(prod.cost_)
 {
   size_t SizeOfString = strlen(prod.name_);
   name_ = new char [1+SizeOfString];
   name_[SizeOfString] = '\0';
   strcpy(name_, prod.name_);
 }
 
 // Destructor
 Product& Product::operator= (const Product& prod)
 {
   if (this != &prod)
   {
     if (name_ != NULL)
       delete [] name_;
     size_t SizeOfString = strlen(prod.name_);
     name_ = new char [1+SizeOfString];
     name_[SizeOfString] = '\0';
     strcpy(name_, prod.name_);
   }
   return *this;
 }
 
 std::ostream& operator<< (std::ostream& output, const Product& prod)
 {
   // remember all flags; code from professor
   std::ios_base::fmtflags flags = std::cout.flags();  
   // prep for $ output
   std::cout.setf(std::ios::fixed | std::ios::showpoint);
   std::cout.precision(2);
   output << prod.GetName() << '\t' << std::hex << std::uppercase
          << std::setfill('0') << std::setw(8) << prod.GetBarCode()
          << std::dec << std::setfill(' ') << '\t' << prod.GetCost();
   std::cout.setf(flags); // return flags to previous states
   return output;
 }