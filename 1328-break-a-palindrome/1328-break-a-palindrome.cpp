class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();      
        if (n == 1)
            return "";
        
        string ans = ""; 
        int aCount = count(palindrome.begin(), palindrome.end(), 'a');
        
        if (palindrome[0] != 'a') 
            ans = 'a' + palindrome.substr(1, n - 1);
        else if (aCount == n - 1 || aCount == n) {
                ans = palindrome.substr(0, n - 1) + 'b';                 
        }
            
        else if (palindrome[0] == 'a' && palindrome[1] != 'a') {
            ans = "aa" + palindrome.substr(2, n - 2);
        }
        else 
        {
            
            
                for (int i = 0; i <= n/2; i++) {
                    if (palindrome[i] != 'a') {
                        ans = palindrome.substr(0, i) + 'a' + palindrome.substr(i + 1, n - i);
                    }
                }
            
            
                
        }
        
        return ans; 
    }
};