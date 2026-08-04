class Solution {
public:
    string minWindow(string s, string t) {
        
        vector<int>thash(128,0);
        vector<int>wind(128,0);
        int left=0,right=0,req=0,form=0;
        int m=s.size();
        int n=t.size();
        if(n>m)
            return "";
        for(char c : t)
            thash[c]++;

        for (int i = 0; i < 128; i++)
        {
            if (thash[i] > 0)
                req++;
        }
        int minl = INT_MAX,start=0;
        while(right < s.size()){
            char c = s[right];
            wind[c]++;
            if (wind[c] == thash[c])
                form++;
            while(form == req){
                if(right-left+1 < minl){
                    minl=right-left+1;
                    start=left;
                }
                wind[s[left]]--;
                if(wind[s[left]] < thash[s[left]])
                    form--;
                left++;
            }
            right++;
        }
        if (minl == INT_MAX)
            return "";
        return s.substr(start,minl);
    }
};