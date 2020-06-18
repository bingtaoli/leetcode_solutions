/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
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
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool helper(TreeNode *root, long long lower, long long upper)
	{
		if (!root)
		{
			return true;
		}
		if (root->val <= lower || root->val >= upper)
		{
			return false;
		}
		return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
	}
    bool isValidBST(TreeNode* root) 
    {
    	return helper(root, LONG_MIN, LONG_MAX);
    }
};

int main(int argc, char const *argv[])
{
	{
		//[2, 1, 3]
		TreeNode *node1 = new TreeNode(2);
		TreeNode *node2 = new TreeNode(1);
		TreeNode *node3 = new TreeNode(3);
		node1->left = node2;
		node1->right = node3;
		Solution s;
		cout << s.isValidBST(node1) << endl;
	}
	{
		//[10,5,15,null,null,6,20]
		/*
		10
		5 15
		null null 6 20
		*/
		TreeNode *node1 = new TreeNode(10);
		TreeNode *node2 = new TreeNode(5);
		TreeNode *node3 = new TreeNode(15);
		TreeNode *node4 = new TreeNode(6);
		TreeNode *node5 = new TreeNode(20);
		node1->left = node2;
		node1->right = node3;
		node3->left = node4;
		node3->right = node5;
		Solution s;
		cout << s.isValidBST(node1) << endl;
	}
	return 0;
}