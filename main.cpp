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

using namespace std;

int main(void)
{
    
    // Initialize Variables using an RGB value
    int rgbOne; // value of red
    int rgbTwo; // value of green
    int rgbThree; // value of blue

    // This will only serve to have the computer slowly get angry at you.
    int tries = 3;
    
    char accept;
    string chosenColor;

    bool isSelected = false;
    // First section: Get user input for colors.
    find_input:
        while (isSelected == false)
        {
            // Get Input
            cout << "Enter three numbers (Red/Green/Blue) from a range of 0 to 255: " << endl;
            cin >> rgbOne;
            cin >> rgbTwo;
            cin >> rgbThree;

            // Check if values are within valid range
            if (rgbOne < 0 || rgbTwo < 0 || rgbThree < 0 || rgbOne > 255 || rgbTwo > 255 || rgbThree > 255) // Not in valid range
            {
                cout << "I'm sorry. Some or all of the values you have entered are not valid.\n";
                cout << "As a reminder, all values must be entered from a range of 0 to 255.\n";
                cout << "Would you like to try again? (Y/N): ";
                cin >> accept;
                if (accept == 'N' || accept == 'n') // Use uppercase and lowercase just in...case.
                {
                    cout << "\nOkay, have a great rest of your day!";
                    goto ending;
                }
                else if (accept == 'Y' || accept == 'y') // Use uppercase and lowercase just in...case.
                {
                    cout << "Okay, let's try again.\n";
                    goto find_input; // Return to the start of the loop and try again
                }
                else
                {
                    if (tries > 0) // Program will stop itself if you fail too much.
                    {
                        tries--; 
                        cout << "Did you perhaps miss your input? It's okay.\n";
                        cout << "I will restart for you, but just for the future, enter Y or N to reselect your options. Case does not matter at all." << endl;
                        goto find_input;
                    }
                    else // You have angered my program. It will now forcefully shut itself down.
                    {
                        cout << "Do not try to be funny here. I am a program designed to help shed light on colorblindness and help those in need." << endl;
                        cout << "Please do not ask me if 9 + 10 = 21 next. I am not for that purpose. Ask ChatGPT for that." << endl;
                        cout << "Goodbye." << endl;
                        goto ending; // You have angered my code. It no like you anymore :(
                    }
                    
                }
            }        
            else
            {
                isSelected = true; // Looks like we have a match!
                goto discern_Color;
            }
        }

    // Second section: Discering certain color combinations
    discern_Color:
        // Find basic colors (black and white)
        if (rgbOne == 0 && rgbTwo == 0 && rgbThree == 0) // Return Black
        {
            chosenColor = "Black";
        }
        else if (rgbOne == 255 && rgbTwo == 255 && rgbThree == 255) // Return White
        {
            chosenColor = "White";
        }
        else if (rgbOne <= 255 && rgbTwo == 0 && rgbThree == 0) // Values of Red
        {
            if (rgbOne < 128)
            {
                chosenColor = "Dark Red";
            }
            else if (rgbOne >= 128)
            {
                chosenColor = "Red";
            }
        }
        else if (rgbOne == 0 && rgbTwo <= 255 && rgbThree == 0) // Values of Green
        {
            if (rgbTwo < 128)
            {
                chosenColor = "Dark Green";
            }
            else if (rgbTwo >= 128)
            {
                chosenColor = "Green";
            }
        }
        else if (rgbOne == 0 && rgbTwo == 0 && rgbThree <= 255) // Values of Blue
        {
            if (rgbThree < 128)
            {
                chosenColor = "Dark Blue";
            }
            else if (rgbThree >= 128)
            {
                chosenColor = "Blue";
            }
        }
        else 
        {
            if (rgbOne == rgbTwo && rgbTwo == rgbThree && rgbOne == rgbThree)
            {
                chosenColor = "Grey";
            }   
        }
        // Print chosen color
        cout << "Success! Your chosen color is: " << chosenColor << "!" << endl;

    ending:
        return 0;
}
