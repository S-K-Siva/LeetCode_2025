class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int index = -1;  // peak mountain's index
        int element = -1; // peak mountain
        int n = arr.size();
        int left = 0; 
        int right = n - 1;

        while(left <= right){
            if(index == -1){
                if(arr[left] > arr[right]){
                    index = left;
                    element = arr[left];
                }else{
                    index = right;
                    element = arr[right];
                }
                left++;
                right--;
            }else{
                if(arr[left] > arr[index]){
                    index = left;
                    element = arr[left];
                }
                if(arr[right] > arr[index]){
                    index = right;
                    element = arr[right];
                }
                left++;
                right--;
            }
        }
        return index;
    }
};