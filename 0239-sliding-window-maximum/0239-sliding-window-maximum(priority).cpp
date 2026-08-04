class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        priority_queue<pair<int,int>> pq;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // Insert current element with its index
            pq.push({nums[i], i});

            // Remove elements outside the current window
            while (!pq.empty() && pq.top().second <= i - k)
                pq.pop();

            // First complete window
            if (i >= k - 1)
                ans.push_back(pq.top().first);
        }

        return ans;
    }
};
