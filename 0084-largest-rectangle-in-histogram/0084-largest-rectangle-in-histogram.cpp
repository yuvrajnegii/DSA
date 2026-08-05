class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0,currHeight=0,left=0;
        for (int i = 0; i <= n; i++) {
            if(i==n)
                currHeight=0;
            else
                currHeight=heights[i];
            while (!st.empty() && heights[st.top()] > currHeight){
                int height = heights[st.top()];
                st.pop();
                if(st.empty())
                    left=-1;
                else
                    left=st.top();
                int width = i-left-1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        return maxArea;
    }
};
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> st;

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
        // Clear stack
        while (!st.empty())
            st.pop();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }

        int maxArea = 0;
        // Calculate maximum area
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;

            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
*/