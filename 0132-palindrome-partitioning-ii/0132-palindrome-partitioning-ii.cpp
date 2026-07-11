class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // isPalin[i][j] = true if s[i..j] is a palindrome
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPalin[i + 1][j - 1])) {
                    isPalin[i][j] = true;
                }
            }
        }

        vector<int> dp(n + 1, 0);
        dp[n] = -1; // so dp[0] gives correct cuts directly (no need for -1 at the end)

        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (isPalin[i][j]) {
                    minCost = min(minCost, 1 + dp[j + 1]);
                }
            }
            dp[i] = minCost;
        }

        return dp[0];
    }
};