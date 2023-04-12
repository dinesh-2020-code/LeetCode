class Solution {
    
    void printStack(stack<string> st) {
        while (!st.empty()) {
            cout << st.top() << " "; 
            st.pop(); 
        }
        cout  << endl; 
    }
public:
    string simplifyPath(string path) {
        
        stack <string> st; 
        int n = path.size();
        
        
        for (int i = 0; i < n; i++) {
            string temp = "";
            if (path[i] == '/')
                continue; 
            
            while (i < n && path[i] != '/') {
                temp += path[i];
                i++; 
            }
            
            if (temp == ".") {
                continue; 
            }
            else if (temp == ".." ){
                if (!st.empty())
                    st.pop(); 
            }
            else {
                st.push(temp);
                
            }
            
            // printStack(st); 
            
        }
        // cout << "After while loop \n"; 
        // printStack(st); 
        string ans  = "";
        
        while (!st.empty()) {
            ans = "/" + st.top() + ans; 
            st.pop();
        }
        if (ans.size() == 0) {
            return "/" + ans; 
        }
        return ans; 
        //  "/a/./b/../../c/"
        //  "/a//b////c/d//./././.."
        // "/home/"
        // "/..hidden/.."
    }
};