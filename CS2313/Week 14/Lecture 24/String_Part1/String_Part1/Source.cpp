
#include <iostream>
#include <string> 
using namespace std;

int main() {
   string string1{"cat"};                          
   string string2; // initialized to the empty string
   string string3; // initialized to the empty string

   string2 = string1; 
   string3.assign(string1); 
   cout << "string1: " << string1 << "\nstring2: " << string2
      << "\nstring3: " << string3 << "\n\n";

   
   string2[0] = string3[2] = 'r';

   cout << "After modification of string2 and string3:\n" << "string1: " 
      << string1 << "\nstring2: " << string2 << "\nstring3: ";
   
   for (size_t i{0}; i < string3.size(); ++i) 
   {
      cout << string3.at(i); // can throw out_of_range exception
   }

   
   string string4{string1 + "apult"}; 
   string string5; 

   
   string3 += "pet"; 
   string1.append("acomb"); 

   // append subscript locations 4 through end of string1 to
   // create string "?????????" (string5 was initially empty)    
   
   string5.append(string1, 4, string1.size() - 4);      

   cout << "\n\nAfter concatenation:\nstring1: " << string1 
      << "\nstring2: " << string2 << "\nstring3: " << string3 
      << "\nstring4: " << string4 << "\nstring5: " << string5 << endl;
	  
} 

