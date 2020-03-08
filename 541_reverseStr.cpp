#include <iostream>
using namespace std;

class Solution {
public:
    void reverse(string &s, int start, int end)
    {
        //reverse s from start to end
        int left = start;
        int right = end;
        while (left < right)
        {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
        return ;
    }
    string reverseStr(string s, int k) 
    {
        if (!k)
        {
            return s;
        }
        int count = s.size() / (2*k);
        int mod = s.size() % (2*k);
        for (int i = 0; i < count; i++)
        {
            int start = i*2*k;
            int end = i*2*k+k-1;
            reverse(s, start, end);
        }
        if (mod < k)
        {
            reverse(s, count*2*k, s.size()-1);
        }
        else 
        {
            reverse(s, count*2*k, count*2*k+k-1);
        }
        return s;
    }
};
