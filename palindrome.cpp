#include <iostream>
#include <vector>
using namespace std;

//暴力破解，时间复杂程度O(N^3)
class Solution {
public:
    string reverseStr(string s){
        string result;
        for (int i = s.length()-1; i >= 0; i--)
        {
            result += s.at(i);
        }
        return result;
    }

    string longestPalindrome(string s) {
        if (s.length() == 0)
        {
            return "";
        }
        vector<string> results;
        for (int i = 0; i < s.length(); i++)
        {
            int j = s.length()-1;
            while (j>i)
            {
                if (s.at(j) == s.at(i))
                {
                    string str = s.substr(i, j-i+1);
                    string reverse = reverseStr(str);
                    if (str == reverse)
                    {
                        results.push_back(str);
                    }
                }
                j--;
            }
        }
        //longest
        string str = s.substr(0,1);
        for (int i = 0; i < results.size(); i ++)
        {
            if (results[i].length() > str.length())
            {
                str = results[i];
            }
        }
        return str;
    }
};

class DPSolution{
public:
    string longestPalindrome(string s) {
        const int len = s.length();
        if (0 == len)
        {
            return "";
        }
        int dp[len][len];
        memset(dp, 0, sizeof(dp));
        //构建动态规划基础数据
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
            if ( i<len-1 && s.at(i) == s.at(i+1) )
            {
                dp[i][i+1] = 2; 
            }
        }
        //动态运算
        int start = 0, maxLen = 1;
        for (int j = 0; j < len; j++)
        {
            for (int i = j - 1; i >=0; i--)
            {
                if (s.at(i) == s.at(j))
                {
                    if ( dp[i+1][j-1] > 0 )
                    {
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                }
                else
                {
                    dp[i][j] = 0;
                }
                if (dp[i][j] > maxLen)
                {
                    start = i;
                    maxLen = dp[i][j];
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main()
{
    string test("cbbd");
    Solution s;
    DPSolution s2;
    string result = s.longestPalindrome(test);
    cout << result << endl;
    result = s2.longestPalindrome(test);
    cout << result << endl;
    return 0;
}
