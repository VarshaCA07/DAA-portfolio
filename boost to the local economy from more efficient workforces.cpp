#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <limits.h>
#include <string>
#include <algorithm>

using namespace std;

// Node structure for Binary Search Tree (BST)
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) Insertion
Node* insertBST(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);
    
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);
    
    return root;
}

// Inorder Traversal of BST
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Graph Representation (Adjacency List) for BFS and Dijkstra
class Graph {
    unordered_map<int, vector<pair<int, int>>> adjList; // (Node, Weight)

public:
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // for undirected graph
    }

    // BFS Traversal
    void BFS(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (auto neighbor : adjList[node]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    // Dijkstra's Shortest Path Algorithm
    void Dijkstra(int start) {
        unordered_map<int, int> dist;
        for (auto& node : adjList) {
            dist[node.first] = INT_MAX;
        }
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first, weight = neighbor.second;
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        cout << "Shortest paths from node " << start << ":\n";
        for (auto& d : dist) {
            cout << "Node " << d.first << ": " << d.second << endl;
        }
    }
};

// Brute Force String Matching Algorithm
void bruteForceStringMatching(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
            j++;

        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

// Menu-driven Program
void menu() {
    int choice;
    Node* root = nullptr;
    Graph g;

    do {
        cout << "\nMenu:\n";
        cout << "1. Binary Search Tree (BST) Operations\n";
        cout << "2. Graph Traversal (BFS)\n";
        cout << "3. Dijkstra's Shortest Path Algorithm\n";
        cout << "4. Brute Force String Matching\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter value to insert in BST: ";
                int value;
                cin >> value;
                root = insertBST(root, value);
                cout << "Inorder Traversal of BST: ";
                inorderTraversal(root);
                cout << endl;
                break;
            }
            case 2: {
                cout << "\nEnter number of edges: ";
                int edges;
                cin >> edges;
                cout << "\nEnter the edges (u v weight):\n";
                for (int i = 0; i < edges; i++) {
                    int u, v, weight;
                    cin >> u >> v >> weight;
                    g.addEdge(u, v, weight);
                }

                cout << "\nEnter the starting node for BFS: ";
                int startNode;
                cin >> startNode;
                cout << "BFS Traversal: ";
                g.BFS(startNode);
                break;
            }
            case 3: {
                cout << "\nEnter number of edges: ";
                int edges;
                cin >> edges;
                cout << "\nEnter the edges (u v weight):\n";
                for (int i = 0; i < edges; i++) {
                    int u, v, weight;
                    cin >> u >> v >> weight;
                    g.addEdge(u, v, weight);
                }

                cout << "\nEnter the starting node for Dijkstra: ";
                int startNode;
                cin >> startNode;
                g.Dijkstra(startNode);
                break;
            }
            case 4: {
                cout << "\nEnter the text: ";
                string text, pattern;
                cin >> text;
                cout << "Enter the pattern to search: ";
                cin >> pattern;
                bruteForceStringMatching(text, pattern);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}

