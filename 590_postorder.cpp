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
    void do_postorder(Node *root, vector<int> &res)
    {
        if (!root)
        {
            return;
        }
        for (int i = 0; i < root->children.size(); i++)
        {
            do_postorder(root->children[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) 
    {
        //left right middle
        vector<int> res;
        do_postorder(root, res);
        return res;
    }
};
