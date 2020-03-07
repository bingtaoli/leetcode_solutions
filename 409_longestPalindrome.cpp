#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) 
    {
        // 2n+1 or 2n
        unordered_map<char, int> hash;
        for (int i = 0; i < s.size(); i++)
        {
            hash[s[i]] = hash[s[i]] + 1;
        }
        int result(0);
        bool hasSingle(false);
        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            if (iter->second % 2 == 0)
            {
                result += iter->second;
            }
            else
            {
                result += iter->second - 1;
                hasSingle = true;
            }
        }
        if (hasSingle)
        {
            result++;
        }
        return result;
    }
};
