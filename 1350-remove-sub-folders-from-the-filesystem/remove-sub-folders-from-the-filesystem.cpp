class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());

        vector<string> hs;
        hs.push_back(*folder.begin());

        int n = folder.size();
        for(int i = 1;i<n;i++){
            string last = hs.back() + '/';

            if(!folder[i].starts_with(last)){
                hs.push_back(folder[i]);
            }
        }
        return hs;
    }
};