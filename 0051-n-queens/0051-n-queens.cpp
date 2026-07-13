class Solution { 
public:     
    // Changed ans type to vector<vector<string>> to match the output format
    void nQueens(int n, int r, vector<int> &pos, vector<vector<string>> &ans){         
        // Base case         
        if(r == n){             
            vector<string> board(n, string(n, '.'));             
            for(int i = 0; i < n; i++){                 
                board[i][pos[i]] = 'Q';             
            }             
            ans.push_back(board);             
            return;         
        }         
        
        // Recursive case         
        for(int j = 0; j < n; j++){             
            bool canPlace = true; // Changed int to bool for clarity            
            for(int i = 0; i < r; i++){                 
                if(pos[i] == j || pos[i] == j - (r - i) || pos[i] == j + (r - i)){                     
                    canPlace = false;                     
                    break;                 
                }             
            }             
            if(canPlace == true){ // Fixed: changed '=' to '=='
                pos[r] = j;                 
                nQueens(n, r + 1, pos, ans); // Fixed: changed 'res' to 'ans'
            }         
        }     
    }     

    vector<vector<string>> solveNQueens(int n) {         
        vector<vector<string>> ans; // Fixed: changed type from int to string        
        vector<int> pos(n);         
        nQueens(n, 0, pos, ans);         
        return ans;     
    } 
};
