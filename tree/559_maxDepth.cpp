#include <iostream>
using namespace std;

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    void dfs(Node *root, int &pathDepth, int &result)
    {
        if (!root)
        {
            if (pathDepth > result)
            {
                result = pathDepth;
            }
            return;
        }
        pathDepth += 1;
        if ( !root->children.size() )
        {
            if (pathDepth > result)
            {
                result = pathDepth;
            }
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            dfs(root->children[i], pathDepth, result);
        }
        pathDepth -= 1;
    }
    int maxDepth(Node* root) 
    {
        int pathDepth = 0;
        int result = 0;
        dfs(root, pathDepth, result);
        return result;
    }
};
