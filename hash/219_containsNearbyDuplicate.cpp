#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0)
        {
            return false;
        }
        unordered_map<int,int> num_to_index;
        for (int i=0; i < nums.size(); i++)
        {
            int value = nums[i];
            if ( num_to_index.find(value) != num_to_index.end() )
            {
                if (i - num_to_index[value] <= k)
                {
                    return true;
                }
            }
            num_to_index[value] = i;
        }
        return false;
    }
};