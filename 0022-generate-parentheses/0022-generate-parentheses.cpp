class Solution {
public:
    void helper(int open_rem, int close_rem, string s, vector<string>& ans) {

        if (open_rem == 0 && close_rem == 0) {
            ans.push_back(s);
            return;
        }

        if (open_rem > 0) {
            helper(open_rem - 1, close_rem, s + '(', ans);
        }

        if (open_rem < close_rem) {
            helper(open_rem, close_rem - 1, s + ')', ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        helper(n, n, "", ans);
        return ans;
    }
};