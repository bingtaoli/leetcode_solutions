#!/usr/bin/env python
# encoding: utf-8

'''
Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1


Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so fuck off.
'''


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        if root is None:
            return
        tmp = root.left
        root.left = root.right
        root.right = tmp
        self.invertTree(root.left)
        self.invertTree(root.right)
        return root

if __name__ == '__main__':
    node1 = TreeNode(1)
    node2 = TreeNode(2)
    node3 = TreeNode(3)
    node4 = TreeNode(4)
    node5 = TreeNode(5)
    node6 = TreeNode(6)
    node7 = TreeNode(7)
    node8 = TreeNode(8)
    node9 = TreeNode(9)
    '''

         4
       /   \
      2     7
     / \   / \
    1   3 6   9
    '''
    node4.left = node2
    node4.right = node7
    node2.left = node1
    node2.right = node3
    node7.left = node6
    node7.right = node9
    s = Solution()
    new_root = s.invertTree(node4)
    '''
         4
       /   \
      7     2
     / \   / \
    9   6 3   1
    '''
    assert new_root.left is not None
    assert new_root.left.val == 7
    assert new_root.right.val == 2
    assert new_root.left.left is not None
    assert new_root.left.left.val == 9
    assert new_root.left.right is not None
    assert new_root.left.right.val == 6

