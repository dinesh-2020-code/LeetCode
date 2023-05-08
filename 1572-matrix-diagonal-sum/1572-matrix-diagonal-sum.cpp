class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0; 
    
        
        bool flag = false; 
        int row = mat.size(); 
        int col = mat[0].size(); 
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (i == j) {
                    sum += mat[i][j];
                }
            }
        }
        int i = 0, j = col -1 ; 
    
        while (i < row && j >= 0) {
            sum += mat[i][j]; 
            i++, j--; 
        }
        
        if (row % 2) {
            int ele = mat[row/2][col/2]; 
            sum -= ele; 
        }
    
        
        
        return sum; 
    }
};