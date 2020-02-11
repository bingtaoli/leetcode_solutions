#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/**
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree: 

   1
 /   \
2     3
 \
  5

All root-to-leaf paths are:

["1->2->5", "1->3"]

*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void binaryTreePaths(vector<string>& result, TreeNode* root, string t) {
        if(!root->left && !root->right) {
            result.push_back(t);
            return;
        }
        if(root->left) binaryTreePaths(result, root->left, t + "->" + to_string(root->left->val));
        if(root->right) binaryTreePaths(result, root->right, t + "->" + to_string(root->right->val));
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(!root) return result;
        
        binaryTreePaths(result, root, to_string(root->val));
        return result;
    }
};

int main(){
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node5(5);
    TreeNode node6(6);
    node1.left = &node2;
    node1.right = &node3;
    node2.right = &node5;
    node2.left = &node6;
    Solution s;
    s.binaryTreePaths(&node1);
    s.binaryTreePaths(NULL);
}