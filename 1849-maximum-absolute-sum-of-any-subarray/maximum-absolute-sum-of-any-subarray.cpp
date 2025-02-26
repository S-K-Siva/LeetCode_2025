class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n, 0);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }

        int maxPrefix = 0, minPrefix = 0;
        int result = INT_MIN;

        for (int i = 0; i < n; i++) {
            result = max(result, abs(prefixSum[i] - minPrefix));
            result = max(result, abs(prefixSum[i] - maxPrefix));

            maxPrefix = max(maxPrefix, prefixSum[i]);
            minPrefix = min(minPrefix, prefixSum[i]);
        }

        return result;
    }
};