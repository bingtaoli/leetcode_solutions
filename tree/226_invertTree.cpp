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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (!root)
        {
            return root;
        }
        TreeNode *tmpLeft = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(tmpLeft);
        return root;
    }
};
