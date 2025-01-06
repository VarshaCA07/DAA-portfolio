#include <iostream>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

// Binary Search Tree Node
struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// AVL Tree Node
struct AVLNode {
    int data;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) : data(val), left(nullptr), right(nullptr), height(1) {}
};

// Graph Representation (Adjacency List)
class Graph {
    int V;
    vector<vector<int>> adj;
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graph
    }
    void BFS(int start);
