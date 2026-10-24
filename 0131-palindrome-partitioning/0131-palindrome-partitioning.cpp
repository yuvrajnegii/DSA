class Solution {
public:
    vector<vector<string>> ans;
    bool ispal(string s){
        int left=0;
        int right=s.size()-1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void solve(string &s, int index,vector<string>& temp){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i < s.size();i++){
            string str = s.substr(index,i-index +1);
            if(ispal(str)){
                temp.push_back(str);
                solve(s,i+1,temp);
                temp.pop_back();
            }
        }
    
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        solve(s,0,temp);
        return ans;
    }
};