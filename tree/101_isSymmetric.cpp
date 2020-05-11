/*
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
    1
   / \
  2   2
 / \ / \
3  4 4  3
*/

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
    bool isSymmetricNode(TreeNode* left, TreeNode* right)
    {
        if ( !left && !right )
        {
            // both none
            return true;
        }
        else if (!left || !right)
        {
            //one is none
            return false;
        }
        //both has value
        if (left->val != right->val)
        {
            return false;
        }
        return isSymmetricNode(left->left, right->right) && isSymmetricNode(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if (!root)
        {
            return true;
        }
        return isSymmetricNode(root->left, root->right);
    }
};
