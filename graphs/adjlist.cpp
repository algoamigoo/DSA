
vector<vector<int>> printGraph(int V, vector<pair<int, int>> &edges)
{
    vector<vector<int>> adj(V);
    vector<vector<int>> res;
    for (auto edge : edges)
    {
        int u = edge.first;
        int v = edge.second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}

// Given an undirected graph with V nodes and edges
//V = 5 and edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]