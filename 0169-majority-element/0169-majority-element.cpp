class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums){
            mp[x]++;
        }
        int s=0,a=0;
        for(auto x:mp){
            if(x.second >= nums.size()/2 && x.second > s){
                s=x.second;
                a=x.first;
            }
        }
        return a;
    }
};