class Solution {
public:
    int maximum69Number (int num) {
        int ans = 0; 
        
        stringstream str; 
        
        str << num; 
        
        string no;
        str >> no; 
         
        
        for (int i = 0; i < no.size(); i++) {
            if (no[i] == '6') {
                no[i] = '9'; 
                break;
            }
            
        }
        ans = stoi(no); 
        
        return ans; 
        
    }
};