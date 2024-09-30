// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

string CaesarCipher(string text, int encryptionFlag, int key)
{
    bool error = false;
    if (encryptionFlag < 0 || encryptionFlag > 1)
    {
        error = true;
        cout << "Please set the encryption flag to 0 for encrypting or 1 for decrypting ";
    }

    if (key < 0 || key > 26)
    {
        error = true;
        cout << "Please set key between 0 and 26 ";
    }

    if (error == true)
    {
        cout << "\n";
        return text;
    }

    for (int i = 0; i < text.length(); i++)
    {
        if (encryptionFlag == 0)
        {
            text[i] = text[i] + key;
            int val = (int)text[i];
            cout << text[i] << val << "\n";
            if ((text[i] > 90 && text[i] < 97) || text[i] > 122)
            {
                text[i] = text[i] - 26;
            }

            val = (int)text[i];
            cout << text[i] << " " << val;

        }

        else if (encryptionFlag == 1)
        {
            text[i] = text[i] - key;
            if (text[i] < 65)
            {
                text[i] = text[i] + 26;
            }
        }
    }

    // cout << text << "\n";
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
    string test1 = CaesarCipher("z", 0, 4);
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
