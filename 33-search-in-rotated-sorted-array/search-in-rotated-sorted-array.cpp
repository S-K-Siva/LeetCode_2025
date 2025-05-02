class Solution {
public:
    int search(vector<int>& nums, int target) {
        unordered_map<int,int> vals;
        int left = 0, right = nums.size()-1;
        while(left <= right){
            if(left == right){
                vals[nums[left]] = left;
                break;
            }
            vals[nums[left]] = left;
            vals[nums[right]] = right;
            left++;
            right--;
        }
        if(vals.find(target) == vals.end()) return -1;
        return vals[target];
    }
};