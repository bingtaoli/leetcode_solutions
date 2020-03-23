class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        //map存储value=>count
        //取value相差1的count之和最大
        map<int, int> g_map;
        int res(0);
        if (nums.size() == 0)
        {
            return res;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            g_map[nums[i]]++;
        }
        map<int, int>::iterator it = g_map.begin();
        int last_value = it->first;
        int last_count = it->second;
        it++;
        for (; it != g_map.end(); it++)
        {
            int diff = it->first - last_value;
            if (diff == 1)
            {
                res = max(res, it->second+last_count);
            }
            last_value = it->first;
            last_count = it->second;
        }
        return res;
    }
};
