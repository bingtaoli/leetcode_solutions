#!/usr/bin/env python
# encoding: utf-8

"""
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example:
Given a = 1 and b = 2, return 3.
"""


'''
解法：
方法来自: http://wiki.jikexueyuan.com/project/for-offer/question-forty-seven.html
5 的二进制是 101，17 的二进制是 10001 。还是试着把计算分成三步：
第一步各位相加但不计进位， 得到的结果是 10100（ 最后一位两个数都是1,相加的结果是二进制的 10 。这一步不计进位， 因此结果仍然是 0 )。
第二步记下进位。在这个例子中只在最后一位相加时产生一个进位，结果是二进制的 10。 
第三步把前两步的结果相加，得到的结果是 10110 ， 转换成十进制正好是 22。由此可见三步走的策略对二进制也是适用的。

接下来我们试着把二进制的加法用位运算来替代。
第一步不考虑进位对每一位相加。0 加 0 、1 加 1 的结果都 0。 0 加 1 、1 加 0 的结果都是 1 。
我们注意到，这和异或的结果是一样的。对异或而言， 0 和 0、1 和 1 异或的结果是 0， 而 0 和 1 、1 和 0 的异或结果是 1 。
接着考虑第二步进位，对加 0 、0 加 1 、1 加 0 而言， 都不会产生进位，只有 1 加 1 时，会向前产生一个进位。
此时我们可以想象成是两个数先做位与运算，然后再向左移动一位。只有两个数都是 1 的时候，位与得到的结果是 1，其余都是 0。
第三步把前两个步骤的结果相加。第三步相加的过程依然是重复前面两步， 直到不产生进位为止。
'''

class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        x = a
        y = b
        result = 0
        carry = 0
        while True:
            result = x ^ y
            carry = (x & y) << 1
            x = result
            y = carry
            if y == 0:
                break
        return result


if __name__ == '__main__':
    s = Solution()
    print s.getSum(17, 5)
    print s.getSum(18, 12)
    