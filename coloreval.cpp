#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

int numberAdd(vector<int> &color)
{
  int givenValues = 0;
  int newValue = 0;
  while (givenValues < 3)
      {
        cout << "Enter a number between 0 and 255." << endl;
        cin >> newValue;
        if (newValue < 0 || newValue > 255)
        {
          cout << "I'm sorry. The entered value is invalid.\n";
          cout << "It has not been added to your value.\n";
        }
        else
        {
          cout << "Value Added!" << endl;
          color.push_back(newValue);
          givenValues++;
        }
        newValue = 0;
      }
  return newValue;
}