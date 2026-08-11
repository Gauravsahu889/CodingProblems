class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int i=1;
        
        while(i<n && nums[i]==nums[i-1]+1){
            i++;

        }
        long long x=0;
        for(int j=0;j<i;j++){
            x+=nums[j];
        }
        unordered_set<int> s(nums.begin(),nums.end());
        while (s.find((int)x) != s.end()) {
            x++;
        }

        return (int)x;
    }
};