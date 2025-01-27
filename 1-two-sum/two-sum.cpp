class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> values;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            values.push_back({nums[i],i});
        }
        sort(values.begin(),values.end());
        int left = 0;
        int right = n-1;

        while(left < right){
            int current = values[left].first + values[right].first;
            if(current == target){
                return {values[left].second, values[right].second};
            }else if(current < target){
                left++;
            }else{
                right--;
            }
        }
        return {-1};
    }
};