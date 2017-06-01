// BinarySearch.cpp
// Adam Flammino SDEV-345 5/28
// Uses binary search to determine if a value is in an array
// if value is present, uses linear search to find index

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

class Searches {
private:
	int element;
	std::vector<double> original;
	std::vector<double> copy;
	int size;
	void sortIt() { // Sorts orginal array for binary search
		std::sort(std::begin(original), std::end(original));
	}
	void duplicate() { // Copies array to mantain index positions
		copy = original;
	}
public:
	Searches() : element(0) { // Default constructor
	};
	Searches(int s) : element(0) { // Constructor
		original.resize(s);
		copy.resize(s);
	}
	void insert(double val) { // Populates vector
		original[element] = val;
		element++;
	}
	int findB(double searchKey) // Binary search, returns index in sorted array. Returns -1 if not found
	{
		int lowerBound = 0;
		int upperBound = element - 1;
		int curIn;
		duplicate();
		sortIt();
		while (true) 
		{
			curIn = (lowerBound + upperBound) / 2;
			if (original[curIn] == searchKey)
				return curIn;              //found it
			else if (lowerBound > upperBound)
				return -1;             //can't find it
			else                          //divide range
			{
				if (original[curIn] < searchKey)
					lowerBound = curIn + 1; //it's in upper half
				else
					upperBound = curIn - 1; //it's in lower half
			}  //end else divide range
		}  //end while
	}  //end find()
	int findL(double searchKey) { // Linear search, returns original index in array. Returns -1 if not found
		int i;
		for (i = 0; i < element; i++) {
			if (copy[i] == searchKey) {
				return i;
			}
		}
		return -1;
	}
};

int main()
{
	int size = 8;
	double searchVal = 9.2;
	int index1; // Position in sorted list
	int index2; // Position in unsorted list
	Searches s(size);
	s.insert(4.5);
	s.insert(6);
	s.insert(1);
	s.insert(9.2);
	s.insert(4);
	s.insert(77);
	s.insert(1200);
	s.insert(16.4);
	index1 = s.findB(searchVal);
	if (index1 == -1) {
		std::cout << searchVal << " not found." << std::endl;
	}
	else {
		index2 = s.findL(searchVal);
		std::cout << searchVal << " is in position " << index1 << " in the sorted list and position " << index2 << " as entered." << std::endl;
	}
    return 0;
}

