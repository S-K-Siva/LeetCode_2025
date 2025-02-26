class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxEndingHere = 0, minEndingHere = 0;
        int maxSum = INT_MIN, minSum = INT_MAX;

        for (int num : nums) {
            maxEndingHere = max(num, maxEndingHere + num);
            maxSum = max(maxSum, maxEndingHere);

            minEndingHere = min(num, minEndingHere + num);
            minSum = min(minSum, minEndingHere);
        }

        return max(maxSum, abs(minSum));
    }
};