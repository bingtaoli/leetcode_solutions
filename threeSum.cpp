#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > results;
        if (nums.size() < 3)
        {
            return results;
        }
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                continue;
            }
            if (i>=1 and nums[i] == nums[i-1])
            {
                //防止重复
                continue;
            }
            int start = i+1;
            int end = nums.size()-1;
            while (start < end)
            {
                int s = nums[i] + nums[start] + nums[end];
                if (s == 0)
                {
                    vector<int> item;
                    item.push_back(nums[i]);
                    item.push_back(nums[start]);
                    item.push_back(nums[end]);
                    results.push_back(item);
                    while (start < len-1 && nums[start] == nums[start+1])
                    {
                        start++;
                    }
                    start++;
                    while (end>=1 && nums[end] == nums[end-1])
                    {
                        end--;
                    }
                    end--;
                }
                else if (s>0)
                {
                    end--;
                }
                else 
                {
                    start++;
                }
            }
        }
        return results;
    }
};

int main()
{
	std::vector<int> test;
	test.push_back(0);
	test.push_back(0);
	test.push_back(0);
	Solution s;
	s.threeSum(test);

	return 0;
}