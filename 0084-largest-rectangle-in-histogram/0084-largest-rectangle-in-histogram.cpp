class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;          // stores indices, heights[stack] increasing
        heights.push_back(0);   // sentinel to flush remaining bars
        int maxArea = 0,width = 0;
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int height = heights[st.top()];
                st.pop();
                if(st.empty())
                    width=i;
                else
                    width=i-st.top()-1;
                maxArea = max(maxArea, height * width);
            }
            st.push(i);
        }
        heights.pop_back(); // restore original vector (optional, avoids side effects)
        return maxArea;
    }
};
