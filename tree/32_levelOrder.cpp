#include <iostream>
using namespace std;

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int> > result;
        if (!root)
        {
            return result;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<TreeNode *> vecCurrentNode;
            vector<int> vecCurrentVal;
            while (!q.empty())
            {
                TreeNode *item = q.front();
                q.pop();
                vecCurrentNode.push_back(item);
                vecCurrentVal.push_back(item->val);
            }
            result.push_back(vecCurrentVal);
            for (int i = 0; i < vecCurrentNode.size(); i++)
            {
                if (vecCurrentNode[i]->left)
                {
                    q.push(vecCurrentNode[i]->left);
                }
                if (vecCurrentNode[i]->right)
                {
                    q.push(vecCurrentNode[i]->right);
                }
            }
        }
        return result;
    }
};
