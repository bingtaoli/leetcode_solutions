/*
给定一个二维网格和一个单词，找出该单词是否存在于网格中。

单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。

 

示例:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

给定 word = "ABCCED", 返回 true
给定 word = "SEE", 返回 true
给定 word = "ABCB", 返回 false

提示：

board 和 word 中只包含大写和小写英文字母。
1 <= board.length <= 200
1 <= board[i].length <= 200
1 <= word.length <= 10^3


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-search
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/*
使用dfs方法，测试时候一直超时通不过，是哪里耗时严重呢？？
一开始是这样：
bool ex = dfs(board, visted, i-1, j, word) || dfs(board, visted, i+1, j, word) ||
	       dfs(board, visted, i, j-1, word) || dfs(board, visted, i, j+1, word)
这样导致每个方向都要遍历，其实我们只要找到了路径就可以返回true了
就改为下面这种方式：
if ( dfs(board, visted, i-1, j, word) )
{
	return true;
}
if ( dfs(board, visted, i+1, j, word) )
{
	return true;
}
if ( dfs(board, visted, i, j-1, word) )
{
	return true;
}
if ( dfs(board, visted, i, j+1, word) )
{
	return true;
}

最后时间消耗就在及格线内了。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

	bool dfs(vector<vector<char> >& board, int **visted, int i, int j, std::vector<char> &word)
	{
		if (word.size() == 0)
		{
			//遍历结束了
			return true;
		}
		//越界
		if (i < 0 || i >= board.size())
		{
			return false;
		}
		if (j < 0 || j >= board[0].size())
		{
			return false;
		}
		if (visted[i][j] == 1)
		{
			return false;
		}
		char value = word.back();
		//值不一样
		if (board[i][j] != value)
		{
			return false;
		}
		else
		{
			//printf("bord[%d][%d]:%c value:%c\n", i, j, board[i][j], value);
		}
		//make this choice
		visted[i][j] = 1;
		word.pop_back();
		char tmp = board[i][j];
		if ( dfs(board, visted, i-1, j, word) )
		{
			return true;
		}
		if ( dfs(board, visted, i+1, j, word) )
		{
			return true;
		}
		if ( dfs(board, visted, i, j-1, word) )
		{
			return true;
		}
		if ( dfs(board, visted, i, j+1, word) )
		{
			return true;
		}
		visted[i][j] = 0;
		//回溯 back this choice，不能影响别的选择 
		word.push_back(tmp);
		return false;
	}

	void clearVisted(int **visted, int rows, int cols)
	{
		for (int i = 0; i < rows; i++)
		{
			memset(visted[i], 0, cols * sizeof(int));
		}
	}

    bool exist(vector<vector<char> >& board, string word) 
   	{
   		int rows = board.size();
   		int cols = board[0].size();
   		//printf("rows:%d cols:%d word.size:%u\n", rows, cols, word.size());
   		//init visit
   		int **visted = new int*[rows];
   		for (int i = 0; i < rows; i++)
   		{
   			visted[i] = new int[cols];
   		}
   		for (int i = 0; i < rows; i++)
   		{
   			for (int j = 0; j < cols; j++)
   			{
   				std::vector<char> word_list;
				for (int k = word.size()-1; k >= 0 ; k--)
				{
					word_list.push_back( word[k] );
				}
				clearVisted(visted, rows, cols);
   				bool ex = dfs(board, visted, i, j, word_list);
   				if (ex)
   				{
   					return true;
   				}
   			}
   		}
   		return false;
    }
};

int main()
{
	Solution solu;
	{
		vector<vector<char> > board;
		{
			std::vector<char> v1;
			v1.push_back('A');
			v1.push_back('B');
			v1.push_back('C');
			v1.push_back('E');
			board.push_back(v1);
		}
		{
			std::vector<char> v1;
			v1.push_back('S');
			v1.push_back('F');
			v1.push_back('C');
			v1.push_back('S');
			board.push_back(v1);
		}
		{
			std::vector<char> v1;
			v1.push_back('A');
			v1.push_back('D');
			v1.push_back('E');
			v1.push_back('E');
			board.push_back(v1);
		}
		string s1 = "ABCCED";  //true
		string s2 = "SEE";     //true
		string s3 = "ABCB";    //false
		cout << solu.exist(board, s1) << endl;
		cout << solu.exist(board, s2) << endl;
		cout << solu.exist(board, s3) << endl;
	}
	{
		vector<vector<char> > board;
		{
			std::vector<char> v1;
			v1.push_back('a');
			board.push_back(v1);
		}
		string s = "a";
		cout << solu.exist(board, s) << endl;
	}
	return 0;
}