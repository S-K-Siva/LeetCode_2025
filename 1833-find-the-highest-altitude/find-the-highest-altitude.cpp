class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = INT_MIN;
        int prefixSum = 0;
        int n = gain.size();
        for(int i = 0;i<n;i++){
            prefixSum = prefixSum + gain[i];
            result = max(result, prefixSum);
        }
        return max(0,result);
    }
};