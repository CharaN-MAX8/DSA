class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        long long rev = 0;
        int t = x;
        while(t > 0){
            rev = rev*10 + t % 10;
            t = t/10;
        }
        return rev == x;
    }
};