class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        long long sum = 0;
        for (int i = 0; i < k; i++) {
            long long curMul = mul - i;          // mul decreases each step
            long long add = nums[i];
            long long multiply = (long long)nums[i] * curMul;
            sum += max(add, multiply);
        }
        return sum;
    }
};