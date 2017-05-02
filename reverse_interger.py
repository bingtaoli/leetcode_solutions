#!/usr/bin/env python
# encoding: utf-8

"""
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
"""


class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        max_int = 2 ** 31 - 1
        reversed_x = 0
        flag = 1
        if x < 0:
        	flag = -1
        	x = -x
        while x > 0:
        	length = len(str(x))
        	reversed_x = reversed_x + (x % 10) * (10 ** (length - 1))
        	x = x / 10
        if reversed_x > max_int:
        	return 0
        return flag * reversed_x


if __name__ == '__main__':
	s = Solution()
	print s.reverse(123)
	print s.reverse(-123)
	print s.reverse(111111111111111111111111111111111111111111111111111111111119)
	print s.reverse(1563847412)