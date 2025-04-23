class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int pairsCnt = 0;
        unordered_map<int, int> freq;

        for (int num : nums) {
            int complement = k - num;

            if (freq[complement] > 0) {
                pairsCnt++;
                freq[complement]--;
            } else {
                freq[num]++;
            }
        }
        return pairsCnt;
    }
};
