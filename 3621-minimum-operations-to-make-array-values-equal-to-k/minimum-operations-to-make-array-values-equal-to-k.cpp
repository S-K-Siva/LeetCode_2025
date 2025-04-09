class Solution {
    public:
    int minOperations(vector<int>& nums, int k) {
        set<int> ss;
        for (int i : nums) 
            if (i < k) return -1;
            else if (i > k) ss.insert(i);
        return ss.size();
    }
};