#include <iostream>
#include <vector>
using namespace std;

/*
执行用时 :16 ms, 在所有 C++ 提交中击败了97.23%的用户
*/

class Solution {
public:
    static int compare(vector<int> &a, vector<int> &b)
    {
        return a[0] < b[0];  //升序
    }
    vector<vector<int> > merge(vector<vector<int> >& intervals) 
    {
    	vector<vector<int> > result;
    	if ( !intervals.size() )
    	{
    		return result;
    	}
        sort(intervals.begin(), intervals.end(), compare);
        //一个一个输出
        result.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++)
        {
        	vector<int> &item = intervals[i];
        	if (result.back()[1] < item[0])
        	{
        		//不重叠
        		result.push_back(item);
        	}
        	else if (result.back()[1] >= item[0])
        	{
        		//merge
        		if (item[1] > result.back()[1])
        		{
        		 	result.back()[1] = item[1];
        		}
        	}
        }
        return result;
    }
};

int main()
{
	vector<int> a;
	vector<int> b;
	vector<vector<int> > intervals;
	a.push_back(1);
	a.push_back(4);
	b.push_back(4);
	b.push_back(5);
	intervals.push_back(a);
	intervals.push_back(b);
	Solution s;
	vector<vector<int> > result = s.merge(intervals);
	cout << result.size() << endl;
	return 0;
}