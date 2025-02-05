class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.size() != s2.size()) return false;
        if(s1 == s2) return true;
        vector<int> indexes;
        for(int i = 0;i<s1.size();i++){
            if(s1[i] != s2[i]){
                indexes.push_back(i);
            }
        }

        if(indexes.size() != 2) return false;
        swap(s2[indexes[0]],s2[indexes[1]]);
        return s1 == s2;
    }
};