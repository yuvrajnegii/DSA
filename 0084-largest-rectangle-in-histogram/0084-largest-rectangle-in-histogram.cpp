class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;          // stores indices, heights[stack] increasing
        heights.push_back(0);   // sentinel to flush remaining bars
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        heights.pop_back(); // restore original vector (optional, avoids side effects)
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