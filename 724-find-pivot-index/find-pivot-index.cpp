class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n= nums.size();
        if(n == 1) return 0;
        vector<int> left(n,0), right(n,0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            left[i] += left[i-1] + nums[i];
        }
        for(int i = n-2;i>-1;i--){
            right[i] += right[i+1]+nums[i];
        }
        for(int i = 0;i<n;i++){
            if(i == 0&& i+1 < n && right[i+1] == 0) return i;
            if(i>0 && i<n-1 && left[i-1] == right[i+1]) return i;
            if(i == n-1 && left[n-2] == 0) return i;
        }
        return -1;
    }
};