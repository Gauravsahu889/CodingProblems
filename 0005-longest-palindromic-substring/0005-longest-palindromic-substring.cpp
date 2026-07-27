#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        int maxlen = 1;
        string ans = s.substr(0, 1);

        // calculate odd palindromes
        for (int i = 0; i < n; i++) {
            int j = 0;
            // FIXED: changed i+j to i-j to prevent out-of-bounds crashes
            while (i - j >= 0 && i + j <= n - 1 && s[i - j] == s[i + j]) {
                if (2 * j + 1 > maxlen) {
                    maxlen = 2 * j + 1;
                    ans = s.substr(i - j, maxlen);
                }
                j++;
            }
        }
        
        // calculate even palindromes using double
        for (double i = 0.5; i <= n - 1; i++) {
            double j = 0.5;
            // FIXED: replaced s(int[...]) syntax with proper static_cast<int> syntax
            while (i - j >= 0 && i + j <= n - 1 && s[static_cast<int>(i - j)] == s[static_cast<int>(i + j)]) {
                int size = (int)(2 * j + 1);
                if (size > maxlen) {
                    maxlen = size;
                    // FIXED: i-j must be explicitly cast to an int for substr()
                    ans = s.substr(static_cast<int>(i - j), maxlen);
                }
                j++;
            }
        }
        return ans;
    }
};
