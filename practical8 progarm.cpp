#include <iostream>
#include <vector>
#include <queue>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        // Validation to prevent vector index out of bounds crashes
        if (u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
    }

    void DFSUtil(int v, vector<bool> &visited, vector<int> &order) {
        visited[v] = true;
        order.push_back(v); // Store order instead of printing directly

        for (int neighbor : adj[v]) {
            if (!visited[neighbor])
                DFSUtil(neighbor, visited, order);
        }
    }

    // Returns the traversal sequence vector
    vector<int> DFS(int start) {
        vector<bool> visited(V, false);
        vector<int> order;
        if (start >= 0 && start < V) {
            DFSUtil(start, visited, order);
        }
        return order;
    }

    // Returns the traversal sequence vector
    vector<int> BFS(int start) {
        vector<bool> visited(V, false);
        vector<int> order;
        
        if (start < 0 || start >= V) return order;

        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        return order;
    }
};

int main() {
    int V, E;

    cout << "Enter number of vertices: ";
    cin >> V;
    if (V <= 0) {
        cout << "Invalid vertex count.\n";
        return 1;
    }

    Graph g(V);

    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // DFS Time Analysis (Accurate algorithm benchmarking)
    auto startDFS = high_resolution_clock::now();
    vector<int> dfsResult = g.DFS(start);
    auto endDFS = high_resolution_clock::now();
    auto dfsTime = duration_cast<nanoseconds>(endDFS - startDFS);

    // BFS Time Analysis (Accurate algorithm benchmarking)
    auto startBFS = high_resolution_clock::now();
    vector<int> bfsResult = g.BFS(start);
    auto endBFS = high_resolution_clock::now();
    auto bfsTime = duration_cast<nanoseconds>(endBFS - startBFS);

    // Output Traversal results cleanly
    cout << "\nDFS Traversal: ";
    for (int node : dfsResult) cout << node << " ";

    cout << "\nBFS Traversal: ";
    for (int node : bfsResult) cout << node << " ";

    // Display execution time metrics minus I/O overhead
    cout << "\n\nExecution Time (Algorithm Only):";
    cout << "\nDFS: " << dfsTime.count() << " ns";
    cout << "\nBFS: " << bfsTime.count() << " ns\n";

    return 0;
}
