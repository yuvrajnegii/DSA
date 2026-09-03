class Solution {
public:
    
    string convertDateToBinary(string date) {
        string s="";
        string b="";
        date+='-';
        for(auto x:date){
            if(x == '-'){
                int a=stoi(b);
                b=bitset<32>(a).to_string();
                s+=b.substr(b.find('1'));
                b="";
                s+=x;
            }
            else{
                b+=x;
            }
        }
        s.pop_back();
        return s;
    }
};