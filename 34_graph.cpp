#include <iostream>
using namespace std;

class Graph {
public:
    int V;
    int E;
    int** Adj;

    Graph(int vertices,int edges):V(vertices),E(edges) {
        Adj=new int*[V];
        for(int i=0;i<V;++i) {
            Adj[i]=new int[V]();
        }
    }

    ~Graph() {
        for(int i=0;i<V;++i) {
            delete[] Adj[i];
        }
        delete[] Adj;
    }

    void addEdge(int u,int v) {
        if(u>=0&&u<V&&v>=0&&v<V) {
            if(Adj[u][v]==0) {
                Adj[u][v]=1;
                Adj[v][u]=1;
                E++;
            }
        } else {
            cerr<<"Invalid edge: ("<<u<<", "<<v<<")"<<endl;
        }
    }

    void removeEdge(int u,int v) {
        if(u>=0&&u<V&&v>=0&&v<V) {
            if(Adj[u][v]==1) {
                Adj[u][v]=0;
                Adj[v][u]=0;
                E--;
            }
        } else {
            cerr<<"Invalid edge: ("<<u<<", "<<v<<")"<<endl;
        }
    }

    void getNeighbors(int u,int neighbors[],int& count) const {
        count=0;
        if(u>=0&&u<V) {
            for(int v=0;v<V;++v) {
                if(Adj[u][v]==1) {
                    neighbors[count++]=v;
                }
            }
        } else {
            cerr<<"Invalid vertex: "<<u<<endl;
        }
    }

    void displayGraph() const {
        cout<<"Graph adjacency list:\n";
        for(int i=0;i<V;++i) {
            cout<<"Vertex "<<i<<": ";
            for(int j=0;j<V;++j) {
                if(Adj[i][j]==1) {
                    cout<<j<<" ";
                }
            }
            cout<<endl;
        }
    }

    void display() const {
        cout<<"Adjacency Matrix:\n";
        for(int i=0;i<V;++i) {
            for(int j=0;j<V;++j) {
                cout<<Adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

Graph* createGraph() {
    int vertices,edges;

    cout<<"Enter number of vertices: ";
    cin>>vertices;

    cout<<"Enter number of edges: ";
    cin>>edges;

    if(vertices<=0||edges<0) {
        cerr<<"Invalid number of vertices or edges."<<endl;
        return nullptr;
    }

    Graph* G=new Graph(vertices,edges);
    
    cout<<"Enter vertex pairs that connect an edge :\n";
    
    for(int i=0;i<edges;++i) {
        int u,v;
        cin>>u>>v;
        G->addEdge(u,v);
    }

    return G;
}

int main() {
    Graph* graph=createGraph();
    
    if(graph) {
        graph->display();
        
        cout<<"\nDisplaying graph as adjacency list:\n";
        graph->displayGraph();

        int vertexToCheck=1;
        int neighbors[10];
        int neighborCount=0;

        graph->getNeighbors(vertexToCheck,neighbors,neighborCount);
        
        cout<<"\nNeighbors of vertex "<<vertexToCheck<<": ";
        
        for(int i=0;i<neighborCount;++i) {
            cout<<neighbors[i]<<" ";
        }
        
        cout<<endl;

        graph->removeEdge(1,2);
        
        cout<<"\nAfter removing edge (1,2):\n";
        graph->display();

        delete graph;
    } else {
        cerr<<"Failed to create graph."<<endl;
    }

    return 0;
}
