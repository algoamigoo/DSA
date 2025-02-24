
vector<int> dijkstra(int n, vector<vector<int>> adj[], int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto& ngbr : adj[node]) {
            int adjNode = ngbr[0];
            int wt = ngbr.[1];

            if (dis + wt < dist[node]) {
                 dist[node]= dis + wt;
                pq.push({dist[v], adjnode});
            }
        }
    }
    return dist;
}

Used only if weights are non-negative
Similar to BFS but has below difference
Used Priority Queue with Integer Array instead of Queue with Integer
Used Distance array instead of boolean visited array.
Time Complexity is O(Elog E) -> O(Elog V^2) -> O(E*2 log v) -> O(ElogV)