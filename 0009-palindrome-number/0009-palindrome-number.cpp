class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;
        int rev = 0;
        int dig = 0;
        while (temp > 0){
            dig = temp%10;

            if (rev > INT_MAX/10 || rev < INT_MIN/10) return 0;
            rev = rev*10 + dig;
            temp = temp/10;
        }
        if (rev == x) return true;
        else return false;
    }
};