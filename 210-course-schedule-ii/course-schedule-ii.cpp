class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()){
            vector<int> res;
            for(int i = numCourses-1;i>=0;i--){
                res.push_back(i);
            }
            return res;
        }
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indeg(numCourses,0);
        for(auto it : prerequisites){
            int ai = it[0];
            int bi = it[1];

            adj[bi].push_back(ai);
            ++indeg[ai];
        }

        queue<int> que;
        for(int i = 0;i<numCourses;i++){
            if(indeg[i]==0){
                que.push(i);
            }
        }
        vector<int> res;
        while(!que.empty()){
            int current = que.front();
            res.push_back(current);
            que.pop();

            for(auto neigh : adj[current]){
                --indeg[neigh];
                if(indeg[neigh] == 0){
                    que.push(neigh);
                }
            }
        }
       
  
        return res.size() == numCourses ? res : vector<int>();
    }
};