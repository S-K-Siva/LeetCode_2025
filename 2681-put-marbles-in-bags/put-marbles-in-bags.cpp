class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        if(k >= n) return 0;

        vector<int>con;
        for(int i = 0 ; i < n-1 ; ++i){
            con.push_back(weights[i]+weights[i+1]);
        }

        sort(con.begin(),con.end());
        
        long long mini = 0;
        long long maxi = 0;

        for(int i = 0 ; i < k-1 ; ++i){
            mini += con[i];
            maxi += con[n-2-i];
        }
        return maxi-mini;
    }
};