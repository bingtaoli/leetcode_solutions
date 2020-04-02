class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            int middle = (left+right)/2;
            int tmp = nums[middle];
            if (tmp == target)
            {
                return middle;
            }
            else if (tmp > target)
            {
                right = middle-1;
            }
            else
            {
                left = middle+1;
            }
        }
        return left;
    }
};
