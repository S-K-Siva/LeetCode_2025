class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        if(nums.empty()) return 0;
        int prefixSum = nums[0];
        int result = nums[0];
        
        int n = nums.size();
        for(int i = 1;i<n;i++){
            if(nums[i] > nums[i-1]){
                prefixSum += nums[i];
            }else{
                prefixSum = nums[i];
            }
            result = max(result, prefixSum);
        }
        return result;
    }
};