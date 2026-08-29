class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        //map structure: {prefix_sum,index}
        mp[0]=-1;
        //0 sum and with index at -1 (not yet started)
        int prefix=0,count=0;
        for(int i=0;i<n;i++){
            //if not 1 add -1
            prefix+=(nums[i]==1) ? 1 : -1;
            if(mp.find(prefix)!=mp.end()){
                int size=i-mp[prefix];
                count=max(count,size);
            }
            else{
                mp[prefix]=i;
            }
        }
        return count;
    }
};