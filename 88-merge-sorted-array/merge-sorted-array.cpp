class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = nums2.size();
        while(!nums1.empty() && nums1.back() == 0 && size--){
            nums1.pop_back();
        }
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
    }
};