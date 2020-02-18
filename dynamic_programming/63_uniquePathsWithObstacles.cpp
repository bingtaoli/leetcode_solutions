#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        long dp[m][n];
        //构建基础数据
        for (int i = m-1; i>=0; i--)
        {
            if (obstacleGrid[n-1][i] == 1)
            {
                for (; i>=0; i--)
                {
                    dp[i][n-1] = 0;
                }
            }
            else
            {
                dp[i][n-1] = 1;
            }
        }
        for (int j = n-1; j>=0; j--)
        {
            if (obstacleGrid[j][m-1] == 1)
            {
                for (; j>=0; j--)
                {
                    dp[m-1][j] = 0;
                }
            }
            else
            {
                dp[m-1][j] = 1;
            }
        }
        //动态规划，规划路径从下至上，从右往左
        //公式： dp[i][j] = dp[i+1][j] + dp[i][j+1]
        for (int j = n-2; j >=0; j--)
        {
            for (int i = m-2; i>=0; i--)
            {
                if (obstacleGrid[j][i] == 1)
                {
                    dp[i][j] = 0;
                }
                else 
                {
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                }
            }
        }
        //返回
        return dp[0][0];
    }
};