class Solution {
public:
    int findParent(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionByRank(int u, int v, vector<int>& rank, vector<int>& parent){
        int findParentOfU = findParent(u,parent);
        int findParentOfV = findParent(v,parent);
        if(findParentOfU == findParentOfV) return;
        if(rank[findParentOfU] < rank[findParentOfV]){
            parent[findParentOfU] = findParentOfV;
        }else if(rank[findParentOfV] < rank[findParentOfU]){
            parent[findParentOfV] = findParentOfU;
        }else{
            parent[findParentOfV] = findParentOfU;
            ++rank[findParentOfV];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1,0);
        vector<int> rank(n+1,0);
        for(int i = 0;i<=n;i++){
            parent[i] = i;
        }
        int index = -1;
        int track = 0;
        for(auto edge : edges){
            int src = edge[0];
            int des = edge[1];
            if(findParent(src,parent) != findParent(des,parent)){
                unionByRank(src,des,rank,parent);
            }else{
                index = track;
            }
            ++track;
        }
        return (index == -1) ? vector<int>() : edges[index];
    }
};