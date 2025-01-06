#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Node structure for Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Binary Search Tree (BST) insertion
Node* insertBST(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);
    
    if (value < root->data)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);
    
    return root;
}

// Binary Tree Inorder Traversal
void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Graph Representation (Adjacency List)
class Graph {
    unordered_map<int, vector<int>> adjList;
public:
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // for undirected graph
    }

    void BFS(int start) {
        unordered_map<int, bool> visited;
        queue<int> q;
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
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
        cout << "2. BFS Graph Traversal\n";
        cout << "3. Brute Force String Matching\n";
        cout << "4. Exit\n";
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
                cout << "\nEnter the edges (u v):\n";
                for (int i = 0; i < edges; i++) {
                    int u, v;
                    cin >> u >> v;
                    g.addEdge(u, v);
                }

                cout << "\nEnter the starting node for BFS: ";
                int startNode;
                cin >> startNode;
                cout << "BFS Traversal: ";
                g.BFS(startNode);
                cout << endl;
                break;
            }
            case 3: {
                cout << "\nEnter the text: ";
                string text, pattern;
                cin >> text;
                cout << "Enter the pattern to search: ";
                cin >> pattern;
                bruteForceStringMatching(text, pattern);
                break;
            }
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 4);
}

int main() {
    menu();
    return 0;
}
