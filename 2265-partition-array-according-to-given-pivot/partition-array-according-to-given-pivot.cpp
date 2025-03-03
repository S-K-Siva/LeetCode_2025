class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> result(nums.size(), 0);
        int left = 0, right = nums.size() - 1;
        int i = 0;
        int j = nums.size() - 1;
        while (i < nums.size()) {
            if (nums[i] < pivot) {
                result[left] = nums[i];
                left++;
            }
            
            if (nums[j] > pivot) {
                result[right] = nums[j];
                right--;
            }
            ++i;
            --j;
        }
        
        while (left <= right) {
            result[left] = pivot;
            left++;
        }
        
        return result;
    }
};