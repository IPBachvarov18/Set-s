#include <algorithm>
#include <vector>
#include "set_operations.h"

using namespace std;

vector <int> setUnion(vector <int> setA, vector <int> setB)
{
	vector <int> result;

	// Concatenate the two vectors
	result.insert(result.begin(), setA.begin(), setA.end());
	result.insert(result.end()-1, setB.begin(), setB.end());

	result = sanitiseSet(result);

	return result;
}

vector <int> setDifference(vector <int> setA, vector <int> setB)
{
	vector <int> result;

	for (int i = 0, j = 0; i < setA.size(); i++) {
		if (j == setB.size()) {
			// When the end of set B has been reached, the rest of set A must also be in the difference
			result.insert(result.end(), setA.begin()+i, setA.end());
			break;
		}
		if (setA[i] == setB[j]) {
			j++;
			continue;
		}
		if (setA[i] > setB[j]) {
			// Move to the next element in set B
			j++;
			i--;
			continue;
		}

		if (setA[i] != setB[j]) {
			result.push_back(setA[i]);
		}
	}

	return result;
}

vector<int> SetIntersection(vector<int>setA, vector<int>setB)
{
	vector<int> result;
	sort(setA.begin(), setA.end());
	sort(setB.begin(), setB.end());
	set_intersection(setA.begin(), setA.end(), setB.begin(), setB.end(),back_inserter(result));
	return result;
}

// Sorts and removes duplicate elements
vector <int> sanitiseSet(vector <int> setToSanitise)
{
	vector <int> sanitisedSet;

	sort(setToSanitise.begin(), setToSanitise.end());

	sanitisedSet.push_back(setToSanitise[0]);
	for (size_t i = 1; i < setToSanitise.size(); i++) {
		if (setToSanitise[i] != setToSanitise[i - 1]) {
			sanitisedSet.push_back(setToSanitise[i]);
		}
	}

	return sanitisedSet;
}
