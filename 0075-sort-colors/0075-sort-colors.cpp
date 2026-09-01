class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]++;
        int i=0;
        for(int color=0 ; color <= 2 ; color++){
            for(int j=0; j < mp[color] ; j++){
            nums[i] = color;
            i++;
            }
        }
    }
};