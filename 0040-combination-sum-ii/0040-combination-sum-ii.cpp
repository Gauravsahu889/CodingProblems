class Solution {
public:
    void getAllcandidates(vector<int> &candidates,int target , int i , vector<vector<int>> &ans , vector<int> &res){
        //base case
        if(target==0){
            ans.push_back(res);
            return;
        }
        //recursive case
        for(int j=i;j<candidates.size();j++){
            if(target-candidates[j]>=0){
                if(j>i and candidates[j]==candidates[j-1]) continue; //skips the duplicate
                res.push_back(candidates[j]);
                getAllcandidates(candidates, target-candidates[j], j+1 , ans , res);
                res.pop_back(); //backtracking step
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        getAllcandidates(candidates, target, 0 , ans , res);
        return ans;
    }
};