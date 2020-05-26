/*
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(std::vector<int> path, std::vector<int> choices)
	{
		if (path.size() == choices.size())
		{
			res.push_back(path);
		}
		for (int i = choices.size()-1; i >=0; i--)
		{
			//make a choice
			int v = choices[i];
			// find 防止重复选择
			if (find(path.begin(), path.end(), v) != path.end())
			{
				continue;
			}
			path.push_back(v);
			dfs(path, choices);
			path.pop_back();
		}
	}
    vector<vector<int> > permute(vector<int>& nums) 
    {
    	std::vector<int> path;
  		dfs(path, nums);
  		return res;
    }
private: 
	vector<vector<int> > res;
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution s;
	vector<vector<int> > res = s.permute(nums);
	cout << res.size() << endl;
	return 0;
}
