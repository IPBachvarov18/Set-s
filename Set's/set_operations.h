#pragma once
#include <vector>

std::vector <int> setUnion(std::vector <int> setA, std::vector <int> setB);
std::vector <int> setDifference(std::vector <int> setA, std::vector <int> setB);
std::vector <int> setIntersection(std::vector <int> setA, std::vector <int> setB);

std::vector <int> sanitiseSet(std::vector <int> setToSanitise);
