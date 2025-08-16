Prims Algo

Start with any vertex. Use Priority Queue to process the smallest edge.
Use visited array or distance array.
Difference between Prims and Dijkstra is “Don’t add current vertex distance to calculate neighbour distance”.
Example : u, v
Dijkstra - dis[v] = dis[u] + graph[u][v];
Prims - dis[v] = graph[u][v]
Time Complexity is O(ElogV)


int prims(int n, vector<pair<int, int>> adj[]) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int mstCost = 0;

    pq.push({0, 0}); // (cost, node)

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (inMST[u]) continue;

        mstCost += cost;
        inMST[u] = true;

        for (auto& neighbor : adj[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (!inMST[v]) {
                pq.push({weight, v});
            }
        }
    }
    return mstCost;
}
