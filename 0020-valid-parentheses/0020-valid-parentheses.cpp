//Better solution
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else {
                if (st.empty() || st.top() != c)
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

/* 
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                st.push(c);
            }
            else {
                if (st.empty())
                    return false;
                if ((st.top() == '(' && c == ')') ||
                    (st.top() == '[' && c == ']') ||
                    (st.top() == '{' && c == '}'))
                {
                    st.pop();
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};
*/