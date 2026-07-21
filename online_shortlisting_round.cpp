#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); 
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {  // s[i] == ')'
            st.pop();
            if (st.empty()) {
                st.push(i); 
            } else {
                maxLen = max(maxLen, i - st.top());
            }
        }
    }

    return maxLen;
}

int main() {
    cout << longestValidParentheses("(()") << endl;    // Output: 2
    cout << longestValidParentheses(")()())") << endl;  // Output: 4
    cout << longestValidParentheses("") << endl;        // Output: 0
  
}