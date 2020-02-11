#include <iostream>
using namespace std;

//https://leetcode-cn.com/problems/decode-ways/submissions/
//注意要点，有0的情况需要判断

class Solution {
public:
    //dp[i][j]表示s字符串i到j之间的解码方法数
    //dp[i-1][j]的解法有 
    //1、s[i-1]作为单独数字，dp[i][j]作为独立个体
    //2、如果s[i-1]和s[i]组成一个数字，dp[i+1][j]作为独立个体
    //所以dp[i-1][j] = dp[i][j] + maybe(dp[i+1][j])
    int numDecodings(string s) {
        const int len = s.length();
        int dp[len][len];
        //构建基础数据
        for(int i = 0; i < len; i++)
        {
        	int value = s[i]-'0';
        	if (value)
        	{
        		dp[i][i] = 1;
        	}
        	else
        	{
        		dp[i][i] = 0;
        	}
            if (i < len-1)
            {
                int a = s[i]-'0';
                int b = s[i+1]-'0';
                int value = a*10+b;
                if ( a && b && (value <= 26) )
                {
                    dp[i][i+1] = 2;
                }
                else if ( a && b)
                {
                    dp[i][i+1] = 1;
                }
                else if ( a && (value <= 26) )
                {
                	dp[i][i+1] = 1;
                }
                else
                {
                	dp[i][i+1] = 0;
                }
            }
        }
        //动态规划，规划顺序从左往右
        for (int j = 2; j < len; j++)
        {
            for (int i = j-2; i >= 0; i--)
            {
                int result(0);
                int a = s[i]-'0';
                int b = s[i+1]-'0';
                int value = a*10+b;
                if (a)
                {
                	result += dp[i+1][j];
                }
                if ( a && (value <= 26) )
                {
                    result += dp[i+2][j];
                }
                dp[i][j] = result;
            }
        }
        return dp[0][len-1];
    }
};

int main()
{
	string test = "226";
	Solution s;
	int a = s.numDecodings("226");
	assert(a == 3);
	a = s.numDecodings("0");
	assert(a == 0);
	a = s.numDecodings("10");
	assert(a == 1);
	a = s.numDecodings("00");
	assert(a == 0);
	a = s.numDecodings("012");
	assert(a == 0);
	return 0;
}