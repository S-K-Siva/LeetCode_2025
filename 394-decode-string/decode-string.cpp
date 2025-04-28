class Solution {
public:
    string decodeString(string s) {
        stack<char> st;

        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(s[i] == ']') {
                string sub = "";
                while(!st.empty() && st.top() != '[') {
                    sub = st.top() + sub;
                    st.pop();
                }
                st.pop();
                
            
                string numberStr = "";
                while(!st.empty() && isdigit(st.top())) {
                    numberStr = st.top() + numberStr;
                    st.pop();
                }
                int number = stoi(numberStr);
                
                
                string newString = "";
                for(int i = 0; i < number; i++) {
                    newString += sub;
                }
                for(int i = 0; i < newString.size(); i++) {
                    st.push(newString[i]);
                }
            } else {
                st.push(s[i]);
            }
        }
        
        string result = "";
        while(!st.empty()) {
            result = st.top() + result;
            st.pop();
        }
        return result;
    }
};
