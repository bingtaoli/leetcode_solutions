#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
        /*
        dp[i]表示i级的台阶有多少中方法，到达i阶的最后一步分两种情况，爬1阶或爬两阶。
        dp[i] = dp[i-1] + dp[i-2]
        */
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else if (n == 3)
        {
            return 3;
        }
        int dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
