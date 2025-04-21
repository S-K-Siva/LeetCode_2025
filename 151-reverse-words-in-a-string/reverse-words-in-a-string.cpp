class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        stack<string> st;
        string word = "";
        for(int i = 0;i<n;i++){
            if(s[i] == ' '){
                if(word.empty()) continue;
                st.push(word);
                word = "";
            }else{
                word += s[i];
            }
        }
        if(!word.empty())
            st.push(word);
        string res = "";
        while(!st.empty()){
            res += st. top();
            st.pop();
            if(!st.empty())
                res += " ";
            
        }
        return res;
    }
};