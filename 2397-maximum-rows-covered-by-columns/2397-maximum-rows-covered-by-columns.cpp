class Solution { 
public:
    int isValid(vector<vector<int>>& matrix, vector<int> &cols) {
        
        unordered_map<int, int> mp; 
        
        for (auto i : cols) 
            mp[i]++; 
        
        // bool flag; 
        int result = 0; 
        for (int i = 0; i < matrix.size(); i++) {
            bool flag = true; 
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 1 )
                {
                    if(mp[j] == 0){                  
                    flag = false; 
                    break; 
                }}
            }
            if (flag)
                result++; 
        }
        
        return result; 
    }
    void solve(vector<vector<int>>& mat, int numSelect, int &ans, vector<int> &cols, int index) {
        
        if (numSelect == 0) {
            ans = max(ans, isValid(mat, cols));
            return; 
        }
        
        for (int i = index; i < mat[0].size(); i++) {
            cols.push_back(i);
            solve(mat, numSelect-1, ans, cols, i + 1);
            cols.pop_back(); 
        }
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0; 
        vector<int> cols; 
        
        solve(matrix, numSelect, ans, cols, 0);
        
        return ans; 
    }
};