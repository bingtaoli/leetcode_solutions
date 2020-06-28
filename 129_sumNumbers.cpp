/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。

例如，从根到叶子节点路径 1->2->3 代表数字 123。

计算从根到叶子节点生成的所有数字之和。

说明: 叶子节点是指没有子节点的节点。

示例 1:

输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:

输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    void dfs(TreeNode *root, std::vector<int> &path, std::vector<int> &res)
    {
    	if (!root)
    	{
    		return;
    	}
    	path.push_back(root->val);
    	if (!root->left && !root->right && path.size() > 0)
    	{
    		//leaf node
    		int tmp(0);
    		int n = path.size();
    		for (int i = 0; i < n; i++)
    		{
    			tmp = tmp * 10 + path[i];
    		}
    		res.push_back(tmp);
    	}
    	dfs(root->left, path, res);
    	dfs(root->right, path, res);
    	path.pop_back();
    }

    int sumNumbers(TreeNode* root) 
    {
    	std::vector<int> path;
    	std::vector<int> res;
    	int sum(0);
    	dfs(root, path, res);
    	for (int i = 0; i < res.size(); i++)
    	{
    		//cout << res[i] << " ";
    		sum += res[i];
    	}
    	cout << endl;
    	return sum;
    }
};

int main(int argc, char const *argv[])
{
	{
		TreeNode *node1 = new TreeNode(1);
		TreeNode *node2 = new TreeNode(2);
		TreeNode *node3 = new TreeNode(3);
		node1->left = node2;
		node1->right = node3;
		Solution s;
		s.sumNumbers(node1);
	}
	return 0;
}