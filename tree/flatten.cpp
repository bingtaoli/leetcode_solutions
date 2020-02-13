#include <iostream>
using namespace std;

//https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/submissions/
/*
解题方法，非常简单粗暴地用深度优先遍历把节点放到vector里，然后再串成一个链表。居然耗时超过了95.48%的用户.

执行用时 :
4 ms
, 在所有 C++ 提交中击败了
95.48%
的用户
内存消耗 :
10.4 MB
, 在所有 C++ 提交中击败了
5.05%
的用户
*/

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
    void visit(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        vecNode.push_back(root);
        visit(root->left);
        visit(root->right);
    }
    void flatten(TreeNode* root) {
        //深度优先遍历
        visit(root);
        for (vector<TreeNode *>::iterator it = vecNode.begin(); it != vecNode.end(); )
        {
            TreeNode *current = (*it);
            it++;
            if (it != vecNode.end())
            {
                TreeNode *next = (*it);
                current->left = NULL;
                current->right = next;
            }
            else
            {
                current->right = NULL;
            }
        }
    }
private:
    vector<TreeNode *> vecNode;
};