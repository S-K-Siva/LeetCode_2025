class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto num : nums){
            string val = to_string(num);
            if(val.size()%2 == 0) cnt++;
        }
        return cnt;
    }
};