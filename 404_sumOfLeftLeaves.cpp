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
    void dfs(TreeNode *root, bool isLeft, int &res)
    {
        if (!root)
        {
            return;
        }
        if (isLeft && !root->left && !root->right)
        {
            //left leaf node
            res += root->val;
        }
        dfs(root->left, true, res);
        dfs(root->right, false, res);
    }
    int sumOfLeftLeaves(TreeNode* root) 
    {
        int res(0);
        dfs(root, false, res);
        return res;
    }
};
