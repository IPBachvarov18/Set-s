#include <iostream>
#include <vector>
#include <string>
#include "set_operations.h"
#include "safe_input.h"

using namespace std;

bool enterSet(vector <int> &a)
{
	bool check=true;
	size_t n;
	int curr;

	cout << "Enter set length: ";
	if (!safeInput(n, 1, (size_t)SIZE_MAX)) {
		cout<<"Invalid set length!\n";
		return false;
	}

	cout << "Enter the " << n << " elements of the set:\n";
	for (size_t i = 0; i < n; i++) {
		if (!safeInput(curr)) {
			check = false;
		}
		if (check) a.push_back(curr);
	}

	if (!check) {
		cout<<"An invalid number has been encountered!\n";
		return false;
	}

	a = sanitiseSet(a);
	return true;
}

bool checkSets(vector <vector <int> > sets)
{
    if (sets.size()>1) return true;
    return false;
}

void printSet(vector <int> a)
{
    if (a.size() == 0) {
        cout << "The set is empty\n";
        return;
    }

    cout<<a[0];
	for (size_t i = 1; i < a.size(); i++) {
		cout << " " << a[i];
	}
	cout << endl;
}

void listSets(vector <vector <int> > sets)
{
	if (sets.size() == 0) {
		cout << "There are no entered sets!\n";
		return;
	}

	for (size_t i = 0; i < sets.size(); i++) {
		cout << i + 1 << ": ";
		printSet(sets[i]);
	}
}

void addSet(vector <vector <int> > &sets)
{
	vector <int> temp;

	if (!enterSet(temp)) {
		cout<<"Aborting...\n";
		return;
	}

	sets.push_back(temp);
}

void removeSet(vector <vector <int> > &sets)
{
	size_t choice;

	cout << "\n\n---- Delete Set ----\n";

	if (sets.size() == 0) {
		cout << "There are no entered sets!\n";
		return;
	}

	cout << "List of sets:\n";
	listSets(sets);

	cout << "\nChoose a set to delete: ";
	if (!safeInput(choice, 1, sets.size())) {
		cout<<"Invalid choice!\n";
		return;
	}

	sets.erase(sets.begin() + choice - 1);
}

bool editSetMenu(vector <vector <int> > &sets)
{
	int choice;

	cout << "\n\n----- Set Menu -----\n";
	cout << "Please select one of the following options:\n\n";
	cout << "1: Enter a new set\n";
	cout << "2: List sets\n";
	cout << "3: Delete existing set\n";
	cout << "9: Back to Main Menu\n\n";
	cout << "Enter your choice: ";

	safeInput(choice);

	switch (choice)
	{
	case 1:
		addSet(sets);
		return true;
	case 2:
		listSets(sets);
		return true;
	case 3:
		removeSet(sets);
		return true;
	case 9:
		return false;
	default:
		return false;

	}
}

vector <int> binarySetOperation(vector <vector <int> > sets, vector <int>(*f)(vector <int> setA, vector <int> setB))
{
	size_t choice1, choice2;

	if (!checkSets(sets)) {
		cout << "You need at least 2 sets to perform this operation!\n";
		return {};
	}

	cout << "List of sets\n";
	listSets(sets);

	cout << "\nChoose first set: ";
	if (!safeInput(choice1, 1, sets.size())) {
		cout<<"Aborting due to invalid choice...\n";
		return {};
	}

	cout << "Choose second set:";
	if (!safeInput(choice2, 1, sets.size())) {
		cout << "Aborting due to invalid choice...\n";
		return {};
	}

	return f(sets[choice1 - 1], sets[choice2 - 1]);
}

bool menu(vector <vector <int> > &sets)
{

    //*****************************************************************************
    // Switch menu to display the menu.
    //*****************************************************************************
    cout<<"\n\n------ Main Menu ------\n";
    cout << "Please select one of the following options:  " << endl;
    cout << endl;
    cout << "1: Edit sets" << endl;
    cout << "2: Find set union" << endl;
    cout << "3: Find set difference" << endl;
    cout << "4: Find set intersection" << endl;
    cout << "5: Find set symmetric diffrence" << endl;
    cout << "9: Quit" << endl;
    cout << endl;
    int choice;

    cout << "Enter your choice: ";

    cin >> choice;
    switch (choice)
    {
    case 1:
        while (editSetMenu(sets));
        return true;
    case 2:
        printSet(binarySetOperation(sets, setUnion));
        return true;
    case 3:
        printSet(binarySetOperation(sets, setDifference));
        return true;
    case 4:
        printSet(binarySetOperation(sets, setIntersection));
        return true;
    case 5:
        printSet(binarySetOperation(sets, setSymmetricDifference));
        return true;
    case 9:
        cout<<"\nGoodbye!\n";
        return false;
    default:
        return false;

    }
}


int main()
{
    vector <vector <int> > sets;

    bool showMenu = true;
    do 
    {
        showMenu = menu(sets);
    } while (showMenu);
}
