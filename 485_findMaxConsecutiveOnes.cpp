#include <iostream>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int result(0);
        for (int i = 0; i < nums.size();)
        {
            int length(0);
            while (i < nums.size() && nums[i] == 1)
            {
                length++;
                i++;
            }
            result = length > result ? length : result;
            i++;
        }
        return result;
    }
};
