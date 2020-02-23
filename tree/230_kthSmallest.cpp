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
    void inorder(TreeNode *root, vector<int> &path)
    {
        //中序遍历
        if (!root)
        {
            return;
        }
        inorder(root->left, path);
        path.push_back(root->val);
        inorder(root->right, path);
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> path;
        if (!root)
        {
            return 0;
        }
        inorder(root, path);
        return path[k-1];
    }
};
