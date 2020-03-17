
#include "characterCounter.h"

CharacterCounter::CharacterCounter()
{
    CharacterCounter::fTotalNumberOfCharacters = 0;
    //fCharacterCounts[256] = { };
    for (int i = 0; i < 255; i++) {
        fCharacterCounts[i] = 0;
    }
}

void CharacterCounter::count(unsigned char aCharacter)
{
    fCharacterCounts[aCharacter]++;
}

ostream& operator<<(ostream& aOstream, const CharacterCounter& aCharacterCounter) {

    aOstream << "Character Counts for  " << aCharacterCounter.fTotalNumberOfCharacters << " characters:" << endl;

    for (int i = 0; i < 255; i++) 
    {
        if (aCharacterCounter.fCharacterCounts[i] > 0) 
            aOstream << (char)i << "  :" << aCharacterCounter.fCharacterCounts[i] << endl;
    }
        
        

    return aOstream;
}


