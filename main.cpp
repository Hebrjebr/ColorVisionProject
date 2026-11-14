// Author: Ian Phurchpean
// Date: 15 November 2026

// OBJECTIVE
// With a palette of colors given, evaluate if the color can be seen and differentiated.
// Take a look at them and see if it can be perceived by people with forms of color blindness
// Ask for color(s), whether it be by names, hexcode, or RGB values, and determine if it can be compared.
// Utilize comparisons, conditionals, and decisions to find if they are able to be compared.
// END OBJECTIVE

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int numberAdd(vector<int> &color);
void Information();
string colorEval(vector<int> color);
void Evaluator(int evalChoice, string chosenColor);

int main(void)
{
  int mainMenu = 0;
  bool isDone = false;
  int evaluatorChoice = 0;

  string nameOne, nameTwo;

  vector <int> colorOne; // Store values of color one
  vector <int> colorTwo; // Store values of color two

  char evaluate;

  // Begin asking for input
  cout << "Welcome to the Fantastically Useful Color Komparator!" << endl;
  cout << "This is a program that can accept two different colors, and then compare them to help users that may have colorblindness.\n" << endl;

  while (!isDone)
  {
    cout << "Please enter a number from 1 to 4 to browse different options:" << endl;
    cout << "1: Enter colors\n2: View Information\n3: Show Bingus\n4: Quit Program\n";
    cout << "Enter Here: ";
    cin >> mainMenu;
    switch (mainMenu)
    {
      case 1: // Color Add
        numberAdd(colorOne);
        cout << "\nAll three values added! We'll need another color in order to begin comparing them.\n";
        numberAdd(colorTwo);
        cout << "\nTwo colors added! Would you like to evaluate them (Y/N)? ";
        cin >> evaluate;
        if ((evaluate == 'Y') || (evaluate == 'y'))
        { 
          // Run Evaluations
          nameOne = colorEval(colorOne);
          nameTwo = colorEval(colorTwo);
          cout << "\nIt looks like your first color is: " << nameOne << endl;
          cout << "And your second color is: " << nameTwo << endl << endl;
          cout << "There are multiple types of colorblindness a person can have. I can evaluate your chosen color based on different types of colorblindness.";
          cout << "I am able to evaluate seven of them: " << endl;
          cout << "1. Deuteranomaly (Green-Weak)\n2. Protanomaly (Red-Weak)\n3. Tritanomaly (Blue-Weak)\n4. Deuteranopia (Green-Blind)\n5. Protanopia (Red-Blind)\n6. Tritanopia (Blue-Blind)\n7. Monochromacy (True Colorblindness)" << endl;
          
          cout << "Enter a value between 1-7 to make your choice: ";
          cin >> evaluatorChoice;
          cout << "\nCOLOR ONE:" << endl;
          Evaluator(evaluatorChoice, nameOne);
          cout << "\nCOLOR TWO: " << endl;
          Evaluator(evaluatorChoice, nameTwo);
        }
        else
        {
          cout << "\nUnderstood!\n";
          cout << "I will see you later!\n";
        }
        isDone = true;
        break; 
      case 2: // View Information
        Information();
        break;
      case 3: // Show Bingus
      {
        string bingus;
        fstream file("bingus", ios::in);
        if (!file.is_open())
        {
          cerr << "Could not open file!" << endl;
        }
        else
        {
          while (getline(file, bingus))
          {
            cout << bingus << endl;
          }
        }
      file.close();
      cout << "\nBingus.\n\n";
      break;
      }
      case 4: 
        cout << "Have a great rest of your day!" << endl;
        isDone = true;
        return 0;
        break;
      default: // Default to Color Add
        mainMenu = 1;
        break;
    }
  }
  return 0;
}