class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ind;
        int st=0,end=nums.size()-1;
        for(int i=1;i<n;i++){
                if(nums[st]+nums[end]==target){
                    ind.push_back(st+1);
                    ind.push_back(end+1);
                    break;
                }
                else if(nums[st]+nums[end]>target)
                    end--;
                else
                    st++;
            }
        return ind;
    }
};