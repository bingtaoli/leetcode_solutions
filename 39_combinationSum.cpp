class Solution {
public:
    void search(const vector<int>& candidates, vector<int> &path, int target)
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
        for (unsigned int i = 0; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            search(candidates, path, target-candidates[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> path;
        search(candidates, path, target);
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
