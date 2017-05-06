#include <string.h>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void destroy_tree(TreeNode *node){
    if (node){
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
        node = NULL;
    }
    return;
}
 
/**
算法解析：
使用BST即深度优先算法把二叉树encode为string，decode也使用BST构建，很有创新性
*/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string order;
        inorderDFS(root, order);
        return order;
    }
    
    inline void inorderDFS(TreeNode* root, string& order) {
        if (!root) return;
        char buf[4];
        memcpy(buf, &(root->val), sizeof(int)); //burn the int into 4 chars
        for (int i=0; i<4; i++) order.push_back(buf[i]);
        inorderDFS(root->left, order);
        inorderDFS(root->right, order);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        return reconstruct(data, pos, INT_MIN, INT_MAX);
    }
    
    inline TreeNode* reconstruct(const string& buffer, int& pos, int minValue, int maxValue) {
        if (pos >= buffer.size()) return NULL; //using pos to check whether buffer ends is better than using char* directly.
        
        int value;
        memcpy(&value, &buffer[pos], sizeof(int));
        if (value < minValue || value > maxValue) return NULL;
        
        TreeNode* node = new TreeNode(value);
        pos += sizeof(int);
        node->left = reconstruct(buffer, pos, minValue, value);
        node->right = reconstruct(buffer, pos, value, maxValue);
        return node;
    }
};

int main(){
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);
    TreeNode node7(7);
    node1.left = &node2;
    node1.right = &node5;
    node2.left = &node3;
    node2.right = &node4;
    node5.left = &node6;
    node5.right = &node7;
    Codec c;
    string a = c.serialize(&node1);
    TreeNode *root = c.deserialize(a);
    printf("%d\n", root->val);
    destroy_tree(root);
    return 0;
}
