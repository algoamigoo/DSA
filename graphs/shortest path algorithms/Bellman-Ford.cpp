vector<int> bellmanFord(int n, vector<vector<int>>& edges, int start) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] =

 dist[u] + weight;
            }
        }
    }
    return dist;
}

Used with negative weights also.
Able to find whether graph has negative cycle
Not preferred over Dijkstra as time complexity of bellman ford is O(VE)
Implemented Bellman ford for this problem to see its working code. https://leetcode.com/problems/network-delay-time
Run this algo one more time if a negative cycle check is required. If the shortest distance of a vertex is reduced, then the graph has a negative cycle.