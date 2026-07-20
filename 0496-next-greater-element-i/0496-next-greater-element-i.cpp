class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nextGreater; // Keeps track of map name

        // Fixed: Loop starts at nums2.size() - 1 to avoid segmentation fault
        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            // Fixed: Access elements using index [i] instead of the whole vector
            nextGreater[nums2[i]] = st.empty() ? -1 : st.top();
            st.push(nums2[i]); 
        }

        vector<int> res;
        for(int x : nums1) {
            // Fixed: Changed name to match the declared variable nextGreater
            res.push_back(nextGreater[x]);
        }
        return res;
    }
};
