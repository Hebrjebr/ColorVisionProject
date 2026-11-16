#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void Information()
{
  string value;
  int helpMenu = 0;
  cout << "\nWhat would you like to read about?" << endl;
  cout << "1: About this program\n2: About Colorblindness\n3: Different types of Colorblindness\n4: How do I enter values?\n\n";
  cout << "Enter your choice here: ";
  cin >> helpMenu;
  switch (helpMenu)
  {
    case 1:
    {
      fstream file("About.txt", ios::in);
      if (!file.is_open())
      {
        cerr << "Could not open file!" << endl;
        return 1;
      }
      else
      {
        while (getline(file, value))
        {
          cout << value << endl;
        }
      }
      file.close();
      break;
    }
    case 2:
    {
      fstream file("Colorblindness.txt", ios::in);
      if (!file.is_open())
      {
        cerr << "Could not open file!" << endl;
        return 1;
      }
      else
      {
        while (getline(file, value))
        {
          cout << value << endl;
        }
      }
      file.close();
      break;
    }
    case 3:
    {
      fstream file("BlindnessTypes.txt", ios::in);
      if (!file.is_open())
      {
        cerr << "Could not open file!" << endl;
        return 1;
      }
      else
      {
        while (getline(file, value))
        {
          cout << value << endl;
        }
      }
      file.close();
      break;
    }
    case 4:
    {
      fstream file("RGBValues.txt", ios::in);
      if (!file.is_open())
      {
        cerr << "Could not open file!" << endl;
        return 1;
      }
      else
      {
        while (getline(file, value))
        {
          cout << value << endl;
        }
      }
      file.close();
      break;
    }
    default:
    {
      cout << "Invalid option chosen.\n";
      cout << "Returning to menu...\n\n";
      break;
    }
  }
}