#include <iostream>

using namespace std;

// Node structure for linked list
struct Node {
    int vertex;
    Node* next;
};

// Class representing a graph
class Graph {
private:
    int V; // Number of vertices
    Node** adjList; // Array of pointers to linked lists

public:
    // Constructor
    Graph(int V) {
        this->V = V;
        adjList = new Node*[V]; // Allocate memory for the adjacency list
        for (int i = 0; i < V; ++i) {
            adjList[i] = nullptr; // Initialize each list as empty
        }
    }

    // Destructor to free allocated memory
    ~Graph() {
        for (int i = 0; i < V; ++i) {
            Node* current = adjList[i];
            while (current) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList; // Free the array of pointers
    }

    // Function to add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        // Add v to u's list
        Node* newNode = new Node{v, adjList[u]};
        adjList[u] = newNode;

        // Add u to v's list (for undirected graph)
        newNode = new Node{u, adjList[v]};
        adjList[v] = newNode;
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "Adjacency list of vertex " << v << ": ";
            Node* current = adjList[v];
            while (current) {
                cout << "-> " << current->vertex;
                current = current->next;
            }
            cout << endl;
        }
    }
};

// Main function
int main() {
    Graph gh(5); // Create a graph with 5 vertices

    // Adding edges
    gh.addEdge(0, 1);
    gh.addEdge(0, 4);
    gh.addEdge(1, 2);
    gh.addEdge(1, 3);
    gh.addEdge(1, 4);
    gh.addEdge(2, 3);
    gh.addEdge(3, 4);

    // Print the adjacency list representation of the above graph
    gh.printGraph();

    return 0;
}
