class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double result = 0;
        double track = 0;
        int n = nums.size();
        for(int i = 0;i<n && i<k;i++){
            track += nums[i];
        }
        result = (double) track/k;

        for(int i = k;i<n;i++){
            track += nums[i] - nums[i-k];
            result = max((double) track/k,result);
        }
        return result;
    }
};