class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        deque<int> dq;
        for(int i=0;i<=n-1;i++){
            if(!dq.empty()&& dq.front() <=i-k){
                dq.pop_front(); //window outside condition 
            }
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if(i>=k-1) {
                v.push_back(nums[dq.front()]);
        }
        }
        return v;

    }
};