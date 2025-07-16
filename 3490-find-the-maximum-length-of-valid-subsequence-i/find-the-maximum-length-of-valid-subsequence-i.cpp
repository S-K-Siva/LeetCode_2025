//TLE
// class Solution {
// public:
//     void solve(int index, vector<int>& nums, int length, int& maxlen, int track, int prev) {
//         maxlen = max(maxlen, length);
//         for (int i = index; i < nums.size(); i++) {
//             if ((nums[i] + nums[prev]) % 2 == track) {
//                 solve(i + 1, nums, length + 1, maxlen, track, i);
//             }
//         }
//     }

//     int maximumLength(vector<int>& nums) {
//         int maxlen = 0;
//         int n = nums.size();

//         for (int i = 0; i < n; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 int track = (nums[i] + nums[j]) % 2;
//                 int len = 2;
//                 solve(j + 1, nums, len, maxlen, track, j);
//             }
//         }
//         return maxlen;
//     }
// };
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        for (int it : nums) {
            if (it % 2 == 0) cnt1++;
            else cnt2++;
        }

        int eve = 0, odd = 0;
        for (int it : nums) {
            if (it % 2 == 0)
                eve = max(eve, odd + 1);
            else
                odd = max(odd, eve + 1);
        }

        return max({cnt1, cnt2, eve, odd});
    }
};