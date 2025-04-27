class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        int cnt = 0;
        for(int i = 2;i<nums.size();i++){
            if((double)nums[i]+nums[i-2] == (double)nums[i-1]/2) cnt++;
        }
        return cnt;
    }
};