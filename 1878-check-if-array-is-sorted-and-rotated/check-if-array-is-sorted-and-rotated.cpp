class Solution {
public:
    bool check(vector<int>& nums) {
        deque<int> dq(nums.begin(),nums.end());
        int n = nums.size();
        int savePoint = -1;
        for(int i = 0;i<n-1;i++){
            if(nums[i] > nums[i+1]){
                savePoint = i + 1;
                break;
            }
        }
        if(savePoint == -1) return true;
        for(int i = 0;i<savePoint;i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }
        return is_sorted(dq.begin(),dq.end());
    }
};