class Solution {
public:
    bool divideArray(vector<int>& nums) {
        if(nums.size()%2 == 1) return false;
        unordered_map<int,int> track;
        for(auto it : nums) ++track[it];
        for(auto it : track){
            if(it.second % 2 == 1) return false;
        }
        return true;
    }
};