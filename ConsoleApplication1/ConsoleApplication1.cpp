// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string CaesarCipher(string text, int encryptionFlag, int key)
{
    bool error = false;
    // checks to see if the encryption flag is in range
    if (encryptionFlag < 0 || encryptionFlag > 1)
    {
        // sets the error flag to on since the encryption flag is out of range
        error = true;
        cout << "Please set the encryption flag to 0 for encrypting or 1 for decrypting ";
    }

    // checks to see if the key is in range
    if (key < 0 || key > 25)
    {
        // sets the error flag to on since the key is out of range
        error = true;
        cout << "Please set key between 0 and 25 ";
    }

    // checks if the error flag is false
    if (error == true)
    {
        // ends function since one of the parameters is out of range
        cout << "\n";
        return text;
    }

    for (int i = 0; i < text.length(); i++)
    {
        if (encryptionFlag == 0)
        {
            // had to convert it to an integer value because the max askii value is 127 and if go above it I can't subtract 26 anymore
            int val = (int)text[i] + key;
            // val > 90 is to check for the to capital overflow and the val > 122 is for the lower case overflow
            // val <= 115 and key >= 7 is to check that it belong to the capital set since it is overlapping with the lowercase set
            // if ((val > 90 && ((val <= 115 && key >= 7) || (val < 97 && key < 7))) || val > 122)
            if (val > 90)
            {
                val = val - 26;
            }
            text[i] = val;
        }

        else if (encryptionFlag == 1)
        {
            text[i] = text[i] - key;
            if (text[i] < 65 || text[i])
            {
                text[i] = text[i] + 26;
            }
        }
    }

    cout << text << "\n";
    return text;
}

int main()
{
    /*
    string test1 = CaesarCipher("hello", 0, 1);
    string test2 = CaesarCipher("ifmmp", 1, 1);
    string test3 = CaesarCipher("abcxyz", 0, 8);
    string test4 = CaesarCipher("cdezab", 1, 2);
    */
    string test1 = CaesarCipher("z", 0, 25);
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
