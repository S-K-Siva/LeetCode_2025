class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 0LL;
        long long totalPairs = 1LL * n * (n - 1) / 2;
        long long result = 0;
        unordered_map<int,int> track;
        // [nums[i]-i] ~ finding good pairs
        // bad pairs = total pairs - good pairs
        for(int i = 0;i<n;i++){

            if(track.count(nums[i]-i)){
                result += track[nums[i]-i];
            }

            ++track[nums[i]-i];
        }

        return (long long ) totalPairs - result;
    }
};