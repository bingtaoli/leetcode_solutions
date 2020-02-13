#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
	//超时版本
    vector<int> searchRangeTimeout(vector<int>& nums, int target) {
    	int len = nums.size();
    	std::vector<int> not_find;
    	std::vector<int> result;
    	not_find.push_back(-1);
    	not_find.push_back(-1);
    	if (len == 0)
    	{
    		return not_find;
    	}
        if (nums[0] > target || nums[len-1] < target)
        {
        	return not_find;
        }
        //二分查找，找到一个之后再左右查找就行
        int left = 0;
        int right = len-1;
        int find_index = -1;
        while ( left <= right )
        {
        	if ( left == right )
        	{
        		if (nums[left] == target)
        		{
        			find_index = left;
        			break;
        		}
        		else
        		{
        			break;
        		}
        	}
        	int middle = (left + right)/2;
        	if (nums[middle] == target)
        	{
        		find_index = middle;
        		break;
        	}
        	else if (nums[middle] > target)
        	{
        		right = middle;
        	}
        	else 
        	{
        		left = middle;
        	}
        }
        if (find_index != -1)
        {
        	int i = find_index;
        	while ( i>=1 && nums[i-1] == nums[i])
        	{
        		i--;
        	}
        	result.push_back(i);
        	int  j = find_index;
        	while ( j<len-1 && nums[j] == nums[j+1])
        	{
        		j++;
        	}
        	result.push_back(j);
        }
        return result;
    }

    int searchLeft(vector<int>& nums, int target)
    {
    	//查找左侧位置
    	int len = nums.size();
        int left = 0;
        int right = len-1;
        int find_index = -1;
        while ( left <= right )
        {
        	if (left == right)
        	{
        		if (nums[left] == target)
        		{
        			find_index = left;
        			break;
        		}
        		else
        		{
        			break;
        		}
        	}
        	int middle = (left + right)/2;
        	if (nums[middle] == target)
        	{
        		find_index = middle;
        		right = middle-1;
        	}
        	else if (nums[middle] > target)
        	{
        		right = middle-1;
        	}
        	else 
        	{
        		left = middle+1;
        	}
        	printf("left:%d middle:%d\n", left, right);
        }
        return find_index;
    }

    int searchRight(vector<int>& nums, int target)
    {
    	//查找左侧位置
    	int len = nums.size();
        int left = 0;
        int right = len-1;
        int find_index = -1;
        while ( left <= right )
        {
        	if (left == right)
        	{
        		if (nums[left] == target)
        		{
        			find_index = left;
        			break;
        		}
        		else
        		{
        			break;
        		}
        	}
        	int middle = (left + right)/2;
        	if (nums[middle] == target)
        	{
        		find_index = middle;
        		left = middle+1;
        	}
        	else if (nums[middle] > target)
        	{
        		right = middle-1;
        	}
        	else 
        	{
        		left = middle+1;
        	}
        	printf("left:%d middle:%d\n", left, right);
        }
        return find_index;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
    	int len = nums.size();
    	std::vector<int> not_find;
    	std::vector<int> result;
    	not_find.push_back(-1);
    	not_find.push_back(-1);
    	if (len == 0)
    	{
    		return not_find;
    	}
        if (nums[0] > target || nums[len-1] < target)
        {
        	return not_find;
        }
        //二分查找，找到一个之后再左右查找就行
        int left = searchLeft(nums, target);
        cout << "left:" <<  left << endl;
        int right = searchRight(nums, target);
        cout << "right:" <<  right << endl;
        result.push_back(left);
        result.push_back(right); 
        return result;
    }
};

int main()
{
	std::vector<int> test;
	test.push_back(5);
	test.push_back(7);
	test.push_back(7);
	test.push_back(8);
	test.push_back(8);
	test.push_back(10);
	Solution s;
	vector<int> result = s.searchRange(test, 8);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "  ";
	}
	cout << endl;
	return 0;
}