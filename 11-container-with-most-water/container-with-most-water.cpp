class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = 0;
        int n = height.size();
        int left = 0;
        int right = n-1;

        while(left < right){
            // w * h
            int area = (right-left) * min(height[left],height[right]);
            res = max(res,area);

            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};