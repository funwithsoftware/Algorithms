#include <iostream>
#include <string>
#include <map>
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
  
// Print the repeated characters in the given string
void printrepeatedchar(string s)
{
  map<char, int> m;
  for(int i=0;i<s.length();i++)
  {
      if(s[i] != ' ')
      {
          std::map<char, int>::iterator itr = m.find(s[i]);
          if(itr!=m.end())
          {
              m[s[i]]++;
          }
          else
          {
              m.insert ( pair <char, int> ( s[i], 1) );
          }
      }
  }
  std::map<char, int>::iterator itr = m.begin();
  for(;itr!=m.end();itr++){
     if( (*itr).second  > 1)
     {
         cout << (*itr).first << endl;
     }
  }
}

private:
string s;

};
