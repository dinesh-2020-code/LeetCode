class Solution {
public:
    bool checkIfPangram(string sentence) {
        // int *freq = new int[26];
        int freq[26];
        memset(freq, 0, sizeof(freq));
        
        
        
        for (int i = 0; i < sentence.length(); i++) {
            freq[sentence[i] - 'a']++; 
        }
        
//         for (int i = 0; i < 26; i++) {
//             cout << freq[i] << " "; 
//         }
//         cout << endl; 
        
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0)
                return false; 
        }
        

        return true; 
    }
};