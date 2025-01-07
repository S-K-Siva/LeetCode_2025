class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        // sort(words.begin(),words.end(),[&](string s1, string s2){
        //     return s1.size() > s2.size();
        // });
        set<string> result;
        int n = words.size();
        
        for(int i = 0;i<n;i++){
            string curr = words[i];
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                string compString = words[j];
                if(compString.find(curr) != string::npos){
                    result.insert(curr);
                }
            }
        }

        return vector<string>(result.begin(),result.end());
    }
};