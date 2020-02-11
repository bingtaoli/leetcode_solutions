
//https://leetcode-cn.com/problems/balanced-binary-tree/

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
	int height(TreeNode *root)
	{
		if (!root)
		{
			return -1;
		}
		//节点的高度
		return 1 + max( height(root->left), height(root->right) );
	}
    bool isBalanced(TreeNode* root) 
    {
        if (!root)
        {
        	return true;
        }
        //自己的子节点高度差<2，并且子节点也满足
        return abs( height(root->left) - height(root->right) ) < 2 
        	   && isBalanced(root->left) && isBalanced(root->right);
    }
};