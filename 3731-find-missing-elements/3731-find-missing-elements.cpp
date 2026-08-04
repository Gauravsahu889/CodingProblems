class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(),nums.end());

        int l0=nums[0];
        int h0=nums[0];
        for(int i=0;i<nums.size();i++){
            if(l0 >nums[i]) l0=nums[i];
            if(h0<nums[i]) h0=nums[i];
        }

        vector<int> result;
        for(int i=l0 ; i<h0;i++){
            if(numset.find(i)==numset.end()){
                result.push_back(i);
            }
        }

    return result;
    }
};