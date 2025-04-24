class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int totalDistinct = unordered_set<int>(nums.begin(), nums.end()).size();
        unordered_map<int, int> freq;
        int left = 0, count = 0, n = nums.size();

        for (int right = 0; right < n; ++right) {
            freq[nums[right]]++;

            while (freq.size() == totalDistinct) {
                count += n - right; // all subarrays from [left, right] to [left, n-1] are valid
                freq[nums[left]]--;
                if (freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left++;
            }
        }
        return count;
    }
};
