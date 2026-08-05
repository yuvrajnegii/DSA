class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        for(auto x:s){
            if(!a.empty()){
                if(a.top()=='(' && x==')'|| a.top()=='[' && x==']' || a.top()=='{' && x=='}'){
                    a.pop();
                }
                else
                    a.push(x); 
            }
            else    
                a.push(x);
        }
        if(a.empty())   
            return true;
        return false;
    }
};