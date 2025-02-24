vector<vector<int>> floydWarshall(int n, vector<vector<int>>& graph) {
    vector<vector<int>> dist = graph;

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

All Pair Shortest Path Algorithm

It prefers adjacency matrix over adjacency list
Time Complexity is O(V^3)
Run this algo one more time if a negative cycle check is required. If the shortest distance of a vertex is reduced, then the graph has a negative cycle.