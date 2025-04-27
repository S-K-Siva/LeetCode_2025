class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(auto it : arr){
            ++freq[it];
        }
        set<int> Set;
        for(auto it : freq){
            Set.insert(it.second);
        }
        return freq.size() == Set.size();
    }
};