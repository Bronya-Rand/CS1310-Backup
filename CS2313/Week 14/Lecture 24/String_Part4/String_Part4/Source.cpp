
#include <iostream>
#include <string>
using namespace std;

int main()
{
	// compiler concatenates all parts into one string
	string stringOrg{ "The values in any left subtree"
		"\nare less than the value in the"
		"\nparent node and the values in"
		"\nany right subtree are greater"
		"\nthan the value in the parent node" };

	cout << "Original string:\n" << stringOrg << endl << endl;

	// remove all characters from (and including) location 62
	// through the end of string1                            
	stringOrg.erase(62);

	
	cout << "Original string after erase:\n" << stringOrg
		<< "\nAfter first replacement:\n";

	size_t position = stringOrg.find(" "); // find first space

										 // replace all spaces with period
	while (position != string::npos) 
	{
		stringOrg.replace(position, 1, ".");
		position = stringOrg.find(" ", position + 1);
	}

	cout << stringOrg <<endl;

	cout << "-----------------------------------------\n\n";
	 
 	string string1{ "beginning end" };
	string string2{ "middle " };
	string string3{ "12345678" };
	string string4{ "xx" };

	cout << "Initial strings:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << "\n\n";

	// insert "middle" at location 10 in string1
	string1.insert(10, string2);
	
	
	// insert "xx" at location 3 in string3     
	string3.insert(3, string4, 0, string::npos); //last two arguments specifies startring and last element of string 4 to be inserted
	                                             //using string::npos causes the entire string to be inserted 

	cout << "Strings after insert:\nstring1: " << string1
		<< "\nstring2: " << string2 << "\nstring3: " << string3
		<< "\nstring4: " << string4 << endl;
	
	cout << "\nconvertion functions: \"120\" + \"10.5\" =  "
		<< stoi("120") + stof("10.5") << endl;
		
}



