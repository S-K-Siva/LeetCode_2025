// class Solution {
// public:
//     int countDays(int days, vector<vector<int>>& meetings) {
//         vector<int> diff(days + 2, 0);
//         for (auto& range : meetings) {
//             int start = range[0];
//             int end = range[1];
//             diff[start]++;
//             diff[end + 1]--;
//         }

//         int cnt = 0;
//         int ongoingMeetings = 0;
        
//         for (int i = 1; i <= days; i++) {
//             ongoingMeetings += diff[i];
//             if (ongoingMeetings == 0) cnt++;
//         }

//         return cnt;
//     }
// };

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;
        sort(meetings.begin(), meetings.end());

        long long busy_days = 0;
        long long start = meetings[0][0];
        long long end = meetings[0][1];

        for (int i = 1; i < meetings.size(); ++i) {
            long long curr_start = meetings[i][0];
            long long curr_end = meetings[i][1];

            if (curr_start <= end + 1) {
                // Overlapping or contiguous intervals → merge
                end = max(end, curr_end);
            } else {
                // Non-overlapping interval → count previous
                busy_days += (end - start + 1);
                start = curr_start;
                end = curr_end;
            }
        }

        // Add the last interval
        busy_days += (end - start + 1);

        // Calculate free days
        long long free_days = days - busy_days;
        return free_days;
    }
};