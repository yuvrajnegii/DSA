class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0,right=0,mins=INT_MAX,size=0;
        int sum=0;
        while(right < n){
            sum+=nums[right];
            while(sum >=target){
                size=right-left+1;
                mins=min(mins,size);
                sum-=nums[left];
                left++;
            }
            right++;
        }
        if(mins == INT_MAX)
            return 0;
        return mins;
    }
};