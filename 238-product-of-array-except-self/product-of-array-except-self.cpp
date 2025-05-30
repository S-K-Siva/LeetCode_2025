class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0), res(n,0);
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            left[i] = left[i-1] * nums[i];
        }
        for(int i = n-2;i>-1;i--)
        {
            right[i] = right[i+1] * nums[i];
        }

        for(int i = 0;i<n;i++){
            if(i == 0){
                res[i] = right[i+1];
            }else if(i == n-1){
                res[i] = left[i-1];
            }else{
                res[i] = right[i+1] * left[i-1];
            }
        }
        return res;

    }
};