class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        long int c = 0, r = 1;
        while (r <= x) {
            c = 10 * c + (x % (10 * r) - x % r) / r;
            r *= 10;
        }
        if (c == x)
            return true;
        else
            return false;
    }
};
