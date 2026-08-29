class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size())
            return false;
        auto str=s+s;
        int pos = str.find(goal);
        if(pos != -1)
            return true;
        return false;
        }

};