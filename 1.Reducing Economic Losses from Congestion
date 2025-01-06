#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

// Node structure for Binary Search Tree
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function prototypes
TreeNode* insertBST(TreeNode* root, int value);
void inOrderTraversal(TreeNode* root);
void bfsGraph(int vertices, vector<vector<int>>& adjList);

// Menu-driven program
int main() {
    int choice;
    do {
        cout << "\n*** Data Structure Operations Menu ***\n";
        cout << "1. Binary Search Tree (Insert & In-Order Traversal)\n";
        cout << "2. Breadth-First Search (BFS) for Graphs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                TreeNode* root = nullptr;
                int n, value;
                cout << "Enter the number of elements to insert into BST: ";
                cin >> n;
                cout << "Enter the elements:\n";
                for (int i = 0; i < n; ++i) {
                    cin >> value;
                    root = insertBST(root, value);
                }
                cout << "In-Order Traversal of the BST:\n";
                inOrderTraversal(root);
                cout << endl;
                break;
            }
            case 2: {
                int vertices, edges;
                cout << "Enter the number of vertices and edges in the graph: ";
                cin >> vertices >> edges;
                vector<vector<int>> adjList(vertices);
                cout << "Enter the edges (u v) (0-based indexing):\n";
                for (int i = 0; i < edges; ++i) {
                    int u, v;
                    cin >> u >> v;
                    adjList[u].push_back(v);
                    adjList[v].push_back(u); // For undirected graph
                }
                bfsGraph(vertices, adjList);
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

// Function to insert a value into a Binary Search Tree
TreeNode* insertBST(TreeNode* root, int value) {
    if (!root) return new TreeNode(value);
    if (value < root->value)
        root->left = insertBST(root->left, value);
    else
        root->right = insertBST(root->right, value);
    return root;
}

// In-Order Traversal of a BST
void inOrderTraversal(TreeNode* root) {
    if (!root) return;
    inOrderTraversal(root->left);
    cout << root->value << " ";
    inOrderTraversal(root->right);
}

// Function to perform BFS on a graph
void bfsGraph(int vertices, vector<vector<int>>& adjList) {
    vector<bool> visited(vertices, false);
    queue<int> q;
    cout << "Enter the starting vertex for BFS: ";
    int start;
    cin >> start;

    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}
