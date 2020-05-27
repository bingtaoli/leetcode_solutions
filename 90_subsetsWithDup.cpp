/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	void dfs(std::vector<int> &index_path, std::vector<int> nums, int len, vector<vector<int> > &res)
	{
		if (index_path.size() == len)
		{
			std::vector<int> path;
			for (int i = 0; i < index_path.size(); i++)
			{
				path.push_back(nums[index_path[i]]);
			}
			res.push_back(path);
			return;
		}
		set<int> currentLevelUsed;
		for (int i = 0; i < nums.size(); i++)
		{
			if ( find(index_path.begin(), index_path.end(), i) != index_path.end() )
			{
				continue;
			}
			if (index_path.size() > 0 && index_path.back() > i)
			{
				//只允许1,2,2 不允许2,2,1 防止重复
				continue;
			}
			if (currentLevelUsed.count(nums[i]) == 1)
			{
				//每个level去重
				continue;
			}
			currentLevelUsed.insert(nums[i]);
			index_path.push_back(i);
			dfs(index_path, nums, len, res);
			index_path.pop_back();
		}
	}
    vector<vector<int> > subsetsWithDup(vector<int>& nums) 
    {
    	//多个长度的子集，0-size
    	int len = nums.size();
    	//排序，从小到大
    	std::sort(nums.begin(), nums.end());
    	vector<vector<int> > res;
    	for (int i = 0; i <= len; i++)
    	{
    		std::vector<int> index_path;
    		dfs(index_path, nums, i, res);
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	Solution s;
	vector<vector<int> > res = s.subsetsWithDup(nums);
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