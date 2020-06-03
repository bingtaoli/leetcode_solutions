/*
给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素最多出现两次，返回移除后数组的新长度。

不要使用额外的数组空间，你必须在原地修改输入数组并在使用 O(1) 额外空间的条件下完成。

示例 1:

给定 nums = [1,1,1,2,2,3],

函数应返回新长度 length = 5, 并且原数组的前五个元素被修改为 1, 1, 2, 2, 3 。

你不需要考虑数组中超出新长度后面的元素。
示例 2:

给定 nums = [0,0,1,1,1,1,2,3,3],

函数应返回新长度 length = 7, 并且原数组的前五个元素被修改为 0, 0, 1, 1, 2, 3, 3 。

你不需要考虑数组中超出新长度后面的元素。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    	//sort
    	if (nums.size() == 0)
    	{
    		return 0;
    	}
    	std::sort(nums.begin(), nums.end());
    	std::vector<int>::iterator it = nums.begin();
    	it++;
    	int last = nums[0];
    	int count = 1;
    	int del_count = 0;
    	while (it != nums.end())
    	{
    		if (*it == last)
    		{
    			count++;
    		}
    		else
    		{
    			//update last
    			last = *it;
    			count = 1;
    		}
    		if (count > 2)
    		{
    			//erase
    			del_count++;
    			it = nums.erase(it);
    		}
    		else
    		{
    			it++;
    		}
    	}
    	return nums.size();
    }
};

int main(int argc, char const *argv[])
{
	{
		//[0,0,1,1,1,1,2,3,3],
		std::vector<int> v;
		v.push_back(0);
		v.push_back(0);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(3);
		Solution s;
		s.removeDuplicates(v);
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
	return 0;
	return 0;
}