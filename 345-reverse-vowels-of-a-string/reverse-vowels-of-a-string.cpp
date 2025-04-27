class Solution {
public:
    string reverseVowels(string s) {
        set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
        string sub = "";
        for(int i = 0;i<s.size();i++){
            if(st.count(s[i])){
                sub += s[i];
            }
        }
        reverse(sub.begin(),sub.end());
        int index = 0;
        for(int i = 0;i<s.size();i++){
            if(st.count(s[i])){
                s[i] = sub[index];
                index++;
            }
        }
        return s;
    }
};