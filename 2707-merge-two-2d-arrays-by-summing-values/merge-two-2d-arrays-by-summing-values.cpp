class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> track;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        for(auto it : nums1){
            if(track.find(it[0]) != track.end()){
                track[it[0]] += it[1];
            }else{
                track[it[0]] = it[1];
            }
        }

        vector<vector<int>> result;
        for(auto it : track){
            result.push_back({it.first,it.second});
        }
        return result;
    }
};