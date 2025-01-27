class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int n = nums.size();
        int result = nums[0];
        int track = nums[0];
        for(int i = 1;i<n;i++){
            track = max(nums[i],track + nums[i]);
            result = max(result, track);
        }
        return result;
    }
};