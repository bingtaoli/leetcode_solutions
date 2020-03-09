#include <iostream>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
    {
        map<char, int> g_map;
        g_map['I'] = 1;
        g_map['V'] = 5;
        g_map['X'] = 10;
        g_map['L'] = 50;
        g_map['C'] = 100;
        g_map['D'] = 500;
        g_map['M'] = 1000;
        int result(0);
        for ( int i = 0; i < s.size(); )
        {
            if ( (i < s.size()-1) && 
                 ( (s[i] == 'I' && s[i+1] == 'V') || (s[i] == 'I' && s[i+1] == 'X')
                     || (s[i] == 'X' && s[i+1] == 'L') || (s[i] == 'X' && s[i+1] == 'C')
                     || (s[i] == 'C' && s[i+1] == 'D') || (s[i] == 'C' && s[i+1] == 'M') )
               )
            {
                //extra
                cout << "extra" << s[i] << s[i+1] << endl;
                result += g_map[s[i+1]] - g_map[s[i]];
                i = i+2;
            }
            else
            {
                result += g_map[s[i]];
                i += 1;
            }
        }
        return result;
    }
};
