/*
给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址正好由四个整数（每个整数位于 0 到 255 之间组成），整数之间用 '.' 分隔。

 

示例:

输入: "25525511135"
输出: ["255.255.11.135", "255.255.111.35"]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/restore-ip-addresses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
参考答案：
https://leetcode-cn.com/problems/restore-ip-addresses/solution/hui-su-suan-fa-hua-tu-fen-xi-jian-zhi-tiao-jian-by/

回溯算法（画图分析剪枝条件）

回溯算法事实上就是在一个树形问题上做深度优先遍历，因此首先需要把问题转换为树形问题。
在画树形图的过程中，你一定会发现有些枝叶是没有必要的，把没有必要的枝叶剪去的操作就是剪枝，
在代码中一般通过 break 或者 contine 和 return （表示递归终止）实现。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	void dfs(std::vector<string> &path, string choice_s, std::vector<string> &res)
	{
		if (path.size() >= 4)
		{
			if (choice_s.size() == 0)
			{
				//ans
				string ans = "";
				for (int i = 0; i < path.size()-1; i++)
				{
					ans += path[i] + ".";
				}
				ans += path[path.size()-1];
				cout << ans << endl;
				res.push_back(ans);
			}
			else
			{
				return;
			}
		}
		for (int i = 1; i <= 3 && i <= choice_s.size(); i++)
		{
			string node = choice_s.substr(0, i);
			//node是否满足
			int num = atoi(node.c_str());
			if (num > 255)
			{
				continue;
			}
			if (node.size() >= 2 && node.at(0) == '0')
			{
				continue;
			}
			string left_choice = choice_s.substr(i);
			path.push_back(node);
			dfs(path, left_choice, res);
			path.pop_back();
		}
	}

    vector<string> restoreIpAddresses(string s) 
    {
    	std::vector<string> path;
    	std::vector<string> res;
   		dfs(path, s, res);
   		return res;
    }
};

int main(int argc, char const *argv[])
{
	string test = "25525511135";
	//"010010"
	string test2 = "010010";
	Solution s;
	s.restoreIpAddresses(test);
	s.restoreIpAddresses(test2);
	return 0;
}