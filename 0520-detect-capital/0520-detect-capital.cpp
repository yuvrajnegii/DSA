class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.length();
        int upper=0;
        for(int i=0;i<n;i++){
            if(isupper(word[i]))
                upper++;
        }
        if(upper==n || upper==1 && isupper(word[0]) || upper==0)
            return true;
        else
            return false;
        
    }
};