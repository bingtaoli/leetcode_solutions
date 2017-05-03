#!/usr/bin/env python
# encoding: utf-8
"""
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
"""

""
class Solution(object):
    """
    本题解法来自九章算法
    http://www.jiuzhang.com/solutions/longest-substring-without-repeating-characters/
    思路：
    遍历字符串，保持下一位的left和上一位的left一致，判断last[ch]是否>=left(等于表示重复了一个ch)，如果是则改变left
    """
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ans = 0
        # left用于记录合法的左边界位置，last用于记录字符上一次出现的位置
        left = 0
        last = {}
        for i in range(len(s)):
            # 子串中出现重复字符，变更left至上一次s[i]出现位置之后，使得子串合法
            if s[i] in last and last[s[i]] >= left:
                left = last[s[i]] + 1
            last[s[i]] = i
            ans = max(ans, i - left + 1)
        return ans

if __name__ == '__main__':
    s = Solution()
    print s.lengthOfLongestSubstring("pwwkew")
    print s.lengthOfLongestSubstring("bbbbb")
    print s.lengthOfLongestSubstring("abcabcbb")
    print s.lengthOfLongestSubstring("abba")