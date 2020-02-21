#include <iostream>
using namespace std;

/*
8 的平方根是 2.82842..., 
由于返回类型是整数，小数部分将被舍去。

这个指定了二分返回的边界，如果说8的平方根是3，那么就不会返回right，而是返回left了。
*/

class Solution {
public:
    int mySqrt(int x) 
    {
        if (x == 0)
        {
            return 0;
        }
        if (x <= 2)
        {
            return 1;
        }
        int left = 1; 
        int right = x/2;
        while (left <= right)
        {
            double middle = left + (right-left)/2;
            double tmp = middle * middle;
            if (tmp ==  x)
            {
                return middle;
            }
            else if (tmp < x)
            {
                left = middle+1;
            }
            else if (tmp > x)
            {
                right = middle-1;
            }
        }
        return right;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	cout << s.mySqrt(4) << endl;
	cout << s.mySqrt(8) << endl;
	cout << s.mySqrt(9) << endl;
	return 0;
}