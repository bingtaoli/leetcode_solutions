#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 0){
            return false;
        }
        sort(nums.begin(), nums.end());  // sort
        int prev = nums[0];
        for (int i = 1; i < n; i++){
            int current = nums[i];
            if (current == prev){
                return true;    
            }
            prev = current;
        }
        return false;
    }
};

int main(){
    vector<int> vi;
    Solution s;
    vi.push_back(1);
    vi.push_back(2);
    vi.push_back(3);
    vi.push_back(1);
    bool result = s.containsDuplicate(vi);
    if (result == true){
        cout << "duplicate" << endl;
    } else {
        cout << "not duplicate" << endl;    
    }
    return 0;
}
