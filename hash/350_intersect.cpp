#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int , int> hash_map1;
        unordered_map<int , int> hash_map2;
        vector<int> result;
        for (int i=0; i<nums1.size(); i++)
        {
            hash_map1[nums1[i]] = hash_map1[nums1[i]] + 1;
        }
        for (int i = 0; i < nums2.size(); i++)
        {
             hash_map2[nums2[i]] = hash_map2[nums2[i]] + 1;
        }
        //intersect
        for (auto it = hash_map1.begin(); it != hash_map2.end(); it++)
        {
            int a = it->second;
            if (hash_map2.find(it->first) != hash_map2.end())
            {
                a = a < hash_map2[it->first] ? a : hash_map2[it->first];
                while (a > 0)
                {
                    result.push_back(it->first);
                    a--;
                }
            }
        }
        return result;
    }
};
