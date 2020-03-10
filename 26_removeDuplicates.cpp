#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        if (!nums.size())
        {
            return 0;
        }
        if (nums.size() == 1)
        {
            return 1;
        }
        int lastNum = nums[0];
        auto iter = nums.begin();
        iter++;
        for ( ; iter != nums.end(); iter++)
        {
            while ( iter != nums.end() && *iter == lastNum )
            {
                iter = nums.erase(iter);
            }
            if (iter != nums.end())
            {
                lastNum = *iter;
            }
            else 
            {
                /*
                如果不在for循环里加上最后的判断会导致错误，原因在于，
                当iter已经是end时，如果不break，就会继续for循环的最后一步iter++，
                这样会越界，而且iter=nums.end()++了。
                */
                break; 
            }
        }
        return nums.size();
    }
};
