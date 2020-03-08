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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (!root)
        {
            return 0;
        }
        ans = 0;
        height(root);
        return ans;
    }
    //height means max length of path from root to leaf, if root has no child node, height=0
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        if (!root->left && !root->right)
        {
            return 0;
        }
        int L = height(root->left);
        int R = height(root->right);
        //while recursive, get ans
        if (root->left && root->right)
        {
            ans = max(ans, L+R+2);
        }
        if (root->left)
        {
            ans = max(ans, L+1);
        }
        if (root->right)
        {
            ans = max(ans, R+1);
        }
        return max(L, R) + 1;  //because root has at least one child node, so plus 1
    }

private:
    int ans;
};
