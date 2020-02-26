#include <iostream>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) 
    {
    	/* 
    	dp[i] 表示以i家收尾的最高收获金额
    	i结尾有两种选择，上一家相隔1家或2家。3家就没必要了，因为完全可以多加1家
    	dp[i] = max( dp[i-2]+nums[i], dp[i-3]+nums[i] )
		*/
		const int len = nums.size();
		if (len == 0)
		{
			return 0;
		}
		int dp[len];
		int result = nums[0];
		if (len == 1)
		{
			dp[0] = nums[0];
			return dp[0];
		}
		else if (len == 2)
		{
			dp[0] = nums[0];
			dp[1] = num[1];
			return max(dp[0], dp[1]);
		}
		else
		{
			dp[0] = nums[0];
			dp[1] = num[1];
			dp[2] = nums[0]+nums[2];
		}
		for (int i = 3; i < len; i++)
		{
			dp[i] = max(dp[i-2]+nums[i], dp[i-3]+nums[i]);
		}
		return max(dp[len-1], dp[len-2]);
    }
};

