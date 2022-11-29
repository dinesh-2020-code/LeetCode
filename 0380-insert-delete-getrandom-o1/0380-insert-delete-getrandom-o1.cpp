class RandomizedSet {
public:
     unordered_set<int> st;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto itr = st.find(val);
        
        if (itr == st.end())
        {
            st.insert(val); 
            return true; 
        }
        else 
            return false; 
    }
    
    bool remove(int val) {
        if (st.find(val) != st.end()) {
            st.erase(st.find(val));
            return true; 
        }
        else 
            return false; 
    }
    
    int getRandom() {
        
        auto i = (rand() % st.size()); 
        auto n = st.begin();
        std::advance(n, i);
        return *n;
        // return *itr; 
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */