#include <iostream>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++)
        {
            hash[nums[i]] = hash[nums[i]] + 1;
        }
        int rank(0);
        int largest(INT_MIN);
        int n = hash.size();
        for (auto iter = hash.begin(); iter != hash.end(); iter++)
        {
            rank++;
            if (rank == n)
            {
                largest = iter->first;
            }
            if (rank == n-2)
            {
                return iter->first;
            }
        }
        return largest;
    }
};
