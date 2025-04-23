class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,vector<int>> values;
        int maxSize = 1;
        for(int i = 1;i<=n;i++){
            if(i<10){
                values[i] = {i};
            }else{
                int sum = 0;
                int val = i;
                while(val != 0){
                    int rem = val % 10;
                    val /= 10;
                    sum += rem;
                }
                if(values.find(sum) == values.end()){
                    values[sum] = {i};
                }else{
                    values[sum].push_back(i);
                }
                int currSize = values[sum].size();
                maxSize = max(maxSize,currSize);
            }
        }
        int cnt = 0;
        for(auto it : values){
            if(it.second.size() == maxSize){
                ++cnt;
            }
        }
        return cnt;
    }
};