#include <stdexcept>
#include <exception>

using namespace std;

class ZeroException : public runtime_error
{
public:
	ZeroException() :runtime_error("Attempted to divide by zero.") {}
};