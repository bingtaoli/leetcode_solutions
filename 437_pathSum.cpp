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
    void dfs(TreeNode *root, int &pathSum, const int sum)
    {
        if (!root)
        {
            return;
        }
        pathSum += root->val;
        if (pathSum == sum)
        {
            totolCount++;
        }
        dfs(root->left, pathSum, sum);
        dfs(root->right, pathSum, sum);
        pathSum -= root->val;
    }
    int pathSum(TreeNode* root, int sum) 
    {
        if (!root)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode* item = q.front();
            q.pop();
            int pathSum = 0;
            dfs(item, pathSum, sum);
            if (item->left)
            {
                q.push(item->left);
            }
            if (item->right)
            {
                q.push(item->right);
            }
        }
        return totolCount;
    }
private:
    int totolCount;
};
