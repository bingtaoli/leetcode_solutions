
class Solution {
public:
	/*
	输入:
	A = [1,2,3,0,0,0], m = 3
	B = [2,5,6],       n = 3

	输出: [1,2,2,3,5,6]
	*/
    void merge(vector<int>& A, int m, vector<int>& B, int n) 
    {
    	//使用新空间做merge
    	//归并合并就是需要额外空间，如果为了追求原地不动排序省空间，导致代码复杂不好阅读，得不偿失。
        int sorted[m+n];
        int pa(0), pb(0);
        int i(0);
        while (i < m+n)
        {
        	if (pa == m)
        	{
        		sorted[i] = B[pb];
        		pb++;
        	}
        	else if (pb == n)
        	{
        		sorted[i] = A[pa];
        		pa++;
        	}
        	else if (A[pa] < B[pb])
        	{
        		sorted[i] = A[pa];
        		pa++;
        	}
        	else 
        	{
        		sorted[i] = B[pb];
        		pb++;
        	}
        	i++;
        }
        for (i=0; i < m+n; i++)
        {
        	A[i] = sorted[i];
        }
        return;
    }
};