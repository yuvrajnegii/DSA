class Solution {
public:
    int compress(vector<char>& chars) {
        string s;
        if(chars.size()==1)
            return 1;
        int read=0,count=1;
        s+=chars[read];
        for(int write=1;write<chars.size();write++)
        {
            if(chars[read]==chars[write] )
                count++;
            else{
                if(count>1)
                    s+=to_string(count);
                s+=chars[write];
                read=write;
                count=1;
            }
        }
        if(count>1)
            s+=to_string(count);
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.size();    
    }
};