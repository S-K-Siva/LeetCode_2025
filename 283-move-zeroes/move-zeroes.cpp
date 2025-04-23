class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int numIndex = 0;

        while(index < n && numIndex < n){
            while(numIndex< n && nums[numIndex] == 0){
                numIndex++;
            }
            if(numIndex < n && index < n){
                swap(nums[numIndex],nums[index]);
                index++;
                numIndex++;
            }
        }
    }
};