#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        //过滤重复斜杠//
        string filtered("");
        for (int i = 0; i < path.size(); i++)
        {
            filtered += path[i];
            while (i < path.size()-1 
                   && path[i] == '/' && path[i] == path[i+1] )
            {
                i++;
            }
        }
        cout << filtered << endl;
        path = filtered;
        //根据'/'分隔
        vector<string> vecPath;
        int pre_pos(0);
        int pos(0);
        while ( (pos = path.find('/', pre_pos+1)) != string::npos)
        {
            string current = path.substr(pre_pos+1, pos-pre_pos-1);
            cout << "current path:" << current << endl;
            vecPath.push_back(current);
            pre_pos = pos;
            if ( pre_pos == (path.size()-1) )
            {
                break;
            }
        }
        if (pre_pos != (path.size()-1) )
        {
            //last segment
            string current = path.substr(pre_pos+1);
            vecPath.push_back(current);
            cout << "current path:" << current << endl;
        }
        //开始精简
        vector<string> simplifyPath;
        for (int i = 0; i < vecPath.size(); i++)
        {
            if (vecPath[i] == ".")
            {
                continue;
            }
            else if (vecPath[i] == "..")
            {
                if (simplifyPath.size() > 0)
                {
                    simplifyPath.pop_back();
                }
            }
            else 
            {
                simplifyPath.push_back(vecPath[i]);
            }
        }
        //拼接
        string result = "/";
        for (int i = 0; i < simplifyPath.size(); i++)
        {
            result += simplifyPath[i];
            if ( i != simplifyPath.size()-1 )
            {
                result += "/";
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    string test1 = "/a/../../b/../c//.//";  //c
    string test2 = "/a//b////c/d//././/..";  //c
    Solution s;
    cout << s.simplifyPath(test1) << endl;
    cout << s.simplifyPath(test2) << endl;
    return 0;
}
