#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int left = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int middle = (left+right)/2;
            int value = nums[middle];
            if ( value == target )
            {
                return middle;
            }
            else if ( value < target )
            {
                left = middle + 1;
            }
            else 
            {
                right = right - 1;
            }
        }
        return left;
    }
};
