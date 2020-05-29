/*
题目难度：困难

给定一个非空二叉树，返回其最大路径和。

本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。

示例 1:
输入: [1,2,3]

       1
      / \
     2   3

输出: 6

示例 2:
输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
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

//答案参考了别人的解答思路
//https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/solution/er-cha-shu-zhong-de-zui-da-lu-jing-he-by-ikaruga/313184

class Solution {
public:
	//返回以root结尾的路径的最大路径和
	int dfs(TreeNode *root)
	{
		if (!root)
		{
			return 0;
		}
		int leftMax = max(0, dfs(root->left));
		int rightMax = max(0, dfs(root->right));
		res = max(res, leftMax + root->val + rightMax);
		return root->val + max(leftMax, rightMax);
	}
    int maxPathSum(TreeNode* root) {
    	//关键在于：查找返回经过root的单边分支最大和
    	res = INT_MIN; //因为一定要经过一个节点，所以设置最小值为INT_MIN
    	dfs(root);
    	return res;
    }
private:
	int res;
};