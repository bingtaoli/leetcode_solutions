#include <iostream>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col)
    {
        grid[row][col] = '0';
        if (row -1 >= 0 && grid[row-1][col] == '1')
        {
            dfs(grid, row-1, col);
        }
        if (row+1 < row_nums && grid[row+1][col] == '1')
        {
            dfs(grid, row+1, col);
        }
        if (col-1>=0 && grid[row][col-1] == '1')
        {
            dfs(grid, row, col-1);
        }
        if (col+1<col_nums && grid[row][col+1] == '1')
        {
            dfs(grid, row, col+1);
        }
    }
    int numIslands(vector<vector<char>>& grid) 
    {
        if (!grid.size())
        {
            return 0;
        }
        int result(0);
        col_nums = grid[0].size();
        row_nums = grid.size();
        for (int i = 0; i < row_nums; i++)
        {
            for (int j = 0; j < col_nums; j++)
            {
                if (grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
private:
    int col_nums;
    int row_nums;
};
