class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int ans = 0; 
        int l1 = (ax2 - ax1), b1 = (ay2 - ay1); 
        int l2 = (bx2 - bx1), b2 = (by2 - by1);
        
        int A1 = l1 * b1, A2 = l2 * b2; 
        int ox1 = max(ax1, bx1), ox2 = min(ax2, bx2);
        int oy1 = max(by1, ay1), oy2 = min(by2, ay2);
        
        int ol1 = max((ox2 - ox1), 0), ol2 = max((oy2 - oy1), 0);   //if rectangles are not overlapping then the ol1 and ol2 will be negative so we are takng the max of overlapping region and 0
        // cout << ol1 << " " <<ol2 << endl; 
        int oArea = ol1 * ol2; 
        // cout << oArea << endl; 
        ans = (A1 + A2) - oArea; 
        
                
        return ans; 
    }
};