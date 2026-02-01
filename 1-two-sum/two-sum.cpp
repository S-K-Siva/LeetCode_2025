class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> track;

        for(int i = 0;i<nums.size();i++){
            if(track.find(target - nums[i]) != track.end()){
                return {track[target-nums[i]],i};
            }
            track[nums[i]] = i;
        }
        return {-1};
    }
};