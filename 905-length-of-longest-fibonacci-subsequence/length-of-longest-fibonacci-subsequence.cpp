//ref
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        if (arr.size() <= 2) return 0;

        int n = arr.size();
        unordered_map<int, int> track;
        for (int i = 0; i < n; i++) {
            track[arr[i]] = i;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int one = arr[j];
                int two = arr[i];
                int len = 2;
                while (track.find(one + two) != track.end()) {
                    len++;
                    res = max(res, len);
                    int x = one;
                    one = one + two;
                    two = x;
                }
            }
        }

        return res > 2 ? res : 0;
    }
};