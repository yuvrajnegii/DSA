class Solution {
    public String removeDuplicates(String s) {
        Deque<Character>st=new ArrayDeque<>();
        for(char c:s.toCharArray())
        {
            if(!st.isEmpty() && st.peek() == c)
                st.pop();
            else
                st.push(c);
        }
        String a="";
        while(!st.isEmpty()){
            a=st.peek() + a;
            st.pop();
        }
        return a;
    }
}