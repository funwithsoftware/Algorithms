#include <iostream>
#include <string>
using namespace std;
class MyString
{
public:

// Constructor
MyString(string S);

// Destructor
~MyString();

// Return the first occurrence of non repeating character in the given string
int find_first_occurrence_of_non_repeating_char(string s);

private:
string s;

};
