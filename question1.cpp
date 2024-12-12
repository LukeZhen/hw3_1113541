#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to create an adjacency list
vector<vector<int>> createAdjacencyList(int V, vector<pair<int, int>> &edges) {
    // Initialize an empty adjacency list
    vector<vector<int>> adjacencyList(V);

    // Populate the adjacency list
    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;

        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u); // Since the graph is undirected
    }

    // Optional: Sort the neighbors for consistency
    for (auto &neighbors : adjacencyList) {
        sort(neighbors.begin(), neighbors.end());
    }

    return adjacencyList;
}

int main() {
    int V = 6;
    vector<pair<int, int>> edges = {
        {0, 2}, {0, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {3, 5}
    };

    // Generate the adjacency list
    vector<vector<int>> adjacencyList = createAdjacencyList(V, edges);

    // Print the adjacency list
    for (int i = 0; i < adjacencyList.size(); ++i) {
        cout << i << ": ";
        for (int neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
