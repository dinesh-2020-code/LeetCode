class Solution {
private: 
    void solve(string digits, vector<string> mapping, string output, vector<string> &ans, int index) {
        if (index >= digits.size()) {
            ans.push_back(output); 
            return; 
        }
        
        int number = digits[index] - '0'; 
        
        string value = mapping[number]; 
        
        for (int i = 0; i < value.size(); i++) {
            output.push_back(value[i]); 
            solve(digits, mapping, output, ans, index + 1);
            output.pop_back(); 
            
        }
        
    }
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans; 
        
        if (digits.size() == 0) {
            return ans; 
        }
        vector<string> mapping= {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output = ""; 
        solve(digits, mapping, output,  ans, 0); 
        
        return ans; 
    }
};