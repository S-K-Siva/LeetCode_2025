class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> indeg(numCourses,0);
        for(auto it : prerequisites){
            int ai = it[0];
            int bi = it[1];

            adj[ai].push_back(bi);
            ++indeg[bi];
        }

        queue<int> que;
        for(int i = 0;i<numCourses;i++){
            if(indeg[i]==0){
                que.push(i);
            }
        }
        int cnt = 0;
        while(!que.empty()){
            int current = que.front();
            ++cnt;
            que.pop();

            for(auto neigh : adj[current]){
                --indeg[neigh];
                if(indeg[neigh] == 0){
                    que.push(neigh);
                }
            }
        }
        return cnt == numCourses;
    }
};