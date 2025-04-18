class Solution {
public:
    string countAndSay(int n) {
        string curr = "1";
        if (n == 1) return curr;
        for (int i = 2; i <= n; i++) {
            string next = "";
            int cnt = 1;
            char current = curr[0];
            for (int j = 1; j < curr.size(); j++) {
                if (curr[j] == current) {
                    cnt++;
                } else {
                    next += to_string(cnt) + current;
                    current = curr[j];
                    cnt = 1;
                }
            }
            next += to_string(cnt) + current;
            curr = next;
        }
        return curr;
    }
};