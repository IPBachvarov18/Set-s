#include <iostream>
#include <vector>
#include "set_operations.h"

using namespace std;

void enterSet(vector <int> &a)
{
	size_t n;
	int curr;

	cout << "Enter set length: ";
	cin >> n;

	cout << "Enter the " << n << " elements of the set:\n";
	for (size_t i = 0; i < n; i++) {
		cin >> curr;
		a.push_back(curr);
	}

	a = sanitiseSet(a);
}

bool checkSet(vector <int> a)
{
    if (a.size() == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void printSet(vector <int> a)
{
    if (a.size() == 0) {
        cout << "The set is empty\n";
        return;
    }

    cout<<a[0];
	for (size_t i = 0; i < a.size(); i++) {
		cout << " " << a[i];
	}
	cout << endl;
}

bool menu(vector <int> setA, vector<int> setB, vector<int> &a)
{

    //*****************************************************************************
    // Switch menu to display the menu.
    //*****************************************************************************
    cout << "Please select one of the following options:  " << endl;
    cout << endl;
    cout << "1: Enter Set" << endl;
    cout << "2: setUnion" << endl;
    cout << "3: setDifference" << endl;
    cout << "4: setIntersection" << endl;
    cout << "5: sanitiseSet" << endl;
    cout << "9: Quit" << endl;
    cout << endl;
    int choice;

    cout << "Enter your choice: ";

    cin >> choice;
    cout << endl;
    switch (choice)
    {
    case 1:
        
        enterSet(a);
        return true;
    case 2:
        if (checkSet(a) == false)
        {
            cout << "You have chosen setUnion" << endl;
            setUnion(setA, setB);
            return true;
        }
        else
        {
            cout << "You need to enter a Set!" << endl;
        }
        return true;
    case 3:
        if (checkSet(a) == false)
        {
            cout << "You have chosen setDifference" << endl;
            setDifference(setA, setB);
            return true;
        }
        else
        {
            cout << "You need to enter a Set!" << endl;
        }
        return true;
    case 4:
        if (checkSet(a) == false)
        {
            cout << "You have chosen setIntersection" << endl;
            setIntersection(setA, setB);
            return true;
        }
        else
        {
            cout << "You need to enter a Set!" << endl;
        }
        return true;
    case 5:
        return true;
    case 9:
        cout << "Goodbye!" << endl;;
        return false;
    default:
        return false;

    }
}


int main()
{
    vector<int> setA = { 1 }, setB = { 1 };
    vector <int> a = { 1 };
    bool showMenu = true;
    do 
    {
        showMenu = menu(setA,setB,a);
    } while (showMenu);
}
