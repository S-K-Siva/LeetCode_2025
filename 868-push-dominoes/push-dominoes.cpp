class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string s = "L" + dominoes + "R";
        int p = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '.') continue;
            if (s[p] == s[i]) {
                for (int k = p + 1; k < i; ++k) s[k] = s[i];
            } else if (s[p] == 'R' && s[i] == 'L') {
                int l = p + 1, r = i - 1;
                while (l < r) {
                    s[l++] = 'R';
                    s[r--] = 'L';
                }
            }
            p = i;
        }
        return s.substr(1, n);
    }
};