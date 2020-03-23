#include <iostream>
using namespace std;


struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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
    void dfs(TreeNode *root, vector<int> &path, const int sum)
    {
        if (!root)
        {
            return;
        }
        path.push_back(root->val);
        if (!root->left && !root->right)
        {
            //该节点为叶子节点，计算是否满足sum
            if (path.size() >= 1)
            {
                //必须size>1，保证是根到叶
                //计算sum
                int total(0);
                for (int i = 0; i < path.size(); i++)
                {
                    total += path[i];
                }
                if (total == sum)
                {
                    results.push_back(path);
                }
            }
        }
        else 
        {
            dfs(root->left, path, sum);
            dfs(root->right, path, sum);
        }
        path.pop_back();
        return;
    }
    vector<vector<int> > pathSum(TreeNode* root, int sum) 
    {
        vector<vector<int> > vecResults;
        if (!root)
        {
            return vecResults;
        }
        vector<int> path;
        dfs(root, path, sum);
        for (auto iter = results.begin(); iter != results.end(); iter++)
        {
            vecResults.push_back(*iter);
        }
        return vecResults;
    }
private:
    vector<vector<int> > results;
};

itn main(int argc, char const *argv[])
{
	/* code */
	
	return 0;
}