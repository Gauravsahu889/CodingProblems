class Solution {
public:
    void getAllSubsets(vector<int> &nums,int i,vector<int> & ans,vector<vector<int>> &allSubsets){
        //base case 
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        //recusive case
        //pick the element
        ans.push_back(nums[i]);
        getAllSubsets(nums,i+1,ans,allSubsets);

        //do not pick the element 
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]) idx++;
        getAllSubsets(nums,idx,ans,allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;

         getAllSubsets(nums,0,ans,allSubsets);
         return allSubsets;
        
    }
};