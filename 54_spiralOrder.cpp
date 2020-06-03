/*
题目：螺旋矩阵

给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/spiral-matrix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) 
    {
    	//一层一层打印
    	std::vector<int> path;
    	if ( matrix.size() == 0 )
    	{
    		return path;
    	}
    	int rows = matrix.size();
    	int cols = matrix[0].size();
    	int levels = 0;
    	int levels_rows = rows/2;
    	if ( rows % 2 )
    	{
    		levels_rows++;
    	}
    	int levels_cols = cols/2;
    	if ( cols % 2 )
    	{
    		levels_cols++;
    	}
    	levels = min(levels_cols, levels_rows);
    	int currentVisitLevel = 0;
    	while (currentVisitLevel < levels)
    	{
    		int width = cols - 2*currentVisitLevel;
    		int height = rows - 2*currentVisitLevel;
    		//1th step left to right
    		for ( int j = currentVisitLevel; j <= cols - currentVisitLevel - 1; j++ )
    		{
    			int value = matrix[currentVisitLevel][j];
    			cout << value << " ";
    			path.push_back(value);
    		}
    		cout << "one level end" << endl;
    		//2th step top to bottom
    		for (int i = currentVisitLevel+1; i < rows - currentVisitLevel - 1; i++)
    		{
    			int j = cols - currentVisitLevel - 1;
    			int value = matrix[i][j];
    			cout << value << " ";
    			path.push_back(value);
    		}
    		cout << "one level end" << endl;
    		if (height > 1)
    		{
    			//3th step right to left
	    		for (int j = cols - currentVisitLevel - 1; j >= currentVisitLevel; j--)
	    		{
	    			int i = rows - currentVisitLevel - 1;
	    			int value = matrix[i][j];
	    			cout << value << " ";
	    			path.push_back(value);
	    		}	
    		}
    		cout << "one level end" << endl;
    		if (width > 1)
    		{
    			//4th step bottom to top
	    		for (int i = rows - currentVisitLevel - 2; i >= currentVisitLevel + 1; i--)
	    		{
	    			int j = currentVisitLevel;
	    			int value = matrix[i][j];
	    			cout << value << " ";
	    			path.push_back(value);
	    		}
    		}
    		cout << "one level end" << endl;
    		currentVisitLevel++;
    	}
    	cout << "end .." << endl;
    	return path;
    }
};

int main(int argc, char const *argv[])
{
	cout << "----test case----- 123 " << endl;
	{
		//[1,2,3]
		vector<vector<int> > matrix;
		{
			std::vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			matrix.push_back(v);
		}
		Solution s;
		s.spiralOrder(matrix);
	}
	cout << "----test case----- 123 " << endl;
	{
		//[[1],[2],[3]]
		vector<vector<int> > matrix;
		{
			std::vector<int> v;
			v.push_back(1);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(2);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(3);
			matrix.push_back(v);
		}
		Solution s;
		s.spiralOrder(matrix);
	}
	cout << "----test case----- 258 -1 0 4 " << endl;
	{
		//[[2,5,8],[4,0,-1]]
		vector<vector<int> > matrix;
		{
			std::vector<int> v;
			v.push_back(2);
			v.push_back(5);
			v.push_back(8);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(4);
			v.push_back(0);
			v.push_back(-1);
			matrix.push_back(v);
		}
		Solution s;
		s.spiralOrder(matrix);
	}
	cout << "----test case----- 123 6 987 4 5 " << endl;
	{
		/*
		输入:
		[
		 [ 1, 2, 3 ],
		 [ 4, 5, 6 ],
		 [ 7, 8, 9 ]
		]
		输出: [1,2,3,6,9,8,7,4,5]
		*/
		vector<vector<int> > matrix;
		{
			std::vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(4);
			v.push_back(5);
			v.push_back(6);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(7);
			v.push_back(8);
			v.push_back(9);
			matrix.push_back(v);
		}
		Solution s;
		s.spiralOrder(matrix);
	}
	cout << "----test case----- [1,2,3,4,8,12,11,10,9,5,6,7]" << endl;
	{
		/*
		输入:
		[
		  [1, 2, 3, 4],
		  [5, 6, 7, 8],
		  [9,10,11,12]
		]
		输出: [1,2,3,4,8,12,11,10,9,5,6,7]
		*/
		vector<vector<int> > matrix;
		{
			std::vector<int> v;
			v.push_back(1);
			v.push_back(2);
			v.push_back(3);
			v.push_back(4);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(5);
			v.push_back(6);
			v.push_back(7);
			v.push_back(8);
			matrix.push_back(v);
		}
		{
			std::vector<int> v;
			v.push_back(9);
			v.push_back(10);
			v.push_back(11);
			v.push_back(12);
			matrix.push_back(v);
		}
		Solution s;
		s.spiralOrder(matrix);
	}
	return 0;
}