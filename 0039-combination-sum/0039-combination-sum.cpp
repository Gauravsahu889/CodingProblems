class Solution {
public:
    void getAllComb(vector<int>& candidates, int target, int i,
                    vector<int>& res, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(res);
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (target - candidates[j] >= 0) {
                res.push_back(candidates[j]);

                getAllComb(candidates, target - candidates[j], j, res, ans);

                res.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        getAllComb(candidates, target, 0, res, ans);

        return ans;
    }
};