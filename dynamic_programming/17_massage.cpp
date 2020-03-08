#include <iostream>
using namespace std;

class Solution {
public:
    int massage(vector<int>& nums) 
    {
        int len = nums.size();
        if (len == 0)
        {
            return 0;
        }
        if (len == 1)
        {
            return nums[0];
        }
        if (len == 2)
        {
            return max(nums[0], nums[1]);
        }
        if (len == 3)
        {
            return max(nums[0]+nums[2], nums[1]);
        }
        int dp[len];
        //dp[index]表示以index为预约结尾的最大总预约分钟数
        dp[0] = nums[0];
        dp[1] = nums[1];
        dp[2] = nums[0]+nums[2];
        dp[3] = max(nums[0]+nums[3], nums[1]+nums[3]);
        /*
        公式: dp[n] = max(dp[n-3]+nums[n], nums[n-2]+nums[n])
        */
        for (int i = 3; i < len; i++)
        {
            dp[i] = max(dp[i-3]+nums[i], dp[i-2]+nums[i]);
        }
        return max(dp[len-1], dp[len-2]);
    }
};
