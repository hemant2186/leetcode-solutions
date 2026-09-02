class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // If all numbers are even, simply keep all of them.
        // Otherwise, pick any odd number:
        // - keep every odd number as it is
        // - for every even number x, use x - odd, which is odd
        //
        // Hence it is always possible.
        return true;
    }
};