

vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<bool> vis(V, false);
        int s = 0;
        vis[s] = true;
        vector<int> res;
        queue<int> q;
        q.push(s);

        while (!q.empty()) {
            int node = q.front();
            res.push_back(node);
            q.pop();

            for (int v : adj[node]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
        return res;
}

//Extract the front vertex t from the queue.
// Add t to the result vector res.
// Loop through all neighbors (v) of t in adj[t].
// If a neighbor v has not been visited, mark it as visited (vis[v] = true) and push it into the queue.

// this will return bfs order traversal 
