class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int lp = 0;
        int res = 0;
        int zeros= 0;
        int n = nums.size();
        for(int rp = 0;rp<n;rp++){
            if(nums[rp] == 0){
                ++zeros;
            }
            while(zeros > 1){
                if(nums[lp] == 0){
                    --zeros;
                }
                ++lp;
            }
            res = max(res, rp - lp);
        }
        return res;
    }
};