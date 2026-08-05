class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int, int>> st;
        int n=temp.size();
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
                while (!st.empty() && st.top().second < temp[i]){
                    auto a=st.top();
                    st.pop();
                    arr[a.first] = i - a.first;
                }
                st.push({i,temp[i]});
            }
        return arr;
    }
};