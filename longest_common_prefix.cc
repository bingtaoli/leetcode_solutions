#include <iostream>
#include <vector>
using namespace std;

//Write a function to find the longest common prefix string amongst an array of strings.
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0){
            return "";
        }
        while (strs.size() > 1){
            string common = longestOfTwo(strs[0], strs[1]);
            strs.push_back(common);
            strs.erase(strs.begin());
            strs.erase(strs.begin());
        }
        return strs[0];
    }
    string longestOfTwo(const string &a, const string &b){
        string common;
        int n = std::min(a.length(), b.length());
        int i = 0;
        while(i < n){
            if (a.at(i) == b.at(i)){
                common += a.at(i);
            } else {
                break;
            }
            i++;
        }
        return common;
    }
};

int main(){
    vector<string> strs;
    strs.push_back("hesss");
    strs.push_back("hesso");
    strs.push_back("hes1o");
    Solution s;
    string common = s.longestCommonPrefix(strs);
    cout << "longest common: " << common << endl;
    return 0;
}