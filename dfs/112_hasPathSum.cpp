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
    void dfs(TreeNode* root, int &sum)
    {
        if (!root)
        {
            return;
        }
        sum += root->val;
        if (!root->left && !root->right)
        {
            vecSum.push_back(sum);
        }
        else
        {
            dfs(root->left, sum);
            dfs(root->right, sum);
        }
        sum -= root->val;
        return;
    }
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
        {
            return false;
        }
        int pathSum(0);
        dfs(root, pathSum);
        for (auto iter = vecSum.begin(); iter != vecSum.end(); iter++)
        {
            if (*iter == sum)
            {
                return true;
            }
        }
        return false;
    }
private:
    vector<int> vecSum;
};
