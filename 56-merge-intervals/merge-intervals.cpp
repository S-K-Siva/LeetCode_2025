class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        for(int i = 0;i<n;i++){
            if(res.empty()){
                res.push_back(intervals[i]);
            }else if(!res.empty()){
                vector<int> current = res.back();
                if(current[1] < intervals[i][0]){
                    res.push_back(intervals[i]);
                }else{
                    res.pop_back();
                    current[1] = max(current[1],intervals[i][1]);
                    res.push_back(current);
                }
            }
        }
        return res;
    }
};