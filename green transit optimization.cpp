#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cmath>
#include <map>
#include <algorithm>
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

// Graph (Adjacency List)
class Graph {
    int V;
    vector<vector<pair<int, int>>> adj; // {node, weight}
public:
    Graph(int vertices) : V(vertices), adj(vertices) {}
    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // For undirected graphs
    }
    void Dijkstra(int start);
    void BellmanFord(int start);
    void BFS(int start);
    void DFSUtil(int node, vector<bool>& visited);
    void DFS(int start);
};

// Function Prototypes
BSTNode* insertBST(BSTNode* root, int val);
void inorderBST(BSTNode* root);
AVLNode* insertAVL(AVLNode* root, int val);
int getHeight(AVLNode* node);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
int getBalance(AVLNode* node);
void inorderAVL(AVLNode* root);
void graphMenu();

int main() {
    int choice;
    do {
        c
