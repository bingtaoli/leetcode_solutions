#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	/*
	这个dp其实就是暴力破解,是一种错误思路
	*/
    int maxProfit_try(vector<int>& prices) {
        /*
        dp[i][j]表示i天买入股票，j天卖出
        dp[i][j] = dp[i][j-1] + prices[j] - prices[j-1]
        */
        const int len = prices.size();
        if (!len)
        {
            return 0;
        }
        int dp[len][len];
        int result(0);
        for (int i = 0; i < len-1; i++)
        {
            dp[i][i+1] = prices[i+1] - prices[i];
            result = max(dp[i][i+1], result);
        }
        for (int j = 2; j < len; j++)
        {
            for (int i = j-2; i>=0; i--)
            {
                dp[i][j] = dp[i][j-1] + prices[j] - prices[j-1];
                result = max(dp[i][j], result);
            }
        }
        return result;
    }
    
};
