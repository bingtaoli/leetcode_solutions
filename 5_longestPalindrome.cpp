class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len = s.size();
        if (!len)
        {
            return "";
        }
        int maxLen = 1;
        string res;
        int dp[len][len];
        memset(dp, 0, sizeof(int)*len*len);
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = 1;
            if (res.empty())
            {
                res = s[i];
            }
            if (i > 0)
            {
                if ( s[i-1] == s[i])
                {
                    dp[i-1][i] = 1;
                    maxLen = 2;
                    res = s.substr(i-1,2);
                    cout << "max len is 2: " << res << endl;
                }
                else
                {
                    dp[i-1][i] = 0;
                }
            }
        }
        //动态规划， if (dp[i][j] && s[i-1] == s[j+1]) then dp[i-1][j+1] = 1
        for (int i = 2; i < len; i++)
        {
            for (int j = i-2; j >= 0; j--)
            {
                if (s[j] == s[i] && dp[j+1][i-1])
                {
                    dp[j][i] = 1;
                    int tmp = i - j + 1;
                    if (tmp > maxLen)
                    {
                        maxLen = tmp;
                        res = s.substr(j, maxLen);
                        cout << "res change:" << res << endl;
                    }
                }
            }
        }
        return res;
    }
};
