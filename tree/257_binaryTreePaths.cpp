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
    void dfs(TreeNode *root, string &path, vector<string> &result)
    {
        if (!root)
        {
            return ;
        }
        string original = path;
        stringstream ssTemp;  
        ssTemp << root->val;
        if (path.empty())
        {
            path = ssTemp.str();
        }
        else
        {
            path += "->" + ssTemp.str();
        }
        if (!root->left && !root->right)
        {
            result.push_back(path);
        }
        dfs(root->left, path, result);
        dfs(root->right, path, result);
        path = original;
    }
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> result;
        if (!root)
        {
            return result;
        }
        string path;
        dfs(root, path, result);
        return result;
    }
};
