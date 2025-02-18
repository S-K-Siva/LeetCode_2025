class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(isdigit(s[i])){
                if(!st.empty()&&!isdigit(st.top())){
                    st.pop();
                }
            }else{
                st.push(s[i]);
            }
        }

        string res = "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};