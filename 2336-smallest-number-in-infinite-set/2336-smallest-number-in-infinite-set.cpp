class SmallestInfiniteSet {
private: 
    set<int> integers; 
    int currInteger; 
    
public:
    SmallestInfiniteSet() {
        currInteger = 1; 
    }
    
    int popSmallest() {
        int ans; 
        
         
        if (!integers.empty()) {
            ans = *integers.begin();
            integers.erase(integers.begin());
        }
        else {
            ans = currInteger; 
            currInteger += 1; 
        }
        return ans; 
    }
    
    void addBack(int num) {
        
        if (currInteger <= num || integers.find(num) != integers.end()) {
            return; 
        }
        integers.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */