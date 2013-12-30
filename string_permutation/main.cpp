// Given two strings, write a method to decide if one is a permutation of the other.
// Assumptions: case-sensitive and no whitespaces
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <string>
using std::string;

bool permutation(string s1, string s2); // function prototype

int main()
{
	string s1, s2;

	cout << "Input two strings to see if they are a permutation of each other\n" 
		<< "Enter the first string: "; // prompt the user
	cin >> s1; //extract the first input

	cout << "Enter the second string: "; // prompt the user
	cin >> s2; // extract the second input

	if(permutation(s1,s2)) { // test if string1 is a permutation of string2
		cout << s1 << " is a permutation of " << s2 << endl;
	}
	else {
		cout << s1 << " is not a permutation of " << s2 << endl;
	}

	return 0;
} // end main

// function that determines if string 1 is a permutation of string 2
bool permutation(string s1, string s2)
{
	//if the strings are different lengths then they cannot be anagrams
	if(s1.length() != s2.length()) {
		return false;
	}

	int charValue;
	int charSet[256] = {0}; // initialize to 0; ASCII character set (8-bit)
	
	// increment the number of occurrences of each letter in string 1
	for(int i = 0; i < s1.length(); i++) {
		charValue = s1[i]; // convert char to int
		charSet[charValue]++; // increment that character
	}

	// decrement the number of occurrences of each letter in string 2 from string 1
	for(int i = 0; i < s2.length(); i++) {
		charValue = s2[i]; // convert char to int
		if(--charSet[charValue] < 0) {
			return false;
		}
	}

	return true;
}