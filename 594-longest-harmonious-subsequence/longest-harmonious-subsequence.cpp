class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> track;

        for(auto num : nums){
            ++track[num];
        }
        int result = 0;
        for(auto num : nums){
            if(track.find(num+1) != track.end()){
                result = max(result, track[num] + track[num+1]);
            }
        }
        return result;
    }
};