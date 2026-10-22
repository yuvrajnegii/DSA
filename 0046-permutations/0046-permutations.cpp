class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    void solve(vector<int>& nums,vector<int>& visited){
        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i = 0;i < nums.size();i++){
            if(visited[i] == 0){
                visited[i]=1;
                temp.push_back(nums[i]);
                solve(nums,visited);
                temp.pop_back();
                visited[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> visited(nums.size(), 0);
        solve(nums,visited);
        return ans;
    }
};