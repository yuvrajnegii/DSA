class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        s += ' ';

        string sen = "";
        string rep = "";

        for (auto x : s) {
            if (x == ' ') {
                if (!rep.empty()) {              // ADD THIS
                    reverse(rep.begin(), rep.end());
                    sen += rep;
                    sen += ' ';
                    rep = "";
                }
            }
            else {
                rep += x;
            }
        }

        sen.pop_back();
        return sen;
    }
};