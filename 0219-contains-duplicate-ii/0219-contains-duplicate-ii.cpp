class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>dups;
        for(int i=0;i<nums.size();i++){
            if(dups.count(nums[i])){
                int check=abs(dups[nums[i]]-i);
                if(check <= k)
                    return true;
            }
            dups[nums[i]]=i;
        }
        return false;
    }
};