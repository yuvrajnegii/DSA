class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0;

        for (int second = 0; second < nums.size(); second++) {

            if (nums[second] != 0) {
                swap(nums[first], nums[second]);
                first++;
            }
        }
    }
};
/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int first = 0, second = 1;

        while (second < n) {
            if (!nums[first] && nums[second]) {
                swap(nums[first], nums[second]);
                first++;
                second++;
            }
            else if (!nums[first] && !nums[second]) {
                second++;
            }
            else {
                first = second;
                second++;
            }
        }
    }
};
*/