#include <iostream>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) 
    {
        bool firstUpper(false);
        bool firstLower(false);
        bool hasLower(false); //from second char has lower
        bool hasUpper(false); //from second char has upper
        if (word[0] >= 'A' && word[0] <='Z')
        {
            firstUpper = true;
        }
        else
        {
            firstLower = true;
        }
        for (int i = 1; i < word.size(); i++)
        {
            if ( word[i] >= 'a' && word[i] <= 'z' )
            {
                hasLower = true;
            }
            if ( word[i] >= 'A' && word[i] <= 'Z' )
            {
                hasUpper = true;
            }
            if (firstLower)
            {
                if (word[i] >= 'A' && word[i] <= 'Z')
                {
                    return false;
                }
            }
            if (firstUpper)
            {
                if ( hasLower && word[i] >= 'A' && word[i] <= 'Z')
                {
                    return false;
                }
                if ( hasUpper && word[i] >= 'a' && word[i] <= 'z')
                {
                    return false;
                }
            }
        }
        return true;
    }
};
