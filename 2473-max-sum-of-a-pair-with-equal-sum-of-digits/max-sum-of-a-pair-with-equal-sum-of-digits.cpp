class Solution {
public:
    int digitSum(int num) {
        int sum = 0;
        while (num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mpp;
        int maxSum = -1;

        for (int num : nums) {
            int sumDigits = digitSum(num);
            mpp[sumDigits].push(num);
        }

        for (auto [key, pq] : mpp) {
            if (pq.size() >= 2) {
                int first = pq.top(); pq.pop();
                int second = pq.top();
                maxSum = max(maxSum, first + second);
            }
        }

        return maxSum;
    }
};