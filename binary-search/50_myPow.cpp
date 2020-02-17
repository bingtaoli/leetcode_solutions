#include <iostream>
using namespace std;

/*
快速幂算法（递归）
如果我们已经知道了x^n的结果，我们如何能知道x^2n的结果呢？使用公式x^2n = (x^n)^2
使用该方法可以降低算法的时间复杂度。
*/

class Solution {
public:
    double myPow1(double x, int n) {
        int i(1);
        double result(1);
        while (i < n)
        {
            result = result * x;
        }
        return result;
    }
    //二分减少计算次数
    double fastPow(double x, int n)
    {
        if (n == 0)
        {
            return 1.0;
        }
        double half = fastPow(x, n/2);
        if (n % 2 == 0)
        {
            return half * half;
        }
        else 
        {
            return half * half * x;
        }
    }
    double myPow(double x, int n) {
        if (x == 0)
        {
            return 0;
        }
        if (n < 0)
        {
            return fastPow(1/x, n);
        }
        return fastPow(x, n);
    }
};