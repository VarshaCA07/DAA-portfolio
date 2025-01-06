#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

// AVL Tree Node
struct AVLNode {
    int value;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int val) : value(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree Function Prototypes
int getHeight(AVLNode* node);
int getBalanceFactor(AVLNode* node);
AVLNode* rotateRight(AVLNode* y);
AVLNode* rotateLeft(AVLNode* x);
AVLNode* insertAVL(AVLNode* root, int value);
void inOrderTraversal(AVLNode* root);

// Graph Function Prototypes (Dijkstra's Algorithm)
void dijkstra(int vertices, vector<vector<pair<int, int>>>& graph, int start);

// Menu-Driven Program
int main() {
    int choice;
    do {
        cout << "\n*** Data Structure and Algorithm Menu ***\n";
        cout << "1. AVL Tree (Insert & In-Order Traversal)\n";
        cout << "2. Dijkstra's Algorithm (Shortest Path in Weighted Graph)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                AVLNode* root = nullptr;
                int n, value;
                cout << "Enter the number of elements to insert into AVL Tree: ";
                cin >> n;
                cout << "Enter the elements:\n";
                for (int i = 0; i < n; ++i) {
                    cin >> value;
                    root = insertAVL(root, value);
                }
                cout << "In-Order Traversal of the AVL Tree:\n";
                inOrderTraversal(root);
                cout << endl;
                break;
            }
            case 2: {
                int vertices, edges;
                cout << "Enter the number of vertices and edges in the graph: ";
                cin >> vertices >> edges;
                vector<vector<pair<int, int>>> graph(vertices);
                cout << "Enter the edges (u v weight) (0-based indexing):\n";
                for (int i = 0; i < edges; ++i) {
                    int u, v, weight;
                    cin >> u >> v >> weight;
                    graph[u].emplace_back(v, weight);
                    graph[v].emplace_back(u, weight); // For undirected graph
                }
                int start;
                cout << "Enter the starting vertex: ";
                cin >> start;
                dijkstra(vertices, graph, start);
                break;
            }
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}

// AVL Tree Functions
int getHeight(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

AVLNode* insertAVL(AVLNode* root, int value) {
    if (!root) return new AVLNode(value);

    if (value < root->value)
        root->left = insertAVL(root->left, value);
    else if (value > root->value)
        root->right = insertAVL(root->right, value);
    else
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalanceFactor(root);

    if (balance > 1 && value < root->left->value)
        return rotateRight(root);
    if (balance < -1 && value > root->right->value)
        return rotateLeft(root);
    if (balance > 1 && value > root->left->value) {
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }
    if (balance < -1 && value < root->right->value) {
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void inOrderTraversal(AVLNode* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Dijkstra's Algorithm Function
void dijkstra(int vertices, vector<vector<pair<int, int>>>& graph, int start) {
    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortes

