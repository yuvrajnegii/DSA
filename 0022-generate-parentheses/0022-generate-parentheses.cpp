class Solution {
public:
    void helper(int open,int close,string str,vector<string>&ans){
        if(open==0 && close==0){
            ans.push_back(str);
            return;
        }
        if(open>0){
            string curr=str+"(";
            helper(open-1,close,curr,ans);
        }
        if(open<close){
            string curr=str+")";
            helper(open,close-1,curr,ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str="";
        helper(n,n,str,ans);
        return ans;
    }
};