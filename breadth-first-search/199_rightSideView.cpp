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
    struct NodeWithDepth
    {
        TreeNode *node;
        int depth;
        NodeWithDepth(TreeNode *n, int d):node(n),depth(d){};
    };
    //breadth-first-search
    void bfs(TreeNode *root)
    {
        NodeWithDepth *a = new NodeWithDepth(root, 1);
        q.push(a);
        path.push_back(a);
        while (!q.empty())
        {
            NodeWithDepth *item = q.front();
            q.pop();
            int currentDepth = item->depth;
            if (item->node->left)
            {
                NodeWithDepth *child = new NodeWithDepth(
                    item->node->left, currentDepth+1);
                q.push(child);
                path.push_back(child);
            }
            if (item->node->right)
            {
                NodeWithDepth *child = new NodeWithDepth(
                    item->node->right, currentDepth+1);
                q.push(child);
                path.push_back(child);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root)
        {
            return result;
        }
        bfs(root);
        if (path.size() == 1)
        {
            result.push_back(path[0]->node->val);
            return result;
        }
        NodeWithDepth *prev = path[0];
        NodeWithDepth *cur = NULL;
        auto iter = path.begin();
        iter++;
        while ( iter != path.end() )
        {
            cur = *iter;
            if (cur->depth > prev->depth)
            {
                //new level, add prev
                result.push_back(prev->node->val);
            }
            prev = cur;
            iter++;
            //add last node
            if (iter == path.end())
            {
                //cur is the last node
                result.push_back(cur->node->val);
            }
        }
        return result;
    }
private:
    queue<NodeWithDepth *> q;
    vector<NodeWithDepth *> path;
};