/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。

示例:

输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) 
    {
    	//广度优先遍历，记录每一层的最后一个节点
    	//使用队列，先进先出
    	std::vector<int> view;
    	if (!root)
    	{
    		return view;
    	}
    	std::queue<TreeNode *> q;
    	q.push(root);
    	while ( !q.empty() )
    	{
    		int size = q.size();
    		for (int i = 0; i < size; i++)
    		{
    			TreeNode *item = q.front();
    			q.pop();
    			if (item->left)
    			{
    				q.push(item->left);
    			}
    			if (item->right)
    			{
    				q.push(item->right);
    			}
    			if (i == size-1)
    			{
    				//last node of current level
    				view.push_back(item->val);
    			}
    		}
    	}
    	return view;
    }
};