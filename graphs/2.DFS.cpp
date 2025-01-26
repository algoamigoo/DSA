
     void dfs(int node,vector<vector<int>>adj,vector<bool> &vis,vector<int> &ans){
         vis[node]=true;
         ans.push_back(node);
         for(auto it : adj[node]){
             if(!vis[it]){
                 dfs(it,adj,vis,ans);
             }
         }
     }

    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        int start=0;
        vector<int> ans;
        dfs(start,adj,vis,ans);
        return ans;
    }
