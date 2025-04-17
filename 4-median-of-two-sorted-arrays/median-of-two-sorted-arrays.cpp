class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2 == 1){
            return (double) nums1[nums1.size()/2];
        }
        int val = nums1.size()/2;
        return (double) (nums1[val] + nums1[val-1])/2;
    }
};