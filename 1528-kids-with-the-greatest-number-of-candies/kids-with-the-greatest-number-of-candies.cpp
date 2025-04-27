class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        vector<int> left(n,0),right(n,0);
        left[0] = candies[0];
        right[n-1] = candies[n-1];
        for(int i = 1;i<n;i++){
            left[i] = max(left[i-1],candies[i]);
        }
        for(int i = n-2;i>-1;i--){
            right[i] = max(right[i+1],candies[i]);
        }
        vector<bool> booleans;
        for(int i = 0;i<n;i++){
            if(i == 0){
                int current = candies[i] + extraCandies;
                if(i+1 < n && current >= right[i+1]){
                    booleans.push_back(true);
                }else{
                    booleans.push_back(false);
                }
            }else if(i == n-1){
                int current = candies[i] + extraCandies;
                if(i-1 >=0 && current >= left[i-1]){
                    booleans.push_back(true);
                }else{
                    booleans.push_back(false);
                }
            }else{
                int maxi = max(left[i-1],right[i+1]);
                int current = candies[i] + extraCandies;
                if(current >= maxi){
                    booleans.push_back(true);
                }else{
                    booleans.push_back(false);
                }
            }
        }
        return booleans;
    }
};