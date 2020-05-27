/*
给定一个二叉树，返回它的 前序 遍历。

 示例:

输入: [1,null,2,3]  
   1
    \
     2
    /
   3 

输出: [1,2,3]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
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

//进阶: 递归算法很简单，你可以通过迭代算法完成吗？


class Solution {
public:
	//前序遍历DLR 也叫做先根遍历、先序遍历、前序周游，可记做根左右
	//首先访问根结点然后遍历左子树，最后遍历右子树。

	void preorder_(TreeNode* root, std::vector<int> &path)
	{
		if (!root)
		{
			return;
		}
		path.push_back(root->val);
		preorder_(root->left, path);
		preorder_(root->right, path);
	}

    vector<int> preorderTraversal(TreeNode* root) 
    {
    	std::vector<int> path;
    	preorder_(root, path);
    	return path;
    }
};

