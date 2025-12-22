#include <iostream>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    int E; // Number of edges
    int** Adj; // Adjacency matrix

    // Constructor
    Graph(int vertices) : V(vertices), E(0) { // Initialize E to 0
        Adj = new int*[V];
        for (int i = 0; i < V; ++i) {
            Adj[i] = new int[V](); // Initialize to 0
        }
    }

    // Destructor
    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] Adj[i];
        }
        delete[] Adj;
    }

    // Add an edge (undirected)
    void addEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            if (Adj[u][v] == 0) { // Check if edge does not exist
                Adj[u][v] = 1;
                Adj[v][u] = 1; // For undirected graph
                E++;
            }
        } else {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
        }
    }

    // Remove an edge (undirected)
    void removeEdge(int u, int v) {
        if (u >= 0 && u < V && v >= 0 && v < V) {
            if (Adj[u][v] == 1) { // Check if edge exists
                Adj[u][v] = 0;
                Adj[v][u] = 0; // For undirected graph
                E--;
            }
        } else {
            cerr << "Invalid edge: (" << u << ", " << v << ")" << endl;
        }
    }

    // Get neighbors of a vertex
    void getNeighbors(int u, int neighbors[], int& count) const {
        count = 0;
        if (u >= 0 && u < V) {
            for (int v = 0; v < V; ++v) {
                if (Adj[u][v] == 1) {
                    neighbors[count++] = v;
                }
            }
        } else {
            cerr << "Invalid vertex: " << u << endl;
        }
    }

    // Display graph as adjacency list in a clear format
    void displayGraphAdjacencyList() const {
        cout << "Graph Adjacency List:\n";
        for (int i = 0; i < V; ++i) {
            cout << "Vertex " << i << " is connected to: ";
            bool hasNeighbors = false;
            for (int j = 0; j < V; ++j) {
                if (Adj[i][j] == 1) {
                    cout << j << " ";
                    hasNeighbors = true;
                }
            }
            if (!hasNeighbors) {
                cout << "No connections";
            }
            cout << endl;
        }
    }

    // Display graph as adjacency matrix
    void displayGraphAdjacencyMatrix() const {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                cout << Adj[i][j] << " ";
            }
            cout << endl;
        }
    }
};

// Function to create a graph from user input
Graph* createGraph() {
    int vertices, edges;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    cout << "Enter number of edges: ";
    cin >> edges;

    if (vertices <= 0 || edges < 0) {
        cerr << "Invalid number of vertices or edges." << endl;
        return nullptr;
    }

    Graph* G = new Graph(vertices);
    
    cout << "Enter vertex pairs that connect an edge:\n";
    
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        G->addEdge(u, v);
    }

    return G;
}

// Main function
int main() {
    Graph* graph = createGraph();
    
    if (graph) {
        graph->displayGraphAdjacencyMatrix(); 
        
        cout << "\nDisplaying graph as adjacency list:\n";
        graph->displayGraphAdjacencyList();

        int vertexToCheck = 1;
        int neighbors[10]; 
        int neighborCount = 0;

        graph->getNeighbors(vertexToCheck, neighbors, neighborCount);
        
        cout << "\nNeighbors of vertex " << vertexToCheck << ": ";
        
        for (int i = 0; i < neighborCount; ++i) {
            cout << neighbors[i] << " ";
        }
        
        cout << endl;

        graph->removeEdge(1, 2);
        
        cout << "\nAfter removing edge (1,2):\n";
        graph->displayGraphAdjacencyMatrix();

        delete graph;
    } else {
        cerr << "Failed to create graph." << endl;
    }

    return 0;
}
