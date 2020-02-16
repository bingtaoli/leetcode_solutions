#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

/*
执行用时 :8 ms, 在所有 C++ 提交中击败了91.54%的用户
内存消耗 :8.7 MB, 在所有 C++ 提交中击败了89.90%的用户
*/

class Solution {
public:
    static int getIntBit(int a)
    {
        int size(0);
        while (a)
        {
            a = a/10;
            size++;
        }
        return size;
    }
    static bool compare(int a, int b)
    {
        int aSize = getIntBit(a);
        int bSize = getIntBit(b);
        long sum1 = a;
        long sum2 = b;
        while (bSize)
        {
            sum1 = sum1 * 10;
            bSize--;
        }
        while (aSize)
        {
            sum2 = sum2 * 10;
            aSize--;
        }
        sum1 += b;
        sum2 += a;
        return sum1 > sum2; //降序排列
    }
    string largestNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end(), compare);
        string result;
        for (int i = 0; i < nums.size(); i++)
        {
        	std::stringstream ssTemp; 
        	ssTemp << nums[i];
        	result += ssTemp.str();
        }
        if (result.at(0) == '0')
        {
            return "0";
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> test;
	test.push_back(0);
	test.push_back(0);
	Solution s;
	string result = s.largestNumber(test);
	cout << result << endl;
	return 0;
}
