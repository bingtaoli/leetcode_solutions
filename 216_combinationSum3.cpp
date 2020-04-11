class Solution {
public:
    void search(const vector<int>& candidates, vector<int> &path, 
                vector<int> &index_path, int target, const int k)
    {
        if (0 == target)
        {
            if (path.size() == k)
            {
                //remove duplicate using set
                //before insert, sort the array.
                vector<int> item = path;
                std::sort(item.begin(), item.end());
                res.insert(item);
            }
            else
            {
                return;
            }
        }
        if (target < 0)
        {
            return;
        }
        unsigned int i = 0;
        if (index_path.size())
        {
            i = index_path.back() + 1;
        }
        for (; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            index_path.push_back(i);
            search(candidates, path, index_path, target-candidates[i], k);
            path.pop_back();
            index_path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> candidates;
        for (int i = 1; i <= 9; i++)
        {
            candidates.push_back(i);
        }
        vector<int> path; 
        vector<int> index_path;
        search(candidates, path, index_path, n, k);
        //return vector
        vector<vector<int>> v_res;
        for (auto iter = res.begin(); iter != res.end(); iter++)
        {
            v_res.push_back(*iter);
        }
        return v_res;
    }
private:
    set<vector<int>> res;
};
