#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
	"""
	steal from http://www.jiuzhang.com/solutions/3sum/#python
	题意：求数列中三个数之和为0的三元组有多少个，需去重
    暴力枚举三个数复杂度为O(N^3)
    先考虑2Sum的做法，假设升序数列a，对于一组解ai,aj, 另一组解ak,al 
    必然满足 i<k j>l 或 i>k j<l, 因此我们可以用两个指针，初始时指向数列两端
    指向数之和大于目标值时，右指针向左移使得总和减小，反之左指针向右移
    由此可以用O(N)的复杂度解决2Sum问题，3Sum则枚举第一个数O(N^2)
    使用有序数列的好处是，在枚举和移动指针时值相等的数可以跳过，省去去重部分
	"""
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        res = []
        length = len(nums)
        for i in range(0, length - 2):
            if i and nums[i] == nums[i - 1]:
                continue
            target = nums[i] * -1
            left, right = i + 1, length - 1
            while left < right:
                if nums[left] + nums[right] == target:
                    res.append([nums[i], nums[left], nums[right]])
                    right -= 1
                    left += 1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:
                        right -= 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left += 1
        return res

if __name__ == '__main__':
	s = Solution()
	r = s.threeSum([-1, 0, 1, 2, -1, -4])
	print r
	print s.threeSum([-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6])