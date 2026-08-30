class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& inter) {
        int n=inter.size();
        vector<vector<int>>ans;
        sort(inter.begin(),inter.end());
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(inter[i]);
            }
            else{
                vector<int>&v=ans.back();
                int end=v[1];//end time of previous interval
                //compare end time of previous
                if(inter[i][0]<=end){
                    v[1]=max(v[1],inter[i][1]);
                }
                else{
                    ans.push_back(inter[i]);
                }
            }
        }
        return ans;
    }
};