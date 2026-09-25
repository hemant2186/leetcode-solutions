class Solution {
public:
       bool isPerfectSquare(int num) {
        long int i = 1;
        for(;i*i<num;i++);
        return i*i==num;
    }
};