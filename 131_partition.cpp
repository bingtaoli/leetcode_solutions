/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例:

输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
	bool isHuiWen(string s)
	{
		int len = s.size();
		for (int i = 0; i < len; i++)
		{
			int j = len - 1 - i;
			if (i < j)
			{
				if (s[i] != s[j])
				{
					return false;
				}
			}
		}
		return true;
	}

	void dfs(string s, std::vector<string> &path, vector<vector<string> >  &res)
	{
		if (s.size() == 0)
		{
			res.push_back(path);
		}
		for (int i = 1; i <= s.size(); i++)
		{
			//make a choice
			string choice = s.substr(0, i);
			if ( !isHuiWen(choice) )
			{
				continue;
			}
			cout << "choice: " << choice << endl;
			path.push_back(choice);
			dfs(s.substr(i), path, res);
			path.pop_back();
		}
	}

    vector<vector<string> > partition(string s) 
    {
    	std::vector<string> path;
    	vector<vector<string> > res;	
    	dfs(s, path, res);
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		string test = "aab";
		vector<vector<string> > res = s.partition(test);
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < res[i].size(); j++)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}