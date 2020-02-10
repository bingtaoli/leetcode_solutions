#include <iostream>
using namespace std;

/*
 * https://leetcode-cn.com/problems/minimum-path-sum/
 */

class Solution {
public:
    //dp[i][j] = min(dp[i+1][j],dp[i][j+1])+value
    int minPathSum(vector<vector<int>>& grid) {
        //长m宽n的矩阵
        const int m = grid[0].size();
        const int n = grid.size();
        int dp[m][n];
        //构建基础数据
        int sum = 0;
        for (int i = m-1; i >=0; i--)
        {
            sum += grid[n-1][i];
            dp[i][n-1] = sum;
        }
        sum = 0;
        for (int j = n-1; j >= 0; j--)
        {
            sum += grid[j][m-1];
            dp[m-1][j] = sum;
        }
        //动态规划，顺序为从下至上，从右向左
        for (int j = n-2; j >=0; j--)
        {
            for (int i = m-2; i >= 0; i--)
            {
                int a = dp[i+1][j];
                int b = dp[i][j+1];
                int m = a < b ? a : b;
                int value = grid[j][i];
                dp[i][j] = m + value;
            }
        }
        return dp[0][0];
    }
};
