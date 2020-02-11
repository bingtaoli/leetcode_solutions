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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<int> path;
        vector<vector<int> > result;
        vector<string> resultString;
        dfsPath(root, path, result);
        vector<vector<int> >::iterator iter = result.begin();
        for (; iter != result.end(); iter++){
            string currentStringPath;
            vector<int> currentVec = *iter;
            int size = currentVec.size();
            currentStringPath += std::to_string(currentVec[0]);
            for (int i = 1; i < size; i++){
                currentStringPath += "->";
                currentStringPath += to_string(currentVec[i]);
            }
            resultString.push_back(currentStringPath);
        }
        return resultString;
    }
    void dfsPath(TreeNode *root, vector<int> &path, vector<vector<int> > &result){
        if (!root){
            if (path.size() > 0){
                result.push_back(path);
            }
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right){
            result.push_back(path);
            return;
        }
        if (root->left){
            vector<int> pathLeft(path);
            dfsPath(root->left, pathLeft, result);
        }
        if (root->right){
            vector<int> pathRight(path);
            dfsPath(root->right, pathRight, result);
        }
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