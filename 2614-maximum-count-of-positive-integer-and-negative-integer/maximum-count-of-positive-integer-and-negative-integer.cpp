class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int posCnt = 0;
        int negCnt = 0;
        for(auto it : nums){
            if(it == 0) continue;
            else if(it > 0) posCnt++;
            else negCnt++;
        }
        return max(posCnt,negCnt);
    }
};