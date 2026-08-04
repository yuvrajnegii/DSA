/*
class Solution {
public:
    bool isPalindrome(string s) {
        
        string temp="";
        for(auto x:s){
            if(isalnum(x))
                temp+=tolower(x);
        }
        int n=temp.size();
        for(int i=0;i<n/2;i++){
            if(temp[i]!=temp[n-i-1])
                return false;
        }
        return true;
    }
};
*/

//for O(1) space
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;

        while(l < r){
            while(l < r && !isalnum(s[l])) l++;
            while(l < r && !isalnum(s[r])) r--;

            if(tolower(s[l]) != tolower(s[r]))
                return false;

            l++;
            r--;
        }
        return true;
    }
};