class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        long long currentS = 0;

        for(int i = 0; i < k; i++) {
            currentS += nums[i];
        }

        long long maxS = currentS;

        for(int i = k; i < nums.size(); i++) {
            currentS += nums[i];
            currentS -= nums[i - k];

            if(currentS > maxS)
                maxS = currentS;
        }

        return (double)maxS / k;
    }
};