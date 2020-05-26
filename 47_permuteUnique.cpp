/*
给定一个可包含重复数字的序列，返回所有不重复的全排列。

示例:
输入: [1,1,2]
输出:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutations-ii/
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

这道题和全排列I解法几乎一样，不同点在于怎么去重？


*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	void dfs(std::vector<int> &index_path, std::vector<int> &choices, vector<vector<int> > &res)
	{
		if (index_path.size() == choices.size())
		{
			std::vector<int> path;
			for (int i = 0; i < index_path.size(); i++)
			{
				path.push_back( choices[index_path[i]] );
			}
			res.push_back(path);
			return;
		}
		set<int> currentLevelUsed;
		for (int i = choices.size()-1; i >= 0; i--)
		{
			if (find(index_path.begin(), index_path.end(), i) != index_path.end())
			{
				continue;
			}
			int v = choices[i];
			if (currentLevelUsed.count(v) == 1)
			{
				//同一层选择不要用相同的数字
				//cout << "same level, filter duplicate " << v << endl;
				continue;
			}
			currentLevelUsed.insert(v);
			cout << "choose " << i << endl;
			//make a choice
			index_path.push_back(i);
			dfs(index_path, choices, res);
			//back 
			index_path.pop_back();
		}
	}
    vector<vector<int> > permuteUnique(vector<int>& nums) 
    {
    	std::vector<int> index_path;
    	vector<vector<int> > res;
    	dfs(index_path, nums, res);
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums;
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(2);
	Solution s;
	vector<vector<int> > res = s.permuteUnique(nums);
	cout << res.size() << endl;
	return 0;
}
