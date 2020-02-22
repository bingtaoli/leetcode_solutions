#include <iostream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        if (!tokens.size())
        {
            return 0;
        }
        vector<int> vec;
        int len = tokens.size();
        for (int i = 0; i < len; i++)
        {
            string str = tokens[i];
            if (str == "+")
            {
                int a = vec.back();
                vec.pop_back();
                int b = vec.back();
                vec.pop_back();
                int tmp = b + a;
                vec.push_back(tmp);
            }
            else if (str == "-")
            {
                int a = vec.back();
                vec.pop_back();
                int b = vec.back();
                vec.pop_back();
                int tmp = b - a;
                vec.push_back(tmp);
            }
            else if (str == "*")
            {
                int a = vec.back();
                vec.pop_back();
                int b = vec.back();
                vec.pop_back();
                int tmp = b * a;
                vec.push_back(tmp);
            }
            else if (str == "/")
            {
                int a = vec.back();
                vec.pop_back();
                int b = vec.back();
                vec.pop_back();
                int tmp = b / a;
                vec.push_back(tmp);
            }
            else 
            {
                int a = atoi(str.c_str());
                vec.push_back(a);
            }
        }
        return vec[0];
    }
};
