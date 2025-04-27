class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        for(int i = 0;i<n;i++){
            if(st.empty()){
                st.push(asteroids[i]);
            }else{
                bool possible = true;
                while(!st.empty() && st.top() >= 0 && asteroids[i] < 0){
                    int existOne = abs(st.top());
                    int newOne = abs(asteroids[i]);
                    if(existOne == newOne){
                        st.pop();
                        possible = false;
                        break;
                    }else if(newOne > existOne){
                        st.pop();
                    }else{
                        possible = false;
                        break;
                    }
                }
                if(possible){
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};