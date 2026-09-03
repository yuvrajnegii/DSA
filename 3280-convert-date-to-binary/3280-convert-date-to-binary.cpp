class Solution {
public:

    string binary(int n) {
        if(n == 0)
            return "0";

        string s = "";

        while(n > 0) {
            s += (n % 2) + '0';
            n /= 2;
        }

        reverse(s.begin(), s.end());

        return s;
    }

    string convertDateToBinary(string date) {
        string ans = "";
        string num = "";

        for(char c : date) {
            if(c == '-') {
                ans += binary(stoi(num));
                ans += '-';
                num = "";
            }
            else {
                num += c;
            }
        }

        ans += binary(stoi(num));

        return ans;
    }
};
/*
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
*/