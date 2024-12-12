#include <iostream>
#include <vector>
using namespace std;

// Function to perform DFS traversal
void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &dfsResult) {
    visited[node] = true;
    dfsResult.push_back(node);

    // Traverse all neighbors of the current node
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, dfsResult);
        }
    }
}

vector<int> dfsTraversal(int V, vector<vector<int>> &adj) {
    vector<int> dfsResult;
    vector<bool> visited(V, false);

    // Start DFS from vertex 0
    dfs(0, adj, visited, dfsResult);

    return dfsResult;
}

int main() {
    // New example graph
    int V = 6; // Number of vertices
    vector<vector<int>> adj = {
        {1, 2},    // Adjacency list for vertex 0
        {0, 3, 4}, // Adjacency list for vertex 1
        {0, 5},    // Adjacency list for vertex 2
        {1},       // Adjacency list for vertex 3
        {1},       // Adjacency list for vertex 4
        {2}        // Adjacency list for vertex 5
    };

    vector<int> result = dfsTraversal(V, adj);

    // Print the DFS traversal
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
