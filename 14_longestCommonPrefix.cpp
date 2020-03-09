#include <iostream>
using namespace std;

class Solution {
public:
    string comm_prefix(const string &s1, const string &s2)
    {
        string result;
        int i(0);
        while (i < s1.size() && i < s2.size())
        {
            if (s1[i] == s2[i])
            {
                result += s1[i];
            }
            else
            {
                break;
            }
            i++;
        }
        return result;
    }
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (!strs.size())
        {
            return "";
        }
        string result = strs[0];
        string last = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            string tmp = comm_prefix(last, strs[i]);
            last = tmp;
            result = last;
            if (!last.size())
            {
                break;
            }
        }
        return result;
    }
};
