// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string CaesarCipher(string text, int encryptionFlag, int key)
{
    // creating my error flag and error message
    bool error = false;
    string errorMessage;
    // checks to see if the encryption flag is in range
    if (encryptionFlag < 0 || encryptionFlag > 1)
    {
        // sets the error flag to on since the encryption flag is out of range
        error = true;
        errorMessage = errorMessage + "Please set the encryption flag to 0 for encrypting or 1 for decrypting. ";
    }

    // checks to see if the key is in range
    if (key < 0 || key > 25)
    {
        // sets the error flag to on since the key is out of range
        error = true;
        errorMessage = errorMessage + "Please set key between 0 and 25. ";
    }

    // checks if the error flag is false
    if (error == true)
    {
        // ends function since one of the parameters is out of range
        return errorMessage;
    }

    // looping through each character in the text
    for (int i = 0; i < text.length(); i++)
    {
        // catches any non letters and skips it to prevent it from changing
        if (text[i] < 65 || (text[i] > 90 && text[i] < 97) || text[i] > 122)
        {
            continue;
        }

        // encrypting
        else if (encryptionFlag == 0)
        {
            // adding the key to the ascii value
            // had to convert it to an integer value because the max ascii value is 127 and if go above it I can't subtract 26 anymore because it overflows
            int asciiVal = (int)text[i] + key;
            // this if statement is for checking if ascii value goes beyond 90 (Z) or 122 (z)
            // asciiVal > 90 is to check for the to capital overflow and the asciiVal > 122 is for the lower case overflow
            // since text[i] is currently unchanged I can check to see if it is orginally from the capital set by using text[i] <= 90 so the lower case set doesn't get affected
            if ((asciiVal > 90 && text[i] <= 90) || asciiVal > 122)
            {
                // subtract 26 to get to the correct ascii value since there is 26 letters in the alphabet
                asciiVal = asciiVal - 26;
            }
            // changing the character of the text
            text[i] = asciiVal;
        }

        // decrypting
        else
        {
            // getting the value before it changes
            char unchanged = text[i];
            // subtracting ascii value to the key
            text[i] = text[i] - key;
            // this if statement is for checking if ascii value goes before 65 (A) or 97 (a)
            // asciiVal < 65 is to check for the to capital ? and the asciiVal < 97 is for the lower case ?
            // i check to see if the original value is from the lower case set by using unchanged >= 97 so the upper case set doesnt get affected
            if (text[i] < 65 || (text[i] < 97 && unchanged >= 97))
            {
                // add 26 to get to the correct ascii value since there is 26 letters in the alphabet
                // changing the character of the text
                text[i] = text[i] + 26;
            }
        }
    }
    // returning the text
    return text;
}

int main()
{
    string test1 = CaesarCipher("hello", 0, 1);
    cout << test1 << "\n";
    string test2 = CaesarCipher("ifmmp", 1, 1);
    cout << test2 << "\n";
    string test3 = CaesarCipher("abcxyz", 0, 2);
    cout << test3 << "\n";
    string test4 = CaesarCipher("cdezab", 1, 2);
    cout << test4 << "\n";

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


