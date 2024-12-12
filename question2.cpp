#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function to perform BFS traversal
vector<int> bfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> bfs;          // To store BFS traversal order
    vector<bool> visited(V, false); // To track visited nodes
    queue<int> q;             // Queue for BFS

    // Start BFS from vertex 0
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        // Traverse all neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
    return bfs;
}

int main() {
    // New example graph
    int V = 6; // Number of vertices
    vector<vector<int>> adj = {
        {1, 2},    // Adjacency list for vertex 0
        {0, 3, 4}, // Adjacency list for vertex 1
        {0, 4},    // Adjacency list for vertex 2
        {1},       // Adjacency list for vertex 3
        {1, 2, 5}, // Adjacency list for vertex 4
        {4}        // Adjacency list for vertex 5
    };

    vector<int> result = bfsTraversal(V, adj);

    // Print the BFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
