
#include <iostream>
#include "Base.h"
#include "Derived1.h"
#include "Derived2.h"
#include "Derived3.h"

using namespace std;

int main() {
	Base baseObj;
	baseObj.x = 50; //ONLY x can be accessed because it is public

	Derived1 derived1Obj;
	derived1Obj.x = 30; //ONLY x can be accessed

	Derived2 derived2Obj;
	//derived2Obj.x = 30; //you cannot access x because of protected inheritance level

	Derived3 derived3Obj;
	//derived3Obj.x = 70; //you cannot access x because of protected inheritance level
	return 0;
}