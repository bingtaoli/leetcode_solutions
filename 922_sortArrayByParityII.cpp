class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> v1;
        vector<int> v2;
        for (int i = 0; i < A.size(); i++)
        {
            if (A[i] % 2 == 0)
            {
                v2.push_back(A[i]);
            }
            else
            {
                v1.push_back(A[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < v2.size(); i++)
        {
            res.push_back(v2[i]);
            res.push_back(v1[i]);
        }
        return res;
    }
};
