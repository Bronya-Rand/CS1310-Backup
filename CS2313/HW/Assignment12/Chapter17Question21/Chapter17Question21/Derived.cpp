#include "Derived.h"
#include <stdexcept>

using namespace std;

void Derived::Derived() {
	throw runtime_error("Attempt to divide by zero.");
}