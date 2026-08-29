class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(51, 0);

        for (int i : nums)
            ++freq[i];
        int ans = -1;
        /*if freq=1
          case 1: first element
          case 2: last element
          case 3: window size 1
          case 4: a case where window size is equal to size of array
        */
        for (int i = 0; i < n; i++) {
            if (k == n) {
                ans = max(ans, nums[i]);
            }
            else {
                if (freq[nums[i]] == 1) {
                    if (k == 1 || i == 0 || i == n - 1)
                        ans = max(ans, nums[i]);
                }
            }
        }
        return ans;
    }
};