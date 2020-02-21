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
    void dfs(TreeNode* root, int pathLength)
    {
        if (!root)
        {
            return;
        }
        pathLength++;
        if (!root->left && !root->right)
        {
            //leaf node
            result = pathLength > result ? pathLength : result;
            return;
        }
        dfs(root->left, pathLength);
        dfs(root->right, pathLength);
        pathLength--;
    }
    int maxDepth(TreeNode* root) 
    {
        result = 0;
        int pathLength(0);
        dfs(root, pathLength);
        return result;
    }
private:
    int result;
};
