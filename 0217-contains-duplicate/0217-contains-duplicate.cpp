class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashSet;

        for (int i : nums) {
            if (hashSet.find(i) != hashSet.end()) {
                return true;
            }
            hashSet.insert(i);
        }

        return false;
    }
};