#include <iostream>
#include <stack>
#include <string>

class Solution { 
public:     
    bool isValid(std::string s) {         
        std::stack<char> st; // 1. Fixed variable name conflict by using 'st'
        
        for (char ch : s) {             
            // If it's an opening bracket, push it to the stack
            if (ch == '(' || ch == '{' || ch == '[') {                 
                st.push(ch);             
            }             
            // If it's a closing bracket, validate carefully
            else {                 
                // 2. Prevent crash: check if stack is empty first
                if (st.empty()) {
                    return false; 
                }
                
                // 3. Match the closing bracket with its correct opening bracket
                if (ch == ')' && st.top() == '(') {                 
                    st.pop();             
                } 
                else if (ch == '}' && st.top() == '{') {                 
                    st.pop();             
                } 
                else if (ch == ']' && st.top() == '[') { // 4. Fixed 'else if' syntax error                
                    st.pop();             
                } 
                else {
                    // Mismatched bracket type found
                    return false; 
                }
            }          
        }         
        // Return true only if all opening brackets were cleared out
        return st.empty();     
    } 
};
