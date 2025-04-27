class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int res = 0;
        int lp = 0;
        int n= nums.size();
        int zerosCnt = 0;
        for(int rp = 0;rp <n;rp++){
            if(nums[rp] == 0){
                ++zerosCnt;
            }
            while(zerosCnt > k){
                if(nums[lp] == 0){
                    --zerosCnt;
                }
                ++lp;
            }
            res = max(res, rp - lp + 1);
        }
        return res;
    }
};