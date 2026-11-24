class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int k = weights.size(), high = 0;
        int low = *max_element(weights.begin(), weights.end());
        for(int n : weights)
            high += n;
        
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int day = 1;
            int load = 0;
            for(int i = 0; i < k; i++) {
                if(load + weights[i] > mid) {
                    day++;
                    load = weights[i];
                }
                else 
                    load += weights[i];
            }
            if(day <= days)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};