class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Sort both arrays to apply a greedy approach
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int n = g.size(); // Number of children
        int m = s.size(); // Number of cookies
        
        int l = 0; // Pointer for children (g)
        int r = 0; // Pointer for cookies (s)
        
        // Loop runs only while we have both children and cookies left
        while (l < n && r < m) {
            // If the cookie size satisfies the child's greed
            if (g[l] <= s[r]) {
                l++; 
            }
            r++; 
        }
        
        return l; 
    }
};
