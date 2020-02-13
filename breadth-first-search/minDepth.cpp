#include <iostream>
using namespace std;

//https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/

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
        int depeth;  //方便记录每层深度
    };
    int minDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        queue<NodeWithDepth> q; //队列实现广度优先搜索
        NodeWithDepth item;
        item.node = root;
        item.depeth = 1;
        q.push(item);
        TreeNode *point;
        int result(0);
        while ( !q.empty() )
        {
            NodeWithDepth temp = q.front();
            q.pop();
            result = temp.depeth;
            point = temp.node;
            if (!point->left && !point->right)
            {
                break;
            }
            if (point->left)
            {
                NodeWithDepth item;
                item.node = point->left;
                item.depeth = temp.depeth+1;
                q.push(item);
            }
            if (point->right)
            {
                NodeWithDepth item;
                item.node = point->right;
                item.depeth = temp.depeth+1;
                q.push(item);
            }
        }
        return result;
    }
};
