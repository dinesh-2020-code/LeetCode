class Solution {
public:
    bool halvesAreAlike(string s) {
        
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        
        int size = s.size(); 
        
        string a = s.substr(0, size/2);
        string b = s.substr(size/2, size); 
        
        int avCount = 0, bvCount = 0;
        
        for (auto it : a) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                avCount++; 
        }
        for (auto it : b) {
            if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u')
                bvCount++; 
        }
         
        return (avCount == bvCount); 
    }
};