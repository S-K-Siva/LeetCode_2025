class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> track;
        vector<int> even,odd;
        for(auto ch : s){
            ++track[ch];
        }
        for(auto it : track){
            if(it.second % 2 == 0){
                even.push_back(it.second);
            }else{
                odd.push_back(it.second);
            }
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        return odd.back() - even.front();
        
    }
};