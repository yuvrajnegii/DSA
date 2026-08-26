class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int a=0;
        for(auto x:nums)
            a^=x;
        unsigned int bit = (unsigned int)a & -(unsigned int)a;
        int u1=0,u2=0;
        for(auto x:nums){
            if(bit &  x)
                u1^=x;
            else
                u2^=x;
        }
        return {u1,u2};
    }   
};