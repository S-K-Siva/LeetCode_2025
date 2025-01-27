class Solution {
public:

    int findParent(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionByRank(int u, int v, vector<int>& rank, vector<int>& parent){
        u = findParent(u,parent);
        v = findParent(v,parent);
        if(u != v){
            if(rank[u] < rank[v]){
                parent[u] = v;
            }else if(rank[u] > rank[v]){
                parent[v] = u;
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> values;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                int distance = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                values.push_back({distance,i,j});
            }
        }

        sort(values.begin(),values.end());
        vector<int> rank(n,0),parent(n);

        for(int i= 0;i<n;i++){
            parent[i] = i;
        }
        int mstWeight = 0;

        for(auto value : values){
            int src = value[1];
            int des = value[2];
            int wt = value[0];
            if(findParent(src,parent) != findParent(des,parent)){
                mstWeight += wt;
                unionByRank(src,des,rank,parent);
            }
        }
        return mstWeight;
    }
};