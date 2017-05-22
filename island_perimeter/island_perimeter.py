#!/usr/bin/env python
# encoding: utf-8


"""
You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected 
horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected 
land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side 
length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
"""

class Solution(object):

    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid:
            return 0

        def sum_adjacent(i, j):
            adjacent = (i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1),
            res = 0
            for x, y in adjacent:
                if x < 0 or y < 0 or x == len(grid) or y == len(grid[0]) or grid[x][y] == 0:
                    res += 1
            return res

        perimeter = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == 1:
                    perimeter += sum_adjacent(i, j)
        return perimeter
