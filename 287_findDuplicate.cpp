class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        /*
        走得快和走得慢的人，如果有一样的，迟早会一样
        */
        int len = nums.size();
        int i(0), j(1);
        while ( 1 )
        {
            if (i%len == j%len)
            {
                j = i+1;
            }
            if (nums[i%len] == nums[j%len])
            {
                return nums[i%len];
            }
            i = i + 1;
            j = j + 2;
        }
    }
};
