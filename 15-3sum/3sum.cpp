class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> result;
        if(n < 3) return vector<vector<int>>();
        for(int low = 0;low<n;low++){

            int high = low + 1;
            int superHigh = n-1;
            while(high < superHigh){
                int current = nums[low] + nums[high] + nums[superHigh];
                if(current == 0){
                    result.insert({nums[low],nums[high],nums[superHigh]});
                    high++;
                }else if(current < 0){
                    high++;
                }else{
                    superHigh--;
                }
            }
        }
        return vector<vector<int>>(result.begin(),result.end());
    }
};