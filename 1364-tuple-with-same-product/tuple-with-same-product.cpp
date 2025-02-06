class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) {
                int value = nums[i] * nums[j];
                res += 8 * mpp[value];
                mpp[value]++;
            }
        return res;
    }
};