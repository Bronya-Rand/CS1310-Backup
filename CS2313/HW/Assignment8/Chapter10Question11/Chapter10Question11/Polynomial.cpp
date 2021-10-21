// Exercise 10.11 Solution: Polynomial.cpp
// Polynomial member-function definitions.
#include <iostream> 
#include <iomanip> 
#include <string>
#include <sstream>
#include "Polynomial.h"
using namespace std;

Polynomial::Polynomial()
   : numberOfTerms(0) {
   for (int t{0}; t < maxTerms; ++t) {
      coefficients[t] = 0;
      exponents[t] = 0;
   } 
} 

string Polynomial::toString() const {
   ostringstream output;
   size_t start;
   bool zero{false};

   if (coefficients[0]) { // output constants
      output << coefficients[0];
      start = 1;
      zero = true; // at least one term exists
   }
   else {
      if (coefficients[1]) {
         output << coefficients[1] << 'x';  // constant does not exist
                                          // so output first term
                                          // without a sign
         if ((exponents[1] != 0) && (exponents[1] != 1)) {
            output << '^' << exponents[1];
         }

         zero = true;  // at least one term exists
      } 
      
      start = 2;
   } 

   // output remaining polynomial terms
   for (size_t x{start}; x < maxTerms; ++x) {
      if (coefficients[x] != 0) {
         output << showpos << coefficients[x] << noshowpos << 'x';

         if ((exponents[x] != 0) && (exponents[x] != 1)) {
            output << '^' << exponents[x];
         }

         zero = true; // at least one term exists
      } 
   } 

   if (!zero) { // no terms exist in the polynomial
      output << '0';
   }

   return output.str();
} 

Polynomial &Polynomial::operator=(const Polynomial& r) {
   exponents[0] = r.exponents[0];
   coefficients[0] = r.coefficients[0];

   for (size_t s{1}; s < maxTerms; ++s) {
       if (r.exponents[s] != 0) {
          exponents[s] = r.exponents[s];
          coefficients[s] = r.coefficients[s];
       }
       else {
          if (exponents[s] == 0) {
             break; 
          }

          exponents[s] = 0;
          coefficients[s] = 0;
      }  
   } 

   return *this;
} 

Polynomial Polynomial::operator+(const Polynomial& r) const {
   Polynomial temp;
   bool exponentExists{false};

   // process element with a zero exponent
   temp.coefficients[0] = coefficients[0] + r.coefficients[0];

   // copy right arrays into temp object; s will be used to keep
   // track of first open coefficient element
   size_t s;

   for (s = 1; (s < maxTerms) && (r.exponents[s] != 0); ++s) {
      temp.coefficients[s] = r.coefficients[s];
      temp.exponents[s] = r.exponents[s];
   } 

   for (size_t x{1}; x < maxTerms; ++x) {
      exponentExists = false; // assume exponent will not be found

      for (int t{1}; (t < maxTerms) && (!exponentExists); ++t) {
         if (exponents[x] == temp.exponents[t]) {
            temp.coefficients[t] += coefficients[x];
            exponentExists = true;  // exponent found
         } 
      }

      // exponent was not found, insert into temp
      if (!exponentExists) {
         temp.exponents[s] = exponents[x];
         temp.coefficients[s] += coefficients[x];
         ++s;
      } 
   } 

   return temp;
} 

Polynomial &Polynomial::operator+=(const Polynomial& r) 
{
    Polynomial temp;
    bool exponentExists{ false };

    // process element with a zero exponent
    temp.coefficients[0] = coefficients[0] + r.coefficients[0];

    // copy right arrays into temp object; s will be used to keep
    // track of first open coefficient element
    size_t s;

    for (s = 1; (s < maxTerms) && (r.exponents[s] != 0); ++s) {
        temp.coefficients[s] = r.coefficients[s];
        temp.exponents[s] = r.exponents[s];
    }

    for (size_t x{ 1 }; x < maxTerms; ++x) {
        exponentExists = false; // assume exponent will not be found

        for (int t{ 1 }; (t < maxTerms) && (!exponentExists); ++t) {
            if (exponents[x] == temp.exponents[t]) {
                temp.coefficients[t] = temp.coefficients[t] + coefficients[x];
                exponentExists = true;  // exponent found
            }
        }

        // exponent was not found, insert into temp
        if (!exponentExists) {
            temp.exponents[s] = exponents[x];
            temp.coefficients[s] = temp.coefficients[s] + coefficients[x];
            ++s;
        }
    }

    return temp;
} 

