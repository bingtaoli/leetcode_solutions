#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int len = nums.size();
        if (!len)
        {
            return 0;
        }
        int dp[len];
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < len; i++)
        {
            dp[i] = max(nums[i], dp[i-1]+nums[i]);
            result = max(result, dp[i]);
        }
        return result;
    }
};
