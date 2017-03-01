#!/usr/bin/env python
# encoding: utf-8


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        sorted_nums = []
        sorted_nums += nums
        sorted_nums.sort()
        i = 0
        j = len(sorted_nums) - 1
        while j > i:
        	if sorted_nums[i] + sorted_nums[j] > target:
        		j -= 1
        	elif  sorted_nums[i] + sorted_nums[j] < target:
        		i += 1
        	else:
        		break
        a = sorted_nums[i]
        b = sorted_nums[j]
        index_1 = 0
        index_2 = 0
        index_1 = nums.index(a)
        for i in range(len(nums)):
        	if nums[i] == b and i != index_1:
        		index_2 = i
        return [index_1, index_2]

if __name__ == '__main__'
	s = Solution()
	r = s.twoSum([3,2,4], 6)
	print r
	r = s.twoSum([3,3], 6)
	print r