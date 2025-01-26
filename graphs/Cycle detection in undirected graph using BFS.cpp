


void dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj, bool& hasCycle) {
    vis[node] = true;
    for (auto it : adj[node]) {
        if (!vis[it]) {
            dfs(it, node, vis, adj, hasCycle);
        } else if (it != parent) {
            hasCycle = true;
        }
    }
}
    bool isCycle(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<bool> vis(n, false);
    bool hasCycle = false;

    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, -1, vis, adj, hasCycle);
        }
    }

    return hasCycle;
    }

// A cycle occurs if you revisit a node that is not part of your direct parent-child relationship.
// Handle disconnected components by running DFS from every unvisited node.
