class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> result;
        for(int i =  0;i<matrix.size();i++){
            result.insert(result.end(), matrix[i].begin(), matrix[i].end());
        }
        sort(result.begin(),result.end());
        return result[k-1];
    }
};