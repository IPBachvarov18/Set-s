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

}

vector <int> setIntersection(vector <int> setA, vector <int> setB)
{

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
