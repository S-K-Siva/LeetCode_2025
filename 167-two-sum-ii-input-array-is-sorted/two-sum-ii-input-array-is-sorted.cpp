class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            int current = numbers[left] + numbers[right];
            if(current == target){
                return {left+1,right+1};
            }else if(current < target){
                left++;
            }else{
                right--;
            }
        }
        return {-1};
    }
};