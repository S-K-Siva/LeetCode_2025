class Solution {
public:

    int findParent(int node, vector<int>& parent){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node],parent);
    }

    void unionByRank(int u, int v, vector<int>&rank, vector<int>& parent){
        int ultimateParentOfU = findParent(u,parent);
        int ultimateParentOfV = findParent(v,parent);

        if(ultimateParentOfV == ultimateParentOfU) return; // cycle

        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        }else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        }else{
            parent[ultimateParentOfV] = ultimateParentOfU;
            rank[ultimateParentOfV]++;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> parent(n),rank(n);
        for(int i = 0;i<n;i++){
            parent[i] = i;
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(isConnected[i][j]){
                    unionByRank(i,j,rank,parent);
                }
            }
        }
        set<int> ss;
        for(int i = 0;i<n;i++){
            ss.insert(findParent(i,parent));
        }
        return ss.size();
    }
};