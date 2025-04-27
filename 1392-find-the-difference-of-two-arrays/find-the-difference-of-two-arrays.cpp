class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        set<int> res1, res2;
        for(auto it : nums1){
            if(s2.count(it)) continue;
            res1.insert(it);
        }
        for(auto it : nums2){
            if(s1.count(it)) continue;
            res2.insert(it);
        }
        return {vector<int>(res1.begin(),res1.end()), vector<int>(res2.begin(),res2.end())};
    }
};