class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        long rev=0,temp=x;
        while(temp){
            long num=temp%10;
            rev=rev*10+num;
            temp/=10;
        }
        return (rev==long(x));
    }
};