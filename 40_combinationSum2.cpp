class Solution {
public:
    void search(const vector<int>& candidates, vector<int> &path, vector<int> &index_path, int target)
    {
        if (0 == target && path.size() > 0)
        {
            //remove duplicate using set
            //before insert, sort the array.
            vector<int> item = path;
            std::sort(item.begin(), item.end());
            res.insert(item);
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
            search(candidates, path, index_path, target-candidates[i]);
            path.pop_back();
            index_path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> path;
        vector<int> index_path;
        search(candidates, path, index_path, target);
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
