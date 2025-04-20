class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // wrg - (16/56)
        // set<int> st(answers.begin(),answers.end());
        // int n = answers.size();
        // int value = accumulate(st.begin(),st.end(),0);
        // return st.size() + value;
    
        unordered_map <int,int> mpp;
        for (int i : answers) mpp[i]++;
        int total = 0;
        for (auto& p : mpp)
            total += ceil((double)p.second / (p.first + 1)) * (p.first + 1);
        return total;
    }
};
