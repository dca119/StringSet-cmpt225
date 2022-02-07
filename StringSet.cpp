#include <iostream>
#include "StringSet.h"

using std::endl;
using std::cout;

// Default constructor
StringSet::StringSet() 
{
	// Sets the current size to zero and the max size to two.
	// Then, allocates dynamic memory of size two and assigns
	// the address to the class' string array pointer.

	max = 2;
	currentSize = 0;
	arr = new string[max];
}

// Copy constructor
StringSet::StringSet(const StringSet& st) 
{
	// Calls the private member function copyStack with 
	// the StringSet reference parameter as its parameter.

	copyStack(st);
}

// Helper method for copy constructor
void StringSet::copyStack(const StringSet& st)
{
	// Copies over the StringSet parameter's max size and
	// current size to the calling object. Then allocates
	// dynamic memory to the calling object's array with 
	// the max size. Then, copies over each of the elements
	// in the StringSet parameter's array to the calling
	// object's array.

	max = st.max;
	currentSize = st.currentSize;
	arr = new string[max];
	for (int i = 0; i < max; i++) {
		arr[i] = st.arr[i];
	}
}

// Destructor
StringSet::~StringSet()
{
	// Frees the memory associated with the calling object's 
	// array and, sets the max size and current size to zero. 

	delete[] arr;
	max = 0;
	currentSize = 0;
}

// Overloaded assignment operator
StringSet& StringSet::operator=(const StringSet& st)
{
	// Free the memory associated with the calling object's array
	// and copy the StringSet parameter's object to the calling
	// object. Then, returns the object.

	delete[] arr;
	copyStack(st);
	return *this;
}

// Inserts the string parameter into the array
bool StringSet::insert(string s)
{	
	// Checks if there is a string matching the parameter
	// already in the array. If there is a matching string,
	// then return false without adding the parameter into
	// the array.

	bool check = false;
	for (int i = 0; i < currentSize; i++) {
		if (arr[i] == s) {
			check = true;
			return false;
		}
	}

	// If there is no string matching the parameter within
	// the array, then checks if the array is full or not.
	// If the array is full create a new temporary array with
	// double the max size of the original one and copy the 
	// elements over. Then, free the memory of the old array
	// and assign the new array's address to the object array's
	// pointer.
	// Add the string parameter to the array, increment the 
	// current size and return true.

	if (!check) {
		if (max == currentSize) {
			max = max * 2;
			string* temp = new string[max];
			for (int i = 0; i < currentSize; i++) {
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
		}
		arr[currentSize] = s;
		currentSize++;
		return true;
	}
	return false;
}

// Removes the string parameter from the array
void StringSet::remove(string s) 
{
	// Compares the calling object's array elements
	// with the string parameter. If the string parameter
	// is found in the array, replaces the element in the
	// array with the last element in the array. Then,
	// decrements the current size by 1.

	for (int i = 0; i < currentSize; i++) {
		if (arr[i] == s) {
			arr[i] = arr[currentSize - 1];
			currentSize--;
		}
	}
}

// Finds the string parameter within the array
int StringSet::find(string s) const
{
	// Compares the calling object's array elements
	// with the string parameter. If they are equal,
	// returns the index of the element that is equal.
	// Else, returns -1.

	for (int i = 0; i < currentSize; i++) {
		if (arr[i] == s) {
			return i;
		}
	}
	return -1;
}

// Size of the number of values in the calling object
int StringSet::size() const
{
	// Returns the private member variable that stores
	// the current size.

	return currentSize;
}

// Union of the calling object and the StringSet parameter
StringSet StringSet::unions(StringSet st) const
{
	// Insert all the elements in the calling object's array into 
	// the new StringSet object's array. Then, compare the elements
	// within the new StringSet object's array with the StringSet
	// parameter's array elements. If the compared elements are 
	// different, then insert that element into the new StringSet
	// object's array.

	StringSet _union;
	for (int i = 0; i < currentSize; i++) {
		_union.insert(arr[i]);
	}
	for (int i = 0; i < st.currentSize; i++) {
		if (st.arr[i] != _union.arr[i]) {
			_union.insert(st.arr[i]);
		}
	}
	
	return _union;
}

// Intersection of the calling object and the StringSet parameter
StringSet StringSet::intersection(StringSet st) const
{
	// Compare one element in the calling object's array with every
	// element in the StringSet parameter's array and change the 
	// found boolean depending on if the element was found or not.
	// If the element was found, then insert the element in the new
	// StringSet object. (This is to prevent adding duplicates to the
	// new StringSet object) Continue this process until all the 
	// elements in the calling object's array has been compared.

	bool found = false;
	StringSet _intersection;
	for (int i = 0; i < currentSize; i++) {
		for (int j = 0; j < st.currentSize; j++) {
			if (arr[i] == st.arr[j]) {
				found = true;
			}
		}
		if (found) {
			_intersection.insert(arr[i]);
		}
		found = false;
	} 

	return _intersection;
}

// Difference of the calling object and the StringSet parameter
StringSet StringSet::difference(StringSet st) const
{
	// Compare one element in the calling object's array with every
	// element in the StringSet parameter's array and change the 
	// unique boolean depending on if the element is unique or not.
	// If the element is unique, then insert the element in the new
	// StringSet object. Continue this process until all the elements
	// in the calling object's array has been compared.

	StringSet _difference;
	bool unique = true;
	for (int i = 0; i < currentSize; i++) {
		for (int j = 0; j < st.currentSize; j++) {
			if (arr[i] == st.arr[j]) {
				unique = false;
			}
		}
		if (unique) {
			_difference.insert(arr[i]);
		}
		unique = true;
	}

	return _difference;
}
