class Solution { 
public:     
    vector<int> t;  

    bool solve(int n) {         
        if(n == 0) return false;          
        if(t[n] != -1) {             
            return t[n] == 1;         
        }         
        
        for(int k = 1; k * k <= n; k++) {             
            if(solve(n - (k * k)) == false) {                 
                return t[n] = 1; // Store 1 for true
            }         
        } // <-- Added missing closing brace for the loop
        
        return t[n] = 0; // Store 0 for false
    }     

    bool winnerSquareGame(int n) {         
        t.assign(n + 1, -1);         
        return solve(n);       
    } 
};