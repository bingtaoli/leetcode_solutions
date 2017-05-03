#!/usr/bin/env python
# encoding: utf-8

"""
https://leetcode.com/problems/longest-palindromic-substring/#/description
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example:
Input: "cbbd"
Output: "bb"

"""


"""
from https://discuss.leetcode.com/topic/20844/python-easy-to-understand-solution-with-comments-from-middle-to-two-ends
这个解法比较简单粗暴，顺序遍历，考虑奇数和偶数的情况
"""
class Solution(object):
    def longestPalindrome(self, s):
        res = ""
        for i in xrange(len(s)):
            # odd case, like "aba"
            tmp = self.helper(s, i, i)
            if len(tmp) > len(res):
                res = tmp
            # even case, like "abba"
            tmp = self.helper(s, i, i+1)
            if len(tmp) > len(res):
                res = tmp
        return res
     
    # get the longest palindrome, l, r are the middle indexes   
    # from inner to outer
    def helper(self, s, l, r):
        while l >= 0 and r < len(s) and s[l] == s[r]:
            l -= 1; r += 1
        return s[l+1:r]