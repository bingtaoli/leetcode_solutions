
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
    	if (nums.size() == 1)
    	{
    		return nums[0];
    	}
        std::sort(nums.begin(), nums.end());
        int count = 1;
        int n = nums.size()
        for (int i = 1; i < n; i++)
        {
        	if (nums[i] == nums[i-1])
        	{
        		count++;
        	}
        	else
        	{
        		if ( i == n-1 )
        		{
        			//last single
        			return nums[i];
        		}
        		else if (count == 1)
        		{
        			//not last single
        			return nums[i-1];
        		}
        		else
        		{
        			count = 1;
        		}
        	}
        }
        return 0;
    }
};

int main(int argc, char const *argv[])
{
	{
		//[2,2,1]
		std::vector<int> v;
		v.push_back(2);
		v.push_back(2);
		v.push_back(1);
		Solution s;
		int a = s.singleNumber(v);
		cout << a << endl;
	}
	return 0;
}