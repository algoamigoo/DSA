vector<int> topoSort(int N, vector<int> adj[])
{
    queue<int> que;
    vector<int> indegree(N, 0);

    // 1
    for (int u = 0; u < N; u++)
    {
        for (int &v : adj[u])
        {
            indegree[v]++;
        }
    }

    // 2. Fill que, indegree with 0
    for (int i = 0; i < N; i++)
    {
        if (indegree[i] == 0)
        {
            que.push(i);
        }
    }

    // 3. Simple BFS
    vector<int> result;
    while (!que.empty())
    {
        int u = que.front();
        result.push_back(u);
        que.pop();

        for (int &v : adj[u])
        {
            indegree[v]--;

            if (indegree[v] == 0)
            {
                que.push(v);
            }
        }
    }

    return result;
}

// Topological Sort is an algorithm used to order the vertices of a Directed Acyclic Graph (DAG) in such a way that for every directed edge u -> v, vertex u comes before vertex v in the ordering. In simpler terms, it's a way of organizing tasks such that dependencies are respected

// can be applied only to DAG 
//n a DAG, there are no cycles, so eventually, every task will get processed because there will always be some tasks with indegree 0 to start with.
// But if there's a cycle (like Task A -> Task B -> Task C -> Task A), there will never be any task with indegree 0 because each task is waiting on another task to complete. So, topological sort cannot work on graphs with cycles.