#include <iostream>
using namespace std;

/*
 * 更倾向于用set去重，之后用vector输出
 * 觉得官方的答案有点问题，如果nums[i]==num[i-1]就i++移动的话，可能会错过0+0+0+0=0的答案
 * 所以还是set比较好
 * */

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        set<vector<int>> s_result;
        vector<vector<int>> v_result;
        int len = nums.size();
        if (len < 4)
        {
            return v_result;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len-3; i++)
        {
            int j(len-1);
            while (i <= j-3)
            {
                int m = i+1;
                int n = j-1;
                while (m < n)
                {
                    int total = nums[i] + nums[j] + nums[m] + nums[n];
                    if (total == target)
                    {
                        vector<int> item;
                        item.push_back(nums[i]);
                        item.push_back(nums[j]);
                        item.push_back(nums[m]);
                        item.push_back(nums[n]);
                        s_result.insert(item);
                        m++;
                        n--;
                    }
                    else if (total < target)
                    {
                        m++;
                    }
                    else 
                    {
                        n--;
                    }
                }
                j--;
            }
        }
        //去重
        for (auto iter = s_result.begin(); iter != s_result.end(); iter++)
        {
            v_result.push_back(*iter);
        }
        return v_result;
    }
};
