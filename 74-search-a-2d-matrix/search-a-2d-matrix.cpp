class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr = matrix[0];
        for(int i=1;i<matrix.size();i++){
            arr.insert(arr.end(),matrix[i].begin(),matrix[i].end());
        }

        int low = 0;
        int high = arr.size()-1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(arr[mid] == target) return true;
            if(arr[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        
        return false;
    }
};