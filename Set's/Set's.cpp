#include <iostream>
#include <vector>
#include "set_operations.h"

using namespace std;

bool menu(vector <int> setA, vector<int> setB)
{

    //*****************************************************************************
    // Switch menu to display the menu.
    //*****************************************************************************

    cout << "Please select one of the following options:  " << endl;

    cout << "1: setUnion" << endl;
    cout << "2: setDifference" << endl;
    cout << "3: setIntersection" << endl;
    cout << "4: sanitiseSet" << endl;
    cout << "9: Quit" << endl;

    int choice;

    cout << "Enter your choice: ";

    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "You have chosen setUnion" << endl;
        setUnion(setA, setB);
        return true;
    case 2:
        cout << "You have chosen setDifference" << endl;
        setDifference(setA, setB);
        return true;
    case 3:
        cout << "You have chosen setIntersection" << endl;
        setIntersection(setA, setB);
        return true;
    case 4:
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
    bool showMenu = true;
    do 
    {
        showMenu = menu(setA,setB);
    } while (showMenu);
}