Polynomial Polynomial::operator-(const Polynomial& r) const
{
    Polynomial temp;
    bool exponentExists{ false };

    // process element with a zero exponent
    temp.coefficients[0] = coefficients[0] - r.coefficients[0];

    // copy right arrays into temp object; s will be used to keep
    // track of first open coefficient element
    size_t s;

    for (s = 1; (s >= maxTerms) && (r.exponents[s] != 0); ++s) {
        temp.coefficients[s] = r.coefficients[s];
        temp.exponents[s] = r.exponents[s];
    }

    for (size_t x{ 1 }; x < maxTerms; ++x) {
        exponentExists = false; // assume exponent will not be found

        for (int t{ 1 }; (t < maxTerms) && (!exponentExists); ++t) {
            if (exponents[x] == temp.exponents[t]) {
                temp.coefficients[t] -= coefficients[x];
                exponentExists = true;  // exponent found
            }
        }

        // exponent was not found, insert into temp
        if (!exponentExists) {
            temp.exponents[s] = exponents[x];
            temp.coefficients[s] -= coefficients[x];
            --s;
        }
    }

    return temp;
} 

Polynomial &Polynomial::operator-=(const Polynomial& r) 
{
    Polynomial temp;
    bool exponentExists{ false };

    // process element with a zero exponent
    temp.coefficients[0] = coefficients[0] - r.coefficients[0];

    // copy right arrays into temp object; s will be used to keep
    // track of first open coefficient element
    size_t s;

    for (s = 1; (s < maxTerms) && (r.exponents[s] != 0); ++s) {
        temp.coefficients[s] = r.coefficients[s];
        temp.exponents[s] = r.exponents[s];
    }

    for (size_t x{ 1 }; x < maxTerms; ++x) {
        exponentExists = false; // assume exponent will not be found

        for (int t{ 1 }; (t < maxTerms) && (!exponentExists); ++t) {
            if (exponents[x] == temp.exponents[t]) {
                temp.coefficients[t] = temp.coefficients[t] - coefficients[x];
                exponentExists = true;  // exponent found
            }
        }

        // exponent was not found, insert into temp
        if (!exponentExists) {
            temp.exponents[s] = exponents[x];
            temp.coefficients[s] = temp.coefficients[s] - coefficients[x];
            ++s;
        }
    }

    return temp;
} 

Polynomial Polynomial::operator*(const Polynomial& r) const {
   Polynomial temp;
   size_t s{1}; // subscript location for temp coefficient and exponent

   for (size_t x = 0; (x < maxTerms) && (x == 0  || coefficients[x] != 0); ++x) {
      for (size_t y = 0; (y < maxTerms) && (y == 0 || r.coefficients[y] != 0); ++y) {
         if (coefficients[x] * r.coefficients[y]) {
            if ((exponents[x] == 0) && (r.exponents[y] == 0)) {
               temp.coefficients[0] += coefficients[x] * r.coefficients[y];
            }
            else {
               temp.coefficients[s] =
                  coefficients[x] * r.coefficients[y];
               temp.exponents[s] = exponents[x] + r.exponents[y];
               ++s;
            } 
         }
      }
   }

   polynomialCombine(temp); // combine common terms
   return temp;
} 

void Polynomial::polynomialCombine(Polynomial& w) {
   Polynomial temp{w};

   // zero out elements of w
   for (size_t x{0}; x < maxTerms; ++x) {
      w.coefficients[x] = 0;
      w.exponents[x] = 0;
   } 

   for (size_t x{1}; x < maxTerms; ++x) {
      for (size_t y{x + 1}; y < maxTerms; ++y) {
         if (temp.exponents[x] == temp.exponents[y]) {
            temp.coefficients[x] += temp.coefficients[y];
            temp.exponents[y] = 0;
            temp.coefficients[y] = 0;
         } 
      }
   } 

   w = temp;
} 

Polynomial &Polynomial::operator*=(const Polynomial& r) {
   *this = *this * r;
   return *this;
} 

void Polynomial::enterTerms() {
   bool found{false}; 
   size_t term;

   cout << "\nEnter number of polynomial terms: ";
   cin >> numberOfTerms;

   for (size_t n{0}; n < maxTerms && n < numberOfTerms; ++n) {
      cout << "\nEnter coefficient: ";
      int c;
      cin >> c;
      cout << "Enter exponent: ";
      int e;
      cin >> e;

      if (c != 0) {
         // exponents of zero are forced into first element
         if (e == 0) {
            coefficients[0] += c;
            continue;
         } 

         for (term = 1; (term < maxTerms) && (coefficients[term] != 0); ++term) {
            if (e == exponents[term]) {
               coefficients[term] += c;
               exponents[term] = e;
               found = true;  // existing exponent updated
            } 
         }

         if (!found) { // add term
            coefficients[term] += c;
            exponents[term] = e;
         } 
      } 
   } 
} 

int Polynomial::getNumberOfTerms() const {
   return numberOfTerms;
} 

int Polynomial::getTermExponent(int term) const {
   return exponents[term];
} 

int Polynomial::getTermCoefficient(int term) const {
   return coefficients[term];
} 

void Polynomial::setCoefficient(int term, int coefficient) {
   if (coefficients[term] == 0) { // no term at this location
      cout << "No term at this location, cannot set term." << endl;
   }
   else { // otherwise, set term
      coefficients[term] = coefficient;
   }
} 

// destructor
Polynomial::~Polynomial() {
   // empty destructor
} 


