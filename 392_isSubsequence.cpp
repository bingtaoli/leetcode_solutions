#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int slow(0);
        int fast(0);
        for (int i = 0; i < s.size(); i++)
        {
            char currentChar = s[i];
            fast = t.find(currentChar, slow);
            printf("i:%d slow:%d fast:%d\n", i, slow, fast);
            if (fast == string::npos)
            {
                return false;
            }
            slow = fast+1;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string s = "leeeeetcode";
    string t = "leeeetcode";
    Solution so;
    cout <<so.isSubsequence(s, t) << endl;
    return 0;
}