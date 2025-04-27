class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = INT_MIN;
        int n = nums.size();
        int track = 0;
        for(int i = 0;i<k && i<n;i++){
            track += nums[i];
        }
        result = max(result, (double)track/k);
        for(int i = k;i<n;i++){
            track -= nums[i-k];
            track += nums[i];
            result = max(result, (double)track/k);
        }
        return result;
    }
};