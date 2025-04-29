class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_el = *max_element(nums.begin(),nums.end());
        int n = nums.size();
        long long res = 0;
        int cnt = 0;

        int i = 0;
        int j = 0;
        while(j < n){
            if(nums[j] == max_el)
                cnt++;
            

            while(i<=j && cnt >= k){
                res += (n-j);
                if(nums[i] == max_el) cnt--;
                i++;
            }
            j++;
        }

        return res;
    }
};