#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/*
		这个解法是我自己写的，复杂化了，把一维的问题转出二维了，可能是之前做的都是二维问题，所以反倒复杂化了。
		这个明显就是个一维问题。
		贴上这个错误解答
	*/
    int maxSubArray_try(vector<int>& nums) 
    {
        const int len = nums.size();
        int **dp = new int*[len];
        for (int i = 0; i < len; i++)
        {
            dp[i] = new int[len];
        }
        int result(INT_MIN);
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = nums[i];
            result = result > dp[i][i] ? result : dp[i][i];
            if (i < len-1)
            {
                if (nums[i+1] > 0)
                {
                    dp[i][i+1] = nums[i] + nums[i+1];
                    result = result > dp[i][i+1] ? result : dp[i][i+1];
                }
            }
        }
        /*
        公式求 dp[i-1][j] 
        if ( dp[i][j] > 0 )
            dp[i-1][j] = nums[i] + dp[i][j]
        else
            dp[i-1][j] = nums[i]
        */
        //迭代
        for (int j = 0; j < len; j++)
        {
            for (int i = j; i >= 1; i--)
            {
                if (dp[i][j] > 0)
                {
                    dp[i-1][j] = nums[i-1] + dp[i][j];
                }
                else
                {
                    dp[i-1][j] = nums[i-1];
                }
                printf("dp[%d][%d]:%d dp[%d][%d]:%d\n", i, j, dp[i][j], i-1, j, dp[i-1][j]);
                result = result > dp[i-1][j] ? result : dp[i-1][j];
            }
        }
        return result;
    }
    int maxSubArray(vector<int>& nums)
    {
    	//公式： dp[i]表示以i结尾的字符串的最大子序和
    	// dp[i] = max( num[i], dp[i-1]+num[i] )
    	int result = nums[0];
    	const int len = nums.size();
    	int dp[len];
    	dp[0] = nums[0];
    	for ( int i = 1; i < len; i++ )
    	{
    		dp[i] = max(nums[i], dp[i-1]+nums[i]);
    		result = max(result, dp[i]); 
    	}
    	return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
	std::vector<int> v(a, a+9);
	Solution s;
	cout << s.maxSubArray(v) << endl;
	int b[4] = {2,-1,3,-1};
	std::vector<int> v2(b, b+4);
	cout << s.maxSubArray(v2) << endl;
	return 0;
}