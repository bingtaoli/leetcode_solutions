#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int> > result;
        if (!numRows)
        {
            return result;
        }
        vector<int> lastLevel;
        lastLevel.push_back(1);
        result.push_back(lastLevel);
        //start from second level
        for (int i = 1; i < numRows; i++)
        {
            vector<int> currentLevel;
            currentLevel.push_back(1);
            for (int k = 0; k < lastLevel.size()-1; k++)
            {
                int total = lastLevel[k] + lastLevel[k+1];
                currentLevel.push_back(total);
            }
            if (currentLevel.size() < i+1)
            {
                currentLevel.push_back(1);
            }
            result.push_back(currentLevel);
            lastLevel = currentLevel;
        }
        return result;
    }
};
