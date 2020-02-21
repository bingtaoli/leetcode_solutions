#include <iostream>
using namespace std;

/*
时间：在所有 C++ 提交中击败了10.77%的用户
内存: 在所有 C++ 提交中击败了5.21%的用户
*/

class Solution {
public:
    bool isCouple(char a, char b)
    {
        if ( (a == '(' && b == ')') || (a=='{'&&b=='}') || (a=='['&&b==']') )
        {
            return true;
        }
        return false;
    }
    string removeNearCouple(const string &s)
    {
        string result;
        int len = s.size();
        for (int i = 0; i < len; )
        {
            if ( i <len-1 && isCouple(s[i],s[i+1]) )
            {
                //remove two
                i = i+2;
            }
            else
            {
                result += s[i];
                i++;
            }
        }
        return result;
    }
    bool isValid(string s) {
        if (s.empty())
        {
            return true;
        }
        int len = s.size();
        if (2 > len)
        {
            return false;
        }
        if (len%2 > 0)
        {
            return false;
        }
        //一对一对消除
        string before = s;
        string filtered = removeNearCouple(s);
        cout << filtered << endl;
        while ( before.size() != filtered.size() )
        {
        	before = filtered;
            filtered = removeNearCouple(filtered);
        }
        if (filtered.size() > 0)
        {
            return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	string test1 = "()";
	string test2 = "(]";
	string test3 = "()[]{}";
	string test4 = "(([]){})";
	Solution s;
	cout << s.isValid(test1) << endl;
	cout << s.isValid(test2) << endl;
	cout << s.isValid(test3) << endl;
	cout << s.isValid(test4) << endl;
	return 0;
}