class Solution {
public:
    bool canAssign(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> availableWorkers(workers.end() - k, workers.end());
        int i = k - 1;
        int usedPills = 0;

        while (i >= 0) {
            auto it = availableWorkers.lower_bound(tasks[i]);
            if (it != availableWorkers.end()) {
                availableWorkers.erase(it);
            } else {
                auto it2 = availableWorkers.lower_bound(tasks[i] - strength);
                if (it2 == availableWorkers.end()) return false;
                availableWorkers.erase(it2);
                usedPills++;
                if (usedPills > pills) return false;
            }
            i--;
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());

        int left = 0, right = min(tasks.size(), workers.size()), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (canAssign(mid, tasks, workers, pills, strength)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
