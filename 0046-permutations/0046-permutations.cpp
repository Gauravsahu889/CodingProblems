class Solution {
public:
    void AllPermutations(int i , vector<vector<int>> &result ,vector<int> &nums){
        //base case
        if(i==nums.size()){
            result.push_back(nums);
        }
        //recursive case
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            AllPermutations(i+1,result,nums);
            swap(nums[i],nums[j]); //backtracking step 
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
     int n=nums.size();
     vector<vector<int>> result;
     AllPermutations(0, result,nums);
     return result;
    }
};