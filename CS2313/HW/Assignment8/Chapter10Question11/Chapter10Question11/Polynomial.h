// Exercise 10.11 Solution: Polynomial.h
// Polynomial class definition.
#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include <array>
#include <string>

class Polynomial {
public:
   static const int maxTerms = 100; // maximum number of terms

   Polynomial();
   Polynomial operator+(const Polynomial&) const; // addition
   Polynomial operator-(const Polynomial&) const; // subtraction
   Polynomial operator*(const Polynomial&) const; // multiplication
   Polynomial &operator=(const Polynomial&); // assignment
   Polynomial &operator+=(const Polynomial&);
   Polynomial &operator-=(const Polynomial&);
   Polynomial &operator*=(const Polynomial&);
   void enterTerms();
   std::string toString() const;
   int getNumberOfTerms() const; // user can only retrieve value
   int getTermExponent(int) const;
   int getTermCoefficient(int) const;
   void setCoefficient(int, int); // set coefficient of a specific term
   ~Polynomial(); // destructor
private:
   size_t numberOfTerms;
   std::array<int, maxTerms> exponents; // exponent array
   std::array<int, maxTerms> coefficients; // coefficients array
   static void polynomialCombine(Polynomial&); // combine common terms
}; 

#endif



/**************************************************************************
 * (C) Copyright 1992-2017 by Deitel & Associates, Inc. and               *
 * Pearson Education, Inc. All Rights Reserved.                           *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 **************************************************************************/
