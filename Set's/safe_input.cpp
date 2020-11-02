#include <iostream>
#include <string>
#include "set_operations.h"

using namespace std;

/*
Handles strings entered instead of numbers;
Returns true when input is valid, false otherwise;
*/
bool safeInput(int &number)
{
	string in;

	cin >> in;

	for (int i = 0; i < in.size(); i++) {
		if ((in[i] < '0' or in[i]>'9') and in[i] != '-') {
			return false;
		}
	}

	number = stoi(in);

	return true;
}

// Also checks if the number is in a given range [from, to]
bool safeInput(int &number, int from, int to)
{
	string in;

	cin >> in;

	for (int i = 0; i < in.size(); i++) {
		if ((in[i] < '0' or in[i]>'9') and in[i] != '-') {
			return false;
		}
	}

	number = stoi(in);

	if (number < from or number > to) return false;
	return true;
}

bool safeInput(size_t &number, size_t from, size_t to)
{
	string in;

	cin >> in;

	for (int i = 0; i < in.size(); i++) {
		if (in[i] < '0' or in[i]>'9') {
			return false;
		}
	}

	number = stoull(in);

	if (number < from or number > to) return false;
	return true;
}