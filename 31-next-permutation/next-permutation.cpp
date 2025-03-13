class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1;
        int right = -1;
        int n = nums.size();
        for(int i = n-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                left = i;
                break;
            }
        }
        if(left == -1){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i = n-1;i>=0 && i > left;i--){
            if(nums[i] > nums[left]){
                right = i;
                break;
            }
        }

        swap(nums[left],nums[right]);
        reverse(nums.begin()+left+1,nums.end());
        
    }
};