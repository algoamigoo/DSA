
bool isCycle(vector<vector<int>>& adj) {
    int V = adj.size();
    vector<bool> vis(V, false);

    for (int start = 0; start < V; ++start) {
        if (!vis[start]) {
            queue<pair<int, int>> q;
            q.push({start, -1});
            vis[start] = true;

            while (!q.empty()) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (int neighbor : adj[node]) {
                    if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, node});
                    } 
                    else if (neighbor != parent)
                    return true;
                }
            }
        }
    }
    return false;
}