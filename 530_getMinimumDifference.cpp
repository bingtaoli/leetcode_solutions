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
    void innerOrder(TreeNode *root, vector<int> &res)
    {
        //二叉树的中序遍历是升序
        if (!root)
        {
            return;
        }
        innerOrder(root->left, res);
        res.push_back(root->val);
        innerOrder(root->right, res);
    }
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> res;
        innerOrder(root, res);
        //get min diff
        int diff = INT_MAX;
        for (int i = 1; i < res.size(); i++)
        {
            int tmp = res[i] - res[i-1];
            diff = min(tmp, diff);
        }
        return diff;
    }
};
