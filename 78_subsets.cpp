/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subsets
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void dfs(std::vector<int> &path, std::vector<int> nums, int len, vector<vector<int> > &res)
	{
		if (path.size() == len)
		{
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); i++)
		{
			int v = nums[i];
			if ( find(path.begin(), path.end(), v) != path.end() )
			{
				continue;
			}
			if (path.size() > 0 && path.back() > v)
			{
				//只允许1,2,3 不允许1,3,2 防止重复
				continue;
			}
			path.push_back(v);
			dfs(path, nums, len, res);
			path.pop_back();
		}
	}
    vector<vector<int> > subsets(vector<int>& nums) 
    {
    	//多个长度的子集，0-size
    	int len = nums.size();
    	vector<vector<int> > res;
    	for (int i = 0; i <= len; i++)
    	{
    		std::vector<int> path;
    		dfs(path, nums, i, res);
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	Solution s;
	vector<vector<int> > res = s.subsets(nums);
	cout << res.size() << endl;
	return 0;
}