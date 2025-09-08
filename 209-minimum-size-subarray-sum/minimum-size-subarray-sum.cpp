class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = INT_MAX;
        int left = 0;
        int right = 0;
        long long int sum = 0;
        
        while(right < nums.size()){
            sum += nums[right];
            
            while(sum >= target && left <= right){
                size = min(size, right - left + 1);
                sum -= nums[left];
                ++left;
            }
            
            right++;
        }
        return size == INT_MAX ? 0 : size;
    }
};