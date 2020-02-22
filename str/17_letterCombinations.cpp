#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public: 
    void initMap(map<char, string> &dig2str)
    {
        dig2str['2'] = "abc";
        dig2str['3'] = "def";
        dig2str['4'] = "ghi";
        dig2str['5'] = "jkl"; 
        dig2str['6'] = "mno"; 
        dig2str['7'] = "pqrs"; 
        dig2str['8'] = "tuv"; 
        dig2str['9'] = "wxyz"; 
        return;
    }
    void dfs(int index, vector<char> &path, string digits)
    {
        if (index == digits.size())
        {
            string item;
            for (int i = 0; i < path.size(); i++)
            {
                item += path[i];
            }
            result.push_back(item);
            return;
        }
        string choice = g_map[digits[index]];
        for (int i = 0; i < choice.size(); i++)
        {
            path.push_back(choice[i]);
            dfs(index+1, path, digits);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        int len = digits.size();
        if (!len)
        {
            return result;
        }
        initMap(g_map);
        vector<char> path;
        dfs(0, path, digits);
        return result;
    }
private:
    vector<string> result;
    map<char, string> g_map;
};

int main(int argc, char const *argv[])
{
	/* code */
	string test1 = "23";
	Solution s;
	vector<string> result = s.letterCombinations(test1);
	cout << result.size() << endl;
	return 0;
}