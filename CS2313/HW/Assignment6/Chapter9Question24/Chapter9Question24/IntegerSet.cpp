
#include "IntegerSet.h"
#include <string>
#include <iostream>
#include <sstream>

IntegerSet::IntegerSet()
{
    for (int i = 1; i < 100; i++) {
        set.push_back(false);
    }
}

IntegerSet::IntegerSet(int array[]) {
    for (int i = 1; i < 100; i++) {
        if (array[i-1] > 0 && array[i-1] < 101) {
            set.push_back(true);
        }
        else {
            set.push_back(false);
        }
    }
}

IntegerSet IntegerSet::unionOfSets(IntegerSet& main, IntegerSet& back) {
    for (int i = 1; i < 100; i++)
    {
        if (set[i - 1] == 1 || main.set[i-1] == 1)
            back.set[i - 1] = true;
    }
    return back;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet& main, IntegerSet& back) {
    for (int i = 1; i <= 100; i++)
    {
        if (set[i-1] == 1 && main.set[i-1] == 1)
            back.set[i-1] = true;
    }
    return back;
}

void IntegerSet::insertElement(int l) {
    if (l > 0 && l <= 99) {
        set[l] = true;
    }
}

void IntegerSet::deleteElement(int l) {
    if (l > 0 && l <= 99) {
        set[l] = false;
    }
}

std::string IntegerSet::toString() {
    std::ostringstream out;
    out << "Present Vector Set Values: {";
    for (int i = 1; i <= 100; i++) {
        if (set[i-1]) {
            out << i-1 << " ";
        }
        else {
            out << "--- ";
        }
    }
    out << "}";
    return out.str();
}

bool IntegerSet::isEqualTo(IntegerSet setA) {
    for (int i = 1; i <= 100; i++) {
        if (set[i-1] != setA.set[i-1]) {
            return false;
        }
    }
    return true;
}

void IntegerSet::inputValuesToSet() {
    int num = 0;

    while (num != -1) {
        std::cout << "Enter an element (-1 to end): ";
        std::cin >> num;

        if (num > 0 && num <= 99) {
            set[num] = true;
        }
    }
}
