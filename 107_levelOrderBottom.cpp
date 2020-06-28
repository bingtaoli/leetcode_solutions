/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：

[
  [15,7],
  [9,20],
  [3]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
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
    vector<vector<int> > levelOrderBottom(TreeNode* root) 
    {
    	vector<vector<int> > res;
    	if (!root)
    	{
    		return res;
    	}
    	queue<TreeNode *> q;
    	q.push(root);
    	while (!q.empty())
    	{
    		std::vector<int> curLevel;
    		std::vector<TreeNode *> nextLevel;
    		while (!q.empty())
    		{
    			TreeNode *cur = q.front();
    			q.pop();
    			curLevel.push_back(cur->val);
    			if (cur->left)
    			{
    				nextLevel.push_back(cur->left);
    			}
    			if (cur->right)
    			{
    				nextLevel.push_back(cur->right);
    			}	
    		}
    		for (int i = 0; i < nextLevel.size(); i++)
    		{
    			q.push(nextLevel[i]);
    		}
    		res.insert(res.begin(), curLevel);
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	{
		TreeNode *node1 = new TreeNode(3);
		TreeNode *node2 = new TreeNode(9);
		TreeNode *node3 = new TreeNode(20);
		TreeNode *node4 = new TreeNode(15);
		TreeNode *node5 = new TreeNode(7);
		node1->left = node2;
		node1->right = node3;
		node3->left = node4;
		node3->right = node5;
		Solution s;
		vector<vector<int> > res = s.levelOrderBottom(node1);
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
