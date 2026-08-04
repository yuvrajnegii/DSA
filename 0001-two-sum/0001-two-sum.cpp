class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>ind;
        int x=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(target==nums[i]+nums[j]){
                    ind.push_back(i);
                    ind.push_back(j);
                    break;
                }
            }
        }
        return ind;
    }
};