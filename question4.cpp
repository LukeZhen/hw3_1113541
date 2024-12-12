#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int to, weight;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

struct Node {
    int vertex, weight;
    Node(int vertex, int weight) : vertex(vertex), weight(weight) {}
    bool operator<(const Node& other) const {
        return weight > other.weight;
    }
};

int findMSTWeight(int V, vector<vector<Edge>>& adj) {
    vector<bool> visited(V, false);
    priority_queue<Node> pq;
    pq.push(Node(0, 0)); // Start from vertex 0 with weight 0

    int mstWeight = 0;

    while (!pq.empty()) {
        Node curr = pq.top();
        pq.pop();

        if (visited[curr.vertex]) continue;
        visited[curr.vertex] = true;
        mstWeight += curr.weight;

        for (Edge& edge : adj[curr.vertex]) {
            if (!visited[edge.to]) {
                pq.push(Node(edge.to, edge.weight));
            }
        }
    }

    return mstWeight;
}

int main() {
    int V = 3, E = 3;
    vector<vector<Edge>> adj = {
        {{1, 5}},
        {{0, 5}, {2, 3}},
        {{0, 1}, {1, 3}}
    };

    int mstWeight = findMSTWeight(V, adj);
    cout << mstWeight << endl;

    return 0;
}