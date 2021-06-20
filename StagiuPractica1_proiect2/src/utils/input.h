
#ifndef INPUT_HEADER
#define INPUT_HEADER

//? Input usage example
/**
#include "./src/utils/input.h"

int main() {

    int testInt;
    float testFloat;
    char testChar;
    string testString;

    cout << "Enter a string (can contain spaces):";
    testString = getUserInput();

    cout << "Enter a interger:";
    testInt = getUserInput<int>();

    cout << "Enter a float:";
    testFloat = getUserInput<float>();

    cout << "Enter a char (if it's string, will take first letter):";
    testChar = getUserInput<char>();


    cout << testString << "\t\t<-- String you entered\n";
    cout << testInt << "\t\t<-- Int you entered\n";
    cout << testFloat << "\t\t<-- Float you entered\n";
    cout << testChar << "\t\t<-- Char you entered\n";

    return 0;
}
 */

#include <iostream>
#include <string>

using namespace std;


/**
 *? Using SFINAE: Substitution Failure Is Not An Error
 *  defined template struct restrictor to ensure
 *  that we can use this type and implementation is provided
 */
template <typename T>   struct restrictor {};
template <>             struct restrictor<float>    { typedef float result; };
template <>             struct restrictor<double>   { typedef double result; };
template <>             struct restrictor<int>      { typedef int result; };
template <>             struct restrictor<char>     { typedef char result; };

template <typename T>
typename restrictor<T>::result
getUserInput() {
    string input;
    cin >> input;

    if(is_same<T, char>::value) {
        return T(input[0]);
    }

    if(is_same<T, int>::value) {
        return T(stoi(input));
    }

    if(is_same<T, float>::value) {
        return T(stof(input.c_str()));
    }

    if(is_same<T, double>::value) {
        return T(stod(input.c_str()));
    }
}

string getUserInput() {
    string input;

    getline(cin,input);

    if(input.empty()) {
        getline(cin,input);
    }
    return input;
}

#endif
