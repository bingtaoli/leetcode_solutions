#include <iostream>
using namespace std;

/*
有点类似消消乐的游戏，最后两个消掉变成一个，然后循环消除知道nums<10。
比如"038"这个数字，3和8相加得到11，所以新的数字各位是1，再进一位，就成了"11"
比如"299"，9和9得到18，新的数字个位是8，再进一位，就是"38"，继续得到"11"，得到"2"
*/

class Solution {
public:
    int addDigits(int num) 
    {
        /*
        从个位开始不断进位，直到没有进位为止
        */
        int carry(0);
        while (num >= 10 || carry)
        {
            int a = num % 10; 
            int b = num / 10 % 10 + carry;  //carry是进位
            int s = a + b;
            if (s >= 10)
            {
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            num = num / 10 / 10 * 10 + s % 10;  //两位变一位
            cout << num << endl;
        }
        return num;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    int a = 38;
    int b = 199;
    int c = 10;
    Solution s;
    //cout <<s.addDigits(a) << endl;
    cout <<s.addDigits(b) << endl;
    cout <<s.addDigits(c) << endl;
    return 0;
}