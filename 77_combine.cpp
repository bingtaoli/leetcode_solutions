/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/combinations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(std::vector<int> &path, int n, int k, vector<vector<int> > &res)
	{
		//end of recursion
		if ( path.size() == n )
		{
			res.push_back(path);
			return;
		}
		if (path.size() == k)
		{
			res.push_back(path);
			return;
		}
		for (int i = 1; i <= n; i++)
		{
			if ( path.size()>0 && path.back() > i )
			{
				//去重，只允许[1,3]，不允许[3,1]
				continue;
			}
			if ( find(path.begin(), path.end(), i) != path.end() )
			{
				continue;
			}
			//make a choice
			path.push_back(i);
			dfs(path, n, k, res);
			//back
			path.pop_back();
		}
	}
    vector<vector<int> > combine(int n, int k) 
    {
   		vector<vector<int> > res;
   		std::vector<int> path;
   		dfs(path, n, k, res);
   		return res;
    }
};

int main()
{
	Solution s;
	vector<vector<int> >  res = s.combine(4, 2);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}