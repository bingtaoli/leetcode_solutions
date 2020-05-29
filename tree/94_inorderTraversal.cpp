/*
给定一个二叉树，返回它的中序 遍历。

1.前序遍历：先访问根节点——左子树——右子树。
2.中序遍历：先访问左子树——根节点——右子树，按照这个顺序。
3.后序遍历：和前面差不多，先访问树的左子树——右子树——根节点。按层遍

示例：
输入: [1,null,2,3]
   1
    \
     2
    /
   3

输出: [1,3,2]
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
class Solution {
public:
	void inorder_(TreeNode* root, std::vector<int> path)
	{
		if (!root)
		{
			return;
		}
		inorder_(root->left, path);
		path.push_back(root->val);
		inorder_(root->right, path);
	}
    vector<int> inorderTraversal(TreeNode* root) 
    {
    	std::vector<int> path;
    	inorder_(root, path);
    	return path;   
    }
};