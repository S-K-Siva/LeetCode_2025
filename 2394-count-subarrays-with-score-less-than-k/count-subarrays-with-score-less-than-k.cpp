class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int l = 0;
        int n = nums.size();
        long long cnt = 0;
        long long prefixSum = 0;
        
        for (int r = 0; r < n; r++) {
            prefixSum += nums[r];
            
            while ((prefixSum)*(r-l+1) >= k && l <= r) {
                prefixSum -= nums[l++];
            }
            
            cnt += (r - l + 1);
        }
        
        return cnt;
    }
};
