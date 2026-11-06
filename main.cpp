// Author: Ian Phurchpean
// Date: 4 September 2026

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
#include <random>

using namespace std;

int compareColors(vector <int> colorOne, vector <int> colorTwo);
bool findColor(vector <int> evaluatedColor);
void cBlindness (int colorPrompt);

int main(void)
{
  vector <int> colorOne; // Store values of color one
  vector <int> colorTwo; // Store values of color two

  int colorEval; // Evaluate different colorblindness types

  // This will only serve to have the computer slowly get angry at you.
  int tries = 3;
    
  return 0;
}