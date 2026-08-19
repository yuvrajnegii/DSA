class Solution {
public:
    //optimal
     int nextNumber(int n) {
        int sum = 0;

        while (n != 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }
    bool isHappy(int n) {
        int slow = n;
        int fast = nextNumber(n);

        while (fast != 1 && slow != fast) {
            slow = nextNumber(slow);
            fast = nextNumber(nextNumber(fast));
        }
        return fast == 1;
    }

/*
    bool isHappy(int n) {
       unordered_set<int>seen;
       while(n!=1){
        if(seen.count(n))
            return false;
        seen.insert(n);
        int sum=0;
        while(n!=0)
        {
            int digit=n%10;
            n=n/10;
            sum+=digit * digit;
        }
        n=sum;
       }
       return true;
    }
*/
};