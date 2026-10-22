class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& cand,int rem,int index,vector<int> temp){
        if(rem == 0){
            ans.push_back(temp);        
            return;
        }
        if(rem < 0 || index == cand.size()){
            return;
        }
        for(int i = index;i < cand.size();i++){
            temp.push_back(cand[i]);
            int newrem = rem - cand[i];
            solve(cand,newrem,i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        solve(candidates,target,0,temp);
        return ans;
    }
};