class Solution {
public:
bool isvowel(char c) {
    return string("aeiouAEIOU").find(c) != string::npos;
}
    string reverseVowels(string s) {
        int right=s.length()-1;
        int left=0;
        while(left < right){
            while(left < right && !isvowel(s[left])){
                left++;
            }
            while(left < right && !isvowel(s[right])){
                right--;
            }
        swap(s[right],s[left]);
        right--;
        left++;
        }
        return s;
    }

};