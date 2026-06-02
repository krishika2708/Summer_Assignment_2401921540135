class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;

        for (int value : nums) {
            if (seen.count(value))
                return true;

            seen.insert(value);
        }

        return false;
    }
};