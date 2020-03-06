#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> lastLevel;
        lastLevel.push_back(1);
        if (!rowIndex)
        {
            return lastLevel;
        }
        for (int i = 1; i <= rowIndex; i++)
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
            lastLevel = currentLevel;
        }
        return lastLevel;
    }
};
