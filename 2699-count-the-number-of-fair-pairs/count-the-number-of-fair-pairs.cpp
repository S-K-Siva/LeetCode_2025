class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // long long cnt = 0;
        // int n = nums.size();
        // for(int i = 0;i<n;i++){
        //     for(int j = i+1;j<n;j++){
        //         int val = nums[i] + nums[j];
        //         if(lower <= val && val <= upper) cnt++;
        //     }
        // }
        // return cnt;
        long long res = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 1; i++) {
            auto up = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            auto low = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            res += (up - low);
        }
        return res;
    }
};