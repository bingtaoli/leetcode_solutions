#include <iostream>
using namespace std;

class Solution {
public:
    int waysToStep(int n) 
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        long dp[n+1];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        /*
        公式: dp[n] = 最后一步是1 + 最后一步是2 + 最后一步是3
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3]
        */
        for (int i = 4; i <= n; i++)
        {
            dp[i] = dp[i-1]%1000000007 + dp[i-2]%1000000007 + dp[i-3]%1000000007;
        }
        cout << dp[n] << endl;
        return dp[n] % 1000000007;
    }
};
