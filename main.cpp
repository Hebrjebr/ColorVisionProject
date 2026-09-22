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
#include <random>

using namespace std;

int main(void)
{
    // Initialize Variables using an RGB value
    int rgbOne; // value of red
    int rgbTwo; // value of green
    int rgbThree; // value of blue

    int colorEval; // Evaluate different colorblindness types
    int colorsAssessed = 0; // Number of colors assessed in this session

    // This will only serve to have the computer slowly get angry at you.
    int tries = 3;
    
    char accept;
    char colorAccept;
    char contAccept;

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
                    cout << "\nOkay, let's try again.\n";
                    goto find_input; // Return to the start of the loop and try again
                }
                else
                {
                    if (tries > 0) // Program will stop itself if you fail too much.
                    {
                        tries--; 
                        cout << "\nDid you perhaps miss your input? It's okay.\n";
                        cout << "I will restart for you, but just for the future, enter Y or N to reselect your options. Case does not matter at all." << endl;
                        cout << "I'm giving you " << tries << " tries. No pressure." << endl;
                        goto find_input;
                    }
                    else // You have angered my program. It will now forcefully shut itself down.
                    {
                        cout << "\nDo not try to be funny here. I am a program designed to help shed light on colorblindness and help those in need." << endl;
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

        // print output
        cout << "Success! Looks like your chosen color is " << chosenColor << "." << endl;
        if (chosenColor == "Black" || chosenColor == "Grey" || chosenColor == "White") // These are colors everyone can see
        {
            cout << "This color can be perceived by all people, regardless of colorblindness." << endl; 
            cout << "There is no need to look for alternatives, nor variations.";
        }
        else
        {
            cout << "This is a color that can be perceived differently by people with colorblindness." << endl;   
        }
        cout << "Would you like to see which types will perceive your color differently? (Y/N) ";
        cin >> colorAccept;
        if (colorAccept == 'y' || colorAccept == 'Y') // User wants to see the colors
            {
                cout << "Okay! Here's the types that will see it different: " << endl;
            }
            else if (colorAccept == 'n' || colorAccept == 'N') // User does not want to see the colors
            {
                cout << "Sounds good to me!" << endl;
                goto ending;
            }
            else // Minor Spelling Mistake. I win.
            {
                cout << "Too bad, minor spelling mistake. I'm showing you anyway." << endl;
            }
        // Go to next section
        goto suggest_Color;
    suggest_Color:
        // Ask which colorblindness they would like to see
        cout << "There are multiple types of colorblindness a person can have. I can evaluate your chosen color based on different types of colorblindness.";
        cout << "I am able to evaluate seven of them: " << endl;
        cout << "1. Deuteranomaly (Green-Weak)\n2. Protanomaly (Red-Weak)\n3. Tritanomaly (Blue-Weak)\n4. Deuteranopia (Green-Blind)\n5. Protanopia (Red-Blind)\n6. Tritanopia (Blue-Blind)\n7. Monochromacy (True Colorblindness)" << endl; 
        cout << "Enter a value from 1-7 to evaluate your color based on different blindness types: ";
        cin >> colorEval;
        goto color_Evaluator;

    // For different color combinations, show user the types of colorblindness and if they can be perceived
    color_Evaluator:
        switch (colorEval)
        {
            case 1:
                cout << "You have chosen: Deuteranomaly" << endl;
                break;
            case 2:
                cout << "You have chosen: Protanomaly" << endl;
                break;
            case 3:
                cout << "You have chosen: Tritanomaly" << endl;
                break;
            case 4:
                cout << "You have chosen: Deuteranopia" << endl;
                break;
            case 5:
                cout << "You have chosen: Protanopia" << endl;
                break;
            case 6:
                cout << "You have chosen: Tritanopia" << endl;
                break;
            case 7:
                cout << "You have chosen: Monochromacy" << endl;
                break;
            default: // If you decide to mess around with the program, it will choose an option for you
                cout << "Invalid Entry. Generating random number..." << endl;
                colorEval = rand() % 8;
                goto color_Evaluator;
        }

    ending:
        colorsAssessed++; // Add 1 colors assessed
        cout << "Thank you for assessing colors! You have assessed a total of " << colorsAssessed << " colors today!" << endl;
        cout << "Would you like to continue assessing colors? (Y/N) ";
        cin >> contAccept;
        if (contAccept == 'y' || contAccept == 'Y') // User continues assessing colors
            {
                cout << "Okay! Let's continue assessing colors!" << endl;
                goto find_input;
            }
            else if (contAccept == 'n' || contAccept == 'N')
            {
                // User quits program
                cout << "Okay, I'll see you around!" << endl;
            } 
            else // User can't spell
            {
                cout << "Please stop patronizing me." << endl;
                cout << "I'll take that as you want to quit, so I'll take my leave." << endl;
                cout << "Goodbye. Please tell me you aren't like this with other programs." << endl;
            }
        return 0;
}
    
    
