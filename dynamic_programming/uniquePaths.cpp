
/*
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。

问总共有多少条不同的路径？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/unique-paths
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// dp[m-1][n-1] = dp[m-1][n] + dp[m][n-1]
    int uniquePaths(int m, int n) {
    	int dp[m][n];
        //基本数据
        for (int i = 0; i < m; i++)
        {
        	dp[i][n-1] = 1;
        }
        for (int j = 0; j < n; j++)
        {
        	dp[m-1][j] = 1;
        }
        //动态规划，规划路径为自底向上，自右向左
        for (int j = n-2; j >= 0; j--)
        {
        	for (int i = m-2; i >=0; i--)
        	{
        		dp[i][j] = dp[i+1][j] + dp[i][j+1];
        	}
        }
        return dp[0][0];
    }
};