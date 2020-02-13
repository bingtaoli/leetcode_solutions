#include <iostream>
using namespace std;

//https://leetcode-cn.com/problems/divide-two-integers/
/*
给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。

返回被除数 dividend 除以除数 divisor 得到的商。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/divide-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    //解题思路二分法
    int divide(int dividend, int divisor) 
    {
        if (dividend == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            if (dividend > INT_MIN)
            {
                return -dividend;
            }
            else
            {
                return INT_MAX;
            }
        }
        long a = dividend;
        long b = divisor;
        int sig = 0;
        if (  (a<0&&b>0) || (a>0&&b<0)  )
        {
            sig = 1;
        }
        a = a>0 ? a : -a;
        b = b>0 ? b : -b;
        long result = div(a,b);
        if (sig)
        {
            return -result;
        }
        else
        {
            if (result>INT_MAX)
            {
                return INT_MAX;
            }
            else
            {
                return result;
            }
        }
        return result;
    }
    long div(long dividend, long divisor)
    {
        if (dividend < divisor)
        {
            return 0;
        }
        long result(0);
        long testNum = divisor;
        if (testNum <= dividend)
        {
            result = 1;
        }
        while ( (testNum + testNum) <= dividend )
        {
            result = result + result;
            testNum = testNum + testNum;
        }
        return result + div(dividend-testNum, divisor);
    }
};