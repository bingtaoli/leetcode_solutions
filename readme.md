leetcode solutions :-)

### Serialize and Deserialize BST

encode和decode二叉树，解决方案是从leetcode的discuss中找到的，按照深度优先来把二叉树转成字符。具体可以查看代码。

在写测试程序的时候，注意到reconstruct方法中有`new`，意识到会有内存泄露，所以补上了`destroy_tree`方法。

```cpp
void destroy_tree(TreeNode *node){
    if (node){
        destroy_tree(node->left);
        destroy_tree(node->right);
        delete node;
        node = NULL;
    }
    return;
}
//......
TreeNode *root = c.deserialize(a);
printf("%d\n", root->val);
destroy_tree(root);
return 0;
```

让我想起了在2015年面试阿里的时候，面试官问我`delete`之后需不需要把ptr置为NULL，我没回答上来，后来才百度知道：

> delete一个指针之后，只是回收指针指向位置的空间，而指针本身的值不变（也就是说还是指向那个地址的）。你需要手工将其赋值为NULL。

