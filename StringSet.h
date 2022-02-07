#pragma once
#include <string>
using std::string;

class StringSet 
{
public:
	// Default constructor
	StringSet();

	// Deep copy constructor
	StringSet(const StringSet & st);

	// Destructor
	~StringSet();

	// Overloaded assignment operator
	StringSet& operator=(const StringSet& st);

	// Inserts the string parameter into the array
	bool insert(string s);

	// Removes the string parameter from the array
	void remove(string s);

	// Finds the string parameter within the array
	int find(string s) const;

	// Size of the number of values in the calling object
	int size() const;

	// Union of the calling object and the StringSet parameter
	StringSet unions(StringSet st) const;

	// Intersection of the calling object and the StringSet parameter
	StringSet intersection(StringSet st) const;

	// Set difference of the calling object and the StringSet parameter
	StringSet difference(StringSet st) const;

private:
	// Pointer to a string
	string* arr;

	// Int with current size
	int currentSize;

	// Int with max size
	int max;

	// Helper method for copy constructor
	void copyStack(const StringSet& st);
};