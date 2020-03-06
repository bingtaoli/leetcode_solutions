#include <iostream>
using namespace std;

class Solution {
public:
    char toUpper(char input)
    {
        if (input >= 'a' && input <= 'z')
        {
            return input + 'A' - 'a';
        }
        return input;
    }
    bool isPalindrome(string s) 
    {
        string filtered;
        for (int i = 0; i < s.size(); i++)
        {
            if ( (s[i] >= 'a' and s[i] <= 'z') || (s[i] >= '0' and s[i] <= '9') || (s[i]>='A' && s[i] <= 'Z'))
            {
                filtered += s[i];
            }
        }
        cout << filtered << endl;
        for (int i = 0; i < filtered.size(); i++)
        {
            int k = filtered.size() - i - 1;
            if (filtered[i] == filtered[k] || toUpper(filtered[i]) == toUpper(filtered[k]) )
            {
                continue;
            }
            else
            {
                cout << filtered[i] << filtered[k] << endl;
                return false;
            }
        }
        return true;
    }
};
