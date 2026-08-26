class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are not palindromes
        // Numbers ending in 0 are not palindromes (except 0 itself)
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // Even number of digits: x == reversedHalf
        // Odd number of digits: ignore middle digit
        return x == reversedHalf || x == reversedHalf / 10;
    }
};