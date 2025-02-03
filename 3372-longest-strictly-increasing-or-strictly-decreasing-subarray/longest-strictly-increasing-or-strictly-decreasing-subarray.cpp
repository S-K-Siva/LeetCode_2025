class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return n;
        int front = 0;
        int rear = 1;
        int res = 0;
        while(front < rear && rear < n){
            int cnt = 1;
            while(rear < n && nums[front] < nums[rear]){
                front++;
                rear++;
                cnt++;
            }
            res = max(res,cnt);
            front++;
            rear++;
        }
        front = 0;
        rear = 1;
        while(front < rear && rear < n && front < n){
            int cnt = 1;
            while(rear < n && nums[front] > nums[rear]){
                front++;
                rear++;
                cnt++;
            }
            res = max(res,cnt);
            front++;
            rear++;
        }

        return res;
    }
};