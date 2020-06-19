/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) 
    {
    	//广度优先搜索，每一层遍历
    	vector<vector<int> > res;
    	if (!root)
    	{
    		return res;
    	}
    	queue<TreeNode*> q;
    	q.push(root);
    	int direction = 1;  //left->right
    	while ( !q.empty() )
    	{
    		std::vector<TreeNode *> nextLevel;
    		std::vector<int> curLevel;
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
    		//add curLevel
    		if (curLevel.size())
    		{
    			if (direction == 1)
    			{
    				res.push_back(curLevel);
    			}
    			else
    			{
    				std::vector<int> reverse;
    				int n = curLevel.size();
    				for (int i = 0; i < n; i++)
    				{
    					reverse.push_back(curLevel[n-i-1]);
    				}
    				res.push_back(reverse);
    			}
    		}
    		//add nextLevel to q
    		for (int i = 0; i < nextLevel.size(); i++)
    		{
    			q.push(nextLevel[i]);
    		}
    		direction = direction * -1;
    	}
    	return res;
    }
};

int main(int argc, char const *argv[])
{
	/*
		3
	   / \
	  9  20
	    /  \
	   15   7
	输出:
	[
	  [3],
	  [20,9],
	  [15,7]
	]
	*/
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
		vector<vector<int> > res = s.zigzagLevelOrder(node1);
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