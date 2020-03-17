#include <iostream>
#include <fstream>
#include "characterCounter.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cerr << "Arguments Missing" << endl;
        cerr << "Usage: charactercountewr <filename> " << endl;

        // Return error: not enough arguments
        return 1;

    }

    CharacterCounter lCounter;
    unsigned char lChar;

    try
    {
        ifstream lInput(argv[1]);

        while (lInput >> noskipws >> lChar)
        {

            lCounter.count(lChar);
        }

        cout << lCounter;
        lInput.close();
    }
    catch (int e) {
        cerr << "Could not open text file, error returned: " << e << endl;
        return 1;
    }


    return 0;

}
