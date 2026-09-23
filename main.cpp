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

    // This will only serve to have the computer slowly get angry at you.
    int tries = 3;
    
    char accept;
    char colorAccept;

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
            cout << "There is no need to look for alternatives, nor variations." << endl;
            goto ending;
        }
        else
        {
            cout << "This is a color that can be perceived differently by people with colorblindness." << endl;   
        }
        cout << "Would you like to see which types will perceive your color differently? (Y/N) ";
        cin >> colorAccept;
        if (colorAccept == 'y' || colorAccept == 'Y') // User wants to see the colors
            {
                goto suggest_Color;
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
                goto deuteranomaly;
                break;
            case 2:
                cout << "You have chosen: Protanomaly" << endl;
                goto protanomaly;
                break;
            case 3:
                cout << "You have chosen: Tritanomaly" << endl;
                goto tritanomaly;
                break;
            case 4:
                cout << "You have chosen: Deuteranopia" << endl;
                goto deuteranopia;
                break;
            case 5:
                cout << "You have chosen: Protanopia" << endl;
                goto protanopia;
                break;
            case 6:
                cout << "You have chosen: Tritanopia" << endl;
                goto tritanopia;
                break;
            case 7:
                cout << "You have chosen: Monochromacy" << endl;
                goto monochromacy;
                break;
            default: // If you decide to mess around with the program, it will choose an option for you
                cout << "Invalid Entry. Generating random number..." << endl;
                colorEval = rand() % 8;
                goto color_Evaluator;
        }
    
    deuteranomaly: // Inform the user about Green-Weak Colorblindness
        cout << "Deuteranomaly is the most common form of colorblindness, found in about 5% of people." << endl;
        cout << "It causes Reds, Greens, and Yellows to appear similar." << endl;
        cout << "Many people live with mild deuteranomaly, causing vivid autumn leaves to appear slightly dulled, or shades of green and orange to blend into one another." << endl;
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
        goto ending;
    protanomaly: // Inform the user about Red-Weak Colorblindness
        cout << "Protoanomaly is another common form of colorblindness, seen in 1.03% of people." << endl;
        cout << "Reds appear darker and duller, with oranges and yellows looking very similar to them." << endl;
        cout << "Because it dims the reds in our daily lives, red lights, brakes, and danger text can be hard to spot." << endl;
        if (chosenColor == "Mostly Red" || chosenColor == "Mostly Green" || chosenColor == "More Red and Green than Blue")
        {
            cout << "Your color may pose a problem with those with Protoanomaly." << endl;
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
        goto ending;
    tritanomaly: // Inform the user about Blue-Weak Colorblindness
        cout << "Tritanomaly is a rare case of colorblindness, only held by 0.001% of people." << endl;
        cout << "Commonly known as blue-yellow colorblindness, it causes blues and greens to blend together, and yellows to look pinkish." << endl;
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
        goto ending;
    deuteranopia: // Inform the user about Green Colorblindness
        cout << "Deuteranopia is a harsher form of Deuteranomaly. Rather than it being hard to perceive green, people with deuteranopia can't perceive green at all." << endl;
        cout << "Seen in about 1% of people, Deuteranopia causes greens to be turned into shades of brownish-yellow." << endl;
        cout << "A bright red and green strawberry will look like a strange mix of yellows. Oh no!" << endl;
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
        goto ending;
    protanopia: // Inform the user about Red Colorblindness
        cout << "Protanopia is a more extreme version of Protanomaly. Rather than it being hard to perceive red, people with protanopia can't perceive red at all." << endl;
        cout << "Seen in about 1% of people, Protanopia makes it hard for people to differntiate reds, greens, and everything in between." << endl;
        cout << "Moreover, it causes the reds to appear VERY dark, making it hard for people to drive since they can't perceive the red lights on the traffic signal." << endl;
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
        goto ending;
    tritanopia: // Inform the user about Blue Colorblindness
        cout << "Tritanopia is a very rare form of colorblindness, only present in about 1 in 30,000 people." << endl;
        cout << "People lose the ability to differentiate blues and greens, and yellows will always appear and light pink or grey." << endl;
        cout << "Purple in particular is a problem; it looks like a dark-brown." << endl;
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
        goto ending;
    monochromacy: // I cannot see color my life a silent movie now
        cout << "Monochromacy is the rarest form of colorblindness. It has quite a few forms." << endl;
        cout << "Some people can only see reds, greens, blues, or no color at all! This is known as Achromatopsia." << endl;
        cout << "Unfortunately, unless your color is a form of black or white, your color cannot be perceived at all by these people." << endl;
        cout << "However, the chances of finding them are very rare, with only 1 in every 50,000 people having it." << endl;
        cout << "So it's okay that your color is not perceived well." << endl;
        goto ending;
    ending:
        cout << "Thank you for assessing colors today! I'll see you later!" << endl;
        return 0;
}