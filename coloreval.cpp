#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

// Evaluate colors and return name
string colorEval(vector<int> color)
{
  string chosenColor;
  int rgbOne, rgbTwo, rgbThree;
  rgbOne = color.at(0);
  rgbTwo = color.at(1);
  rgbThree = color.at(2);

  if (rgbOne == 0 && rgbTwo == 0 && rgbThree == 0) // Black
  {
    chosenColor = "Black";
  }
        
  else if (rgbOne == 255 && rgbTwo == 255 && rgbThree == 255) // White
  {
    chosenColor = "White";
  }

  else if (rgbOne == rgbTwo && rgbOne == rgbThree && rgbTwo == rgbThree) // Grey
  {
    chosenColor = "Grey";
  }

  // Color Bases
  else if (rgbOne > rgbTwo && rgbOne > rgbThree) // Mostly Red
  {
    chosenColor = "Mostly Red";
  }
  else if (rgbTwo > rgbOne && rgbTwo > rgbThree) // Mostly Green
  {
    chosenColor = "Mostly Green";
  }
  else if (rgbThree > rgbOne && rgbTwo > rgbThree) // Mostly Blue
  {
    chosenColor = "Mostly Blue";
  }
  else if (rgbOne == rgbTwo && rgbOne > rgbThree && rgbTwo > rgbThree)
  {
    chosenColor = "More Red and Green than Blue";
  }
  else if (rgbTwo == rgbThree && rgbTwo > rgbOne && rgbThree > rgbOne)
  {
    chosenColor = "More Blue and Green than Red";
  }
  else
  {
    chosenColor = "A combination of Red, Green, and Blue";
  }
  return chosenColor;
}

void Evaluator(int evalChoice, string chosenColor)
{
  switch (evalChoice)
  {
    case 1: // Deuteranomaly
    {
      if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
            cout << "Your color may pose a problem with those with Deuteranomaly." << endl;
            cout << "It will cause your color to look a stark yellow or tan." << endl;
            cout << "Consider adding more blue to your color, or toning down the red and/or green." << endl;
        }
        else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
        {
            cout << "Your color can be perceived okay by those with Deuteranomaly." << endl;
        }
        else
        {
            cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
        }
      break;
    }
    case 2: // Protonomaly
    {
      if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
      {
        cout << "This color may pose a problem with those with Protoanomaly." << endl;
        cout << "It will cause your color to be dimmed in their eyes." << endl;
        cout << "Create more contrast in your color. Make the color a little bit more orange, and avoid making the reds and greens too similar." << endl;
      }
      else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
      {
        cout << "Your color can be perceived okay by those with Protoanomaly." << endl;
      }
      else
      {
        cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
      }
      break;
    }
    case 3: // Tritanomaly
    {
      if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
          cout << "Your color can be perceived okay by those with Tritanomaly." << endl;
          cout << "However, be aware of greens. People with Tritanomaly can perceive them as a more blue-ish tint." << endl;
        }
        else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
        {
          cout << "Your color may pose a problem with those with Tritanomaly." << endl;
          cout << "This color may blend with other colors and cause a bit of confusion." << endl;
          cout << "Up the contrast in the color, shift the hue a bit so it's able to be perceived better." << endl;
        }
        else
        {
          cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
        }
      break;
    }
    case 4: // Deuteranopia
    {
        if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
          cout << "Your color may pose a problem with those with Deuteranopia." << endl;
          cout << "It will cause your color to look a muted brownish-yellow." << endl;
          cout << "Lower the saturation of your color so it can be seen by people with Deuteranopia." << endl;
        }
        else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
        {
          cout << "Your color can be perceived okay by those with Deuteranopia." << endl;
          cout << "However, if it contains hints of reds and greens, it will cause the color to blend in. Blues and Purples appear similar in their vision." << endl;
        }
        else
        {
          cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
        }
      break;
    }
    case 5: // Protanopia
    {
      if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
          cout << "Your color may pose a problem with those with Protoanopia." << endl;
          cout << "It will cause your color to appear very black or muted." << endl;
          cout << "Create more contrast in your color. Make the color a little bit more orange, and avoid making the reds and greens too similar." << endl;
        }
        else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
        {
          cout << "Your color can be perceived okay by those with Protanopia." << endl;
        }
        else
        {
          cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
        }
      break;
    }
    case 6: // Tritanopia
    {
        if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
          cout << "Your color can be perceived okay by those with Tritanopia." << endl;
        }
        else if (chosenColor == "Mostly Blue" || chosenColor == "More Blue and Green than Red")
        {
          cout << "Your color may pose a problem with those with Tritoanopia." << endl;
          cout << "The blues in the color cannot be perceived very well, causing confusion." << endl;
          cout << "Avoid using so much blue in your color to avoid confusion. Some alternatives may be hard to find, but I know you can do it!" << endl;
        }
        else
        {
          cout << "This is a color that may have trouble being seen by most people with colorblindness." << endl;
        }
      break;
    }
    case 7: // Monochromacy
    {
      cout << "Monochromacy is the rarest form of colorblindness. It has quite a few forms." << endl;
      cout << "Some people can only see reds, greens, blues, or no color at all! This is known as Achromatopsia." << endl;
      cout << "Unfortunately, unless your color is a form of black or white, your color cannot be perceived at all by these people." << endl;
      cout << "However, the chances of finding them are very rare, with only 1 in every 50,000 people having it." << endl;
      cout << "So it's okay that your color is not perceived well." << endl;
      break;
    }
    default:
    {
      cout << "Invalid option detected. Breaking." << endl;
      break;
    }
  }
}