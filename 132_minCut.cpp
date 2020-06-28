/*
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回符合要求的最少分割次数。

示例:

输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
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

	void dfs(string s, std::vector<string> &path, int &cutNum)
	{
		if (s.size() == 0 && path.size() > 0)
		{
			cutNum = min(cutNum, (int)path.size()-1);
		}
		for (int i = 1; i <= s.size(); i++)
		{
			//make a choice
			string choice = s.substr(0, i);
			if ( !isHuiWen(choice) )
			{
				continue;
			}
			//cout << "choice: " << choice << endl;
			path.push_back(choice);
			dfs(s.substr(i), path, cutNum);
			path.pop_back();
		}
	}

    int minCut(string s) 
    {
    	std::vector<string> path;
    	int cutNum(INT_MAX);	
    	dfs(s, path, cutNum);
    	return cutNum;
    }
};

int main(int argc, char const *argv[])
{
	{
		Solution s;
		string test = "aab";
		int res = s.minCut(test);
		cout << res << endl;
	}
	return 0;
}