class SmallestInfiniteSet {
private: 
    set<int> st; 
    
public:
    SmallestInfiniteSet() {
        // st = new set(); 
        
        for (int i = 1; i <= 1000; i++) {
            st.insert(i); 
        }
    } 
    
    int popSmallest() {
        int item = *(st.begin()) ; 
        st.erase(st.begin());
        return item; 
    }
    
    void addBack(int num) {
        st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */